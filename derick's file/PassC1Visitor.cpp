/*
 * PassC1Visitor.cpp
 *
 *  Created on: Nov 20, 2018
 *  author: deric
 */
#include <iostream>
#include <string>
#include <vector>

#include "PassC1Visitor.h"
#include "wci/intermediate/SymTabFactory.h"
#include "wci/intermediate/symtabimpl/Predefined.h"
#include "wci/util/CrossReferencer.h"

using namespace std;
using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::util;

PassC1Visitor::PassC1Visitor()
    : program_id(nullptr), j_file(nullptr)
{
    // Create and initialize the symbol table stack.
    symtab_stack = SymTabFactory::create_symtab_stack();
    Predefined::initialize(symtab_stack);

    //cout << "=== Pass1Visitor(): symtab stack initialized." << endl;
}


PassC1Visitor::~PassC1Visitor() {}

ostream& PassC1Visitor::get_assembly_file() { return j_file; }

antlrcpp::Any PassC1Visitor::visitProg(SimpleCParser::ProgContext *ctx){
	auto value = visitChildren(ctx);

	//    cout << "=== visitProgram: Printing xref table." << endl;

	    // Print the cross-reference table.
	    CrossReferencer cross_referencer;
	    cross_referencer.print(symtab_stack);

	    return value;
}
antlrcpp::Any PassC1Visitor::visitHeader(SimpleCParser::HeaderContext *ctx){

    cout << "=== visitHeader: " + ctx->getText() << endl;

    string program_name = ctx->BIGMAIN()->toString();

    program_id = symtab_stack->enter_local(program_name);
    program_id->set_definition((Definition)DF_PROGRAM);
    program_id->set_attribute((SymTabKey) ROUTINE_SYMTAB,
                              symtab_stack->push());
    symtab_stack->set_program_id(program_id);

    // Create the assembly output file.
    j_file.open(program_name + ".j");
    if (j_file.fail())
    {
            cout << "***** Cannot open assembly file." << endl;
            exit(-99);
    }

    // Emit the program header.
    j_file << ".class public " << program_name << endl;
    j_file << ".super java/lang/Object" << endl;

    // Emit the RunTimer and PascalTextIn fields.
    j_file << endl;
    j_file << ".field private static _runTimer LRunTimer;" << endl;
    j_file << ".field private static _standardIn LPascalTextIn;" << endl;

    return visitChildren(ctx);
}


antlrcpp::Any PassC1Visitor::visitVar_table(SimpleCParser::Var_tableContext *ctx){
//	    cout << "=== visitDeclarations: " << ctx->getText() << endl;

	    auto value = visitChildren(ctx);

	    // Emit the class constructor.
	    j_file << endl;
	    j_file << ".method public <init>()V" << endl;
	    j_file << endl;
	    j_file << "\taload_0" << endl;
	    j_file << "\tinvokenonvirtual    java/lang/Object/<init>()V" << endl;
	    j_file << "\treturn" << endl;
	    j_file << endl;
	    j_file << ".limit locals 1" << endl;
	    j_file << ".limit stack 1" << endl;
	    j_file << ".end method" << endl;


	    return value;
}
antlrcpp::Any PassC1Visitor::visitVar_dec(SimpleCParser::Var_decContext *ctx){

	  j_file << "\n; " << ctx->getText() << "\n" << endl;
	  return visitChildren(ctx);
}
antlrcpp::Any PassC1Visitor::visitVarList(SimpleCParser::VarListContext *ctx)
{
//    cout << "=== visitVarList: " + ctx->getText() << endl;
    variable_id_list.resize(0);

    return visitChildren(ctx);
}
antlrcpp::Any PassC1Visitor::visitVarID(SimpleCParser::VarIDContext *ctx)
{
//    cout << "=== visitVarId: " + ctx->getText() << endl;

    string variable_name = ctx->ID()->toString();
    SymTabEntry *variable_id = symtab_stack->enter_local(variable_name);
    variable_id->set_definition((Definition) DF_VARIABLE);
    variable_id_list.push_back(variable_id);


    return visitChildren(ctx);
}
antlrcpp::Any PassC1Visitor::visitVarOP(SimpleCParser::VarOPContext *ctx){
//    cout << "=== visitTypeId: " + ctx->getText() << endl;
    TypeSpec *type;
    string type_indicator;

    string type_name = ctx->getText();
    if (type_name == "int")
    {
        type = Predefined::integer_type;
        type_indicator = "I";
    }
    else if (type_name == "bool")
    {
        type = Predefined::boolean_type;
        type_indicator = "B";
    }
    else if (type_name == "float")
    {
        type = Predefined::real_type;
        type_indicator = "F";
    }
    else
    {
        type = nullptr;
        type_indicator = "?";
    }

    for (SymTabEntry *id : variable_id_list) {
//        cout << " " << type_indicator << " ";

//    	cout << id->get_name() << type_indicator << " ";
        id->set_typespec(type);

        // Emit a field declaration
        j_file << ".field private static "
               << id->get_name() << " " << type_indicator << endl;
    }

    return visitChildren(ctx);
}


antlrcpp::Any PassC1Visitor::visitExprVari(SimpleCParser::ExprVariContext *ctx){
//	    cout << "=== visitVariableExpr: " + ctx->getText() << endl;

	    string variable_name = ctx->vari()->ID()->toString();
	    SymTabEntry *variable_id = symtab_stack->lookup(variable_name);

	    ctx->type = variable_id->get_typespec();
	    return visitChildren(ctx);
}



////antlrcpp::Any PassC1Visitor::visitWhile_stat(SimpleCParser::While_statContext *ctx){}
////antlrcpp::Any PassC1Visitor::visitFunction(SimpleCParser::FunctionContext *ctx){}
////antlrcpp::Any PassC1Visitor::visitFunc_call(SimpleCParser::Func_callContext *ctx){}
antlrcpp::Any PassC1Visitor::visitExprMultDiv(SimpleCParser::ExprMultDivContext *ctx){
	//    cout << "=== visitMulDivExpr: " + ctx->getText() << endl;

    auto value = visitChildren(ctx);

    TypeSpec *type1 = ctx->expr(0)->type;
    TypeSpec *type2 = ctx->expr(1)->type;

    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);
    bool real_mode    =    (type1 == Predefined::real_type)
                        && (type2 == Predefined::real_type);

    TypeSpec *type = integer_mode ? Predefined::integer_type
                   : real_mode    ? Predefined::real_type
                   :                nullptr;
    ctx->type = type;

    return value;
}


antlrcpp::Any PassC1Visitor::visitExprAddSub(SimpleCParser::ExprAddSubContext *ctx){
	//    cout << "=== visitAddSubExpr: " + ctx->getText() << endl;

    auto value = visitChildren(ctx);

    TypeSpec *type1 = ctx->expr(0)->type;
    TypeSpec *type2 = ctx->expr(1)->type;

    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);
    bool real_mode    =    (type1 == Predefined::real_type)
                        && (type2 == Predefined::real_type);

    TypeSpec *type = integer_mode ? Predefined::integer_type
                   : real_mode    ? Predefined::real_type
                   :                nullptr;
    ctx->type = type;

    return value;
}
antlrcpp::Any PassC1Visitor::visitExprComp(SimpleCParser::ExprCompContext *ctx){
    auto value = visitChildren(ctx);

    TypeSpec *type1 = ctx->expr(0)->type;
    TypeSpec *type2 = ctx->expr(1)->type;

    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);
    bool bool_mode    =    (type1 == Predefined::boolean_type)
                        && (type2 == Predefined::boolean_type);
    bool real_mode    =    (type1 == Predefined::real_type)
                        && (type2 == Predefined::real_type);

    TypeSpec *type = integer_mode ? Predefined::integer_type
                   : bool_mode    ? Predefined::boolean_type
                   : real_mode    ? Predefined::real_type
                   :                nullptr;
    ctx->type = type;

    return value;
}
antlrcpp::Any PassC1Visitor::visitExprInt(SimpleCParser::ExprIntContext *ctx){
	//    cout << "=== visitUnsignedNumberExpr: " + ctx->getText() << endl;

	    auto value = visit(ctx->num());
	    ctx->type = ctx->num()->type;
	    return value;

}

antlrcpp::Any PassC1Visitor::visitExprPara(SimpleCParser::ExprParaContext *ctx){
	//    cout << "=== visitParenExpr: " + ctx->getText() << endl;
		auto value = visitChildren(ctx);
	    ctx->type = ctx->expr()->type;
	    return value;
}
//
antlrcpp::Any PassC1Visitor::visitExprBool(SimpleCParser::ExprBoolContext *ctx){
		auto value = visit(ctx->booln());
		ctx->type = ctx->booln()->type;
		return value;
}

antlrcpp::Any PassC1Visitor::visitIntegerConst(SimpleCParser::IntegerConstContext *ctx)
{
//    cout << "=== visitIntegerConst: " + ctx->getText() << endl;

    ctx->type = Predefined::integer_type;
    return visitChildren(ctx);
}

antlrcpp::Any PassC1Visitor::visitBoolConst(SimpleCParser::BoolConstContext *ctx)
{
//    cout << "=== visitFloatConst: " + ctx->getText() << endl;

    ctx->type = Predefined::boolean_type;
    return visitChildren(ctx);
}
antlrcpp::Any PassC1Visitor::visitFloatConst(SimpleCParser::FloatConstContext *ctx){
//    cout << "=== visitFloatConst: " + ctx->getText() << endl;

    ctx->type = Predefined::real_type;
    return visitChildren(ctx);
}
antlrcpp::Any PassC1Visitor::visitPrint(SimpleCParser::PrintContext *ctx){

//	auto value = visitChildren(ctx);
//   // ctx->type = ctx->ID()->type;
//  //  j_file << "\tldc\t" << ctx->getText() << endl;
//
//	j_file << ".method public static main([Ljava/lang/String;)V" << endl;
//	j_file << " " << endl;
//	j_file<< "getstatic java/lang/System/out Ljava/io/PrintStream;" << endl;
////	   j_file << "ldc Hello"<< endl; // do not hard code this
//	j_file << "ldc " << ctx->string()->getText() << endl;
//	j_file << "invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V" << endl;
//
//	 j_file <<  " return "<< endl;
//	 j_file <<  ".limit locals 16 "<< endl;
//	 j_file << ".limit stack 16" << endl;
//	 j_file <<  ".end method" << endl;
	  return visitChildren(ctx);
}
antlrcpp::Any PassC1Visitor::visitString(SimpleCParser::StringContext *ctx){
	auto value = visitChildren(ctx);
   // ctx->type = ctx->ID()->type;
  //  j_file << "\tldc\t" << ctx->getText() << endl;

	j_file << ".method public static main([Ljava/lang/String;)V" << endl;
	j_file << " " << endl;
	j_file<< "getstatic java/lang/System/out Ljava/io/PrintStream;" << endl;
//	   j_file << "ldc Hello"<< endl; // do not hard code this
	j_file << "ldc " << ctx->getText() << endl;
	j_file << "invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V" << endl;

	 j_file <<  " return "<< endl;
	 j_file <<  ".limit locals 16 "<< endl;
	 j_file << ".limit stack 16" << endl;
	 j_file <<  ".end method" << endl;
	return visitChildren(ctx);
}

////antlrcpp::Any PassC1Visitor::visitFuncVoid(SimpleCParser::FuncVoidContext *ctx){}
////antlrcpp::Any PassC1Visitor::visitFuncInt(SimpleCParser::FuncIntContext *ctx){}
////antlrcpp::Any PassC1Visitor::visitFuncBool(SimpleCParser::FuncBoolContext *ctx){}
//
//
