
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

antlrcpp::Any PassC1Visitor::visitHeader(SimpleCParser::HeaderContext *ctx){
	//    cout << "=== visitHeader: " + ctx->getText() << endl;

	    string program_name = ctx->MAIN()->toString();

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


antlrcpp::Any PassC1Visitor::visitBlock(SimpleCParser::BlockContext *ctx)
{
    // Emit the main program header.
    j_file << endl;
    j_file << ".method public static main([Ljava/lang/String;)V" << endl;
    j_file << endl;
    j_file << "\tnew RunTimer" << endl;
    j_file << "\tdup" << endl;
    j_file << "\tinvokenonvirtual RunTimer/<init>()V" << endl;
    j_file << "\tputstatic        " << program_id
           << "/_runTimer LRunTimer;" << endl;
    j_file << "\tnew PascalTextIn" << endl;
    j_file << "\tdup" << endl;
    j_file << "\tinvokenonvirtual PascalTextIn/<init>()V" << endl;
   // j_file << "\tputstatic        " + program_id
      //     << "/_standardIn LPascalTextIn;" << endl;

    auto value = visitChildren(ctx);

    // Emit the main program epilogue.
    j_file << endl;
    j_file << "\tgetstatic     " << program_id
               << "/_runTimer LRunTimer;" << endl;
    j_file << "\tinvokevirtual RunTimer.printElapsedTime()V" << endl;
    j_file << endl;
    j_file << "\treturn" << endl;
    j_file << endl;
    j_file << ".limit locals 16" << endl;
    j_file << ".limit stack 16" << endl;
    j_file << ".end method" << endl;

    return value;
}
/*
antlrcpp::Any PassC1Visitor::visitFuncInt(SimpleCParser::FuncIntContext *ctx)
{
	//Prints INT
    // Emit a load constant instruction.
   // j_file << "\tldc\t" << ctx->getText() << endl;

	 j_file << "\tldc\t" << ctx->getText() << endl;
    return visitChildren(ctx);
}
antlrcpp::Any PassC1Visitor::visitFuncBool(SimpleCParser::FuncBoolContext *ctx)
{
	//Prints BOOL
	 // Emit a load constant instruction.
	 //   j_file << "\tldc\t" << ctx->getText() << endl;

	 j_file << "\tldc\t" << ctx->getText() << endl;
	 return visitChildren(ctx);
}



antlrcpp::Any PassC1Visitor::visitFuncVoid(SimpleCParser::FuncVoidContext *ctx)
{
	//Prints VOID
	 // Emit a load constant instruction.
	 j_file << "\tldc\t" << ctx->getText() << endl;
	    return visitChildren(ctx);
}*/


antlrcpp::Any PassC1Visitor::visitStatIf(SimpleCParser::StatIfContext *ctx)
{

	 // Emit a load constant instruction.

	 j_file << "\n; " << ctx->getText() << "\n" << endl;
	 j_file << "\tldc\t" << ctx->getText() << endl;
	    return visitChildren(ctx);
}

antlrcpp::Any PassC1Visitor::visitStatWhile(SimpleCParser::StatWhileContext *ctx)
{

	 // Emit a load constant instruction.
	 j_file << "\tldc\t" << ctx->getText() << endl;
	 j_file << "\n; " << ctx->getText() << "\n" << endl;
	    return visitChildren(ctx);
}

antlrcpp::Any PassC1Visitor::visitStatFunc(SimpleCParser::StatFuncContext *ctx)
{

    j_file << "\n; " << ctx->getText() << "\n" << endl;
	 // Emit a load constant instruction.
	 j_file << "\tldc\t" << ctx->getText() << endl;
	    return visitChildren(ctx);
}

antlrcpp::Any PassC1Visitor::visitStatID(SimpleCParser::StatIDContext *ctx)
{

	 // Emit a load constant instruction.

	 //j_file << "\n; " << ctx->getText() << "\n" << endl;
	j_file << "\tldc\t" << ctx->getText() << endl;
	    return visitChildren(ctx);
}

antlrcpp::Any PassC1Visitor::visitStatVar(SimpleCParser::StatVarContext *ctx)
{

	 // Emit a load constant instruction.
	 //  j_file << "\n; " << ctx->getText() << "\n" << endl;

	 j_file << "\n; " << ctx->getText() << "\n" << endl;
	 j_file << "\tldc\t" << ctx->getText() << endl;
	    return visitChildren(ctx);
}


antlrcpp::Any PassC1Visitor::visitStatID_equals(SimpleCParser::StatID_equalsContext *ctx)
{

	// Emit a load constant instruction.

	 j_file << "\tldc\t" << ctx->getText() << endl;

	   // j_file << "\n; " << ctx->getText() << "\n" << endl;


	    return visitChildren(ctx);
}


antlrcpp::Any PassC1Visitor::visitStatCall(SimpleCParser::StatCallContext *ctx)
{

	 // Emit a load constant instruction.
    j_file << "\n; " << ctx->getText() << "\n" << endl;
	 j_file << "\tldc\t" << ctx->getText() << endl;

	    return visitChildren(ctx);
}

antlrcpp::Any PassC1Visitor::visitStatExpr(SimpleCParser::StatExprContext *ctx)
{

	 // Emit a load constant instruction.
	   // j_file << "\tldc\t" << ctx->getText() << endl;
    j_file << "\n; " << ctx->getText() << "\n" << endl;

	 j_file << "\tldc\t" << ctx->getText() << endl;
	    return visitChildren(ctx);
}
/*
antlrcpp::Any PassC1Visitor::visitStatRet(SimpleCParser::StatRetContext *ctx)
{

	 // Emit a load constant instruction.
	    j_file << "\tldc\t" << ctx->getText() << endl;
	    j_file << "\n; " << ctx->getText() << "\n" << endl;
	    return visitChildren(ctx);
}

antlrcpp::Any PassC1Visitor::visitVarInt(SimpleCParser::VarIntContext *ctx)
{

	 // Emit a load constant instruction.
	   // j_file << "\tldc\t" << ctx->getText() << endl;

	 j_file << "VARINT" << ctx->getText() << endl;
	    return visitChildren(ctx);


}


antlrcpp::Any PassC1Visitor::visitVarBool(SimpleCParser::VarBoolContext *ctx)
{

	 // Emit a load constant instruction.

	 j_file << "VARBOOL" << ctx->getText() << endl;
	    return visitChildren(ctx);
}

antlrcpp::Any PassC1Visitor::visitExprMultDiv(SimpleCParser::ExprMultDivContext *ctx)
{

	 // Emit a load constant instruction.

	 j_file << "ExprMultDi" << ctx->getText() << endl;
	    return visitChildren(ctx);
}


antlrcpp::Any PassC1Visitor::visitExprAddSub(SimpleCParser::ExprAddSubContext *ctx)
{

	 // Emit a load constant instruction.

	 j_file << "ExprAddSub" << ctx->getText() << endl;
	    return visitChildren(ctx);
}
antlrcpp::Any PassC1Visitor::visitExprComp(SimpleCParser::ExprCompContext *ctx)
{

	 // Emit a load constant instruction.

	 j_file << "ExprComp" << ctx->getText() << endl;
	    return visitChildren(ctx);
}

antlrcpp::Any PassC1Visitor::visitExprFuncInt(SimpleCParser::ExprFuncIntContext *ctx)
{

	 // Emit a load constant instruction.

	 j_file << "ExprFuncInt" << ctx->getText() << endl;
	    return visitChildren(ctx);
}

antlrcpp::Any PassC1Visitor::visitExprFuncID(SimpleCParser::ExprFuncIDContext *ctx)
{

	 // Emit a load constant instruction.

	 j_file << "ExprFuncID" << ctx->getText() << endl;
	    return visitChildren(ctx);
}
antlrcpp::Any PassC1Visitor::visitExprFuncBool(SimpleCParser::ExprFuncBoolContext *ctx)
{

	 // Emit a load constant instruction.

	 j_file << "tExprFuncBool" << ctx->getText() << endl;
	    return visitChildren(ctx);
}

antlrcpp::Any PassC1Visitor::visitExprPara(SimpleCParser::ExprParaContext *ctx)
{

	 // Emit a load constant instruction.

	 j_file << "ExprPara" << ctx->getText() << endl;
	    return visitChildren(ctx);
}

*/

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
