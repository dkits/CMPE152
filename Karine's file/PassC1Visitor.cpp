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

antlrcpp::Any PassC1Visitor::visitProg(SimpleCParser::ProgContext *ctx)
{
auto value = visitChildren(ctx);

//    cout << "=== visitProgram: Printing xref table." << endl;

    // Print the cross-reference table.
    CrossReferencer cross_referencer;
    cross_referencer.print(symtab_stack);

    return value;
}

antlrcpp::Any PassC1Visitor::visitStatExpr(SimpleCParser::StatExprContext *ctx){
	//    cout << "=== visitHeader: " + ctx->getText() << endl;

	    string program_name = ctx->expr()->toString();

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

antlrcpp::Any PassC1Visitor::visitFuncInt(SimpleCParser::FuncIntContext *ctx)
{
	//Prints INT
    // Emit a load constant instruction.
    j_file << "\tldc\t" << ctx->getText() << endl;

    return visitChildren(ctx);
}
antlrcpp::Any PassC1Visitor::visitFuncBool(SimpleCParser::FuncBoolContext *ctx)
{
	//Prints BOOL
	 // Emit a load constant instruction.
	    j_file << "\tldc\t" << ctx->getText() << endl;

	    return visitChildren(ctx);
}



antlrcpp::Any PassC1Visitor::visitFuncVoid(SimpleCParser::FuncVoidContext *ctx)
{
	//Prints VOID
	 // Emit a load constant instruction.
	    j_file << "\tldc\t" << ctx->getText() << endl;

	    return visitChildren(ctx);
}


antlrcpp::Any PassC1Visitor::visitStatIf(SimpleCParser::StatIfContext *ctx)
{
	//Prints VOID
	 // Emit a load constant instruction.
	    j_file << "\tldc\t" << ctx->getText() << endl;

	    return visitChildren(ctx);
}

antlrcpp::Any PassC1Visitor::visitStatWhile(SimpleCParser::StatWhileContext *ctx)
{
	//Prints VOID
	 // Emit a load constant instruction.
	    j_file << "\tldc\t" << ctx->getText() << endl;

	    return visitChildren(ctx);
}

antlrcpp::Any PassC1Visitor::visitStatFunc(SimpleCParser::StatFuncContext *ctx)
{
	//Prints VOID
	 // Emit a load constant instruction.
	    j_file << "\tldc\t" << ctx->getText() << endl;

	    return visitChildren(ctx);
}

antlrcpp::Any PassC1Visitor::visitStatID(SimpleCParser::StatIDContext *ctx)
{
	//Prints VOID
	 // Emit a load constant instruction.
	    j_file << "\tldc\t" << ctx->getText() << endl;

	    return visitChildren(ctx);
}

antlrcpp::Any PassC1Visitor::visitStatVar(SimpleCParser::StatVarContext *ctx)
{
	//Prints VOID
	 // Emit a load constant instruction.
	    j_file << "\tldc\t" << ctx->getText() << endl;

	    return visitChildren(ctx);
}

/* THIS PRINTS A LOT
antlrcpp::Any PassC1Visitor::visitExprFuncID(SimpleCParser::ExprFuncIDContext *ctx)
{
	//Prints VOID
	 // Emit a load constant instruction.
	    j_file << "\tldc\t" << ctx->getText() << endl;

	    return visitChildren(ctx);
}

*/
//need StatExpr here


//antlrcpp::Any PassC1Visitor::visitStatID(SimpleCParser::StatIDContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitStatID_equals(SimpleCParser::StatID_equalsContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitStatVar(SimpleCParser::StatVarContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitStatIf(SimpleCParser::StatIfContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitStatWhile(SimpleCParser::StatWhileContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitStatFunc(SimpleCParser::StatFuncContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitStatCall(SimpleCParser::StatCallContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitStatRet(SimpleCParser::StatRetContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitVarInt(SimpleCParser::VarIntContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitVarBool(SimpleCParser::VarBoolContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitIf_stat(SimpleCParser::If_statContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitWhile_stat(SimpleCParser::While_statContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitFunction(SimpleCParser::FunctionContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitFunc_call(SimpleCParser::Func_callContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitExprMultDiv(SimpleCParser::ExprMultDivContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitExprFuncInt(SimpleCParser::ExprFuncIntContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitExprComp(SimpleCParser::ExprCompContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitExprAddSub(SimpleCParser::ExprAddSubContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitExprPara(SimpleCParser::ExprParaContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitExprFuncID(SimpleCParser::ExprFuncIDContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitExprFuncBool(SimpleCParser::ExprFuncBoolContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitFuncVoid(SimpleCParser::FuncVoidContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitFuncInt(SimpleCParser::FuncIntContext *ctx){}
//antlrcpp::Any PassC1Visitor::visitFuncBool(SimpleCParser::FuncBoolContext *ctx){}
