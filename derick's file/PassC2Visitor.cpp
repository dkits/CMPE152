/*
 * PassC2Visitor.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: deric
 */

#include <iostream>
#include <string>

#include "PassC2Visitor.h"
#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"
#include "wci/intermediate/symtabimpl/Predefined.h"

using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;

PassC2Visitor::PassC2Visitor(ostream& j_file)
    : program_name(""), j_file(j_file)
{
}

PassC2Visitor::~PassC2Visitor() {}

antlrcpp::Any PassC2Visitor::visitProg(SimpleCParser::ProgContext *ctx)
{
    auto value = visitChildren(ctx);
    //j_file.close();
    return value;
}
antlrcpp::Any PassC2Visitor::visitBlock(SimpleCParser::BlockContext *ctx){
    // Emit the main program header.
    j_file << endl;
    j_file << ".method public static main([Ljava/lang/String;)V" << endl;
    j_file << endl;
    j_file << "\tnew RunTimer" << endl;
    j_file << "\tdup" << endl;
    j_file << "\tinvokenonvirtual RunTimer/<init>()V" << endl;
    j_file << "\tputstatic        " << program_name
           << "/_runTimer LRunTimer;" << endl;
    j_file << "\tnew PascalTextIn" << endl;
    j_file << "\tdup" << endl;
    j_file << "\tinvokenonvirtual PascalTextIn/<init>()V" << endl;
    j_file << "\tputstatic        " + program_name
           << "/_standardIn LPascalTextIn;" << endl;

    auto value = visitChildren(ctx);

    // Emit the main program epilogue.
    j_file << endl;
    j_file << "\tgetstatic     " << program_name
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


antlrcpp::Any PassC2Visitor::visitStatID(SimpleCParser::StatIDContext *ctx){
    auto value = visit(ctx->expr());

    string type_indicator =
                  (ctx->expr()->type == Predefined::integer_type) ? "I"
                : (ctx->expr()->type == Predefined::boolean_type) ? "B"
                :                                                   "?";

    // Emit a field put instruction.
    j_file << "\tputstatic\t" << program_name
           << "/" << ctx->funcID()->ID()->toString()
           << " " << type_indicator << endl;

    return value;
}

antlrcpp::Any PassC2Visitor::visitStatID_equals(SimpleCParser::StatID_equalsContext *ctx){
    auto value = visit(ctx->expr());

    string type_indicator =
                  (ctx->expr()->type == Predefined::integer_type) ? "I"
                : (ctx->expr()->type == Predefined::real_type)    ? "F"
                :                                                   "?";

    // Emit a field put instruction.
    j_file << "\tputstatic\t" << program_name
           << "/" << ctx->funcID()->ID()->toString()
           << " " << type_indicator << endl;

    return value;
}
//
//
antlrcpp::Any PassC2Visitor::visitExprMultDiv(SimpleCParser::ExprMultDivContext *ctx){
	auto value = visitChildren(ctx);

	    TypeSpec *type1 = ctx->expr(0)->type;
	    TypeSpec *type2 = ctx->expr(1)->type;

	    bool integer_mode =    (type1 == Predefined::integer_type)
	                        && (type2 == Predefined::integer_type);
	    bool real_mode    =    (type1 == Predefined::real_type)
	                        && (type2 == Predefined::real_type);

	    string op = ctx->mulDivOp()->getText();
	    string opcode;

	    if (op == "*")
	    {
	        opcode = integer_mode ? "imul"
	               : real_mode    ? "fmul"
	               :                "????";
	    }
	    else
	    {
	        opcode = integer_mode ? "idpv"
	               : real_mode    ? "fdiv"
	               :                "????";
	    }

	    // Emit a multiply or divide instruction.
	    j_file << "\t" << opcode << endl;

	    return value;
}

antlrcpp::Any PassC2Visitor::visitExprAddSub(SimpleCParser::ExprAddSubContext *ctx){
    auto value = visitChildren(ctx);

    TypeSpec *type1 = ctx->expr(0)->type;
    TypeSpec *type2 = ctx->expr(1)->type;

    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);
    bool real_mode    =    (type1 == Predefined::real_type)
                        && (type2 == Predefined::real_type);

    string op = ctx->addSubOp()->getText();
    string opcode;

    if (op == "+")
    {
        opcode = integer_mode ? "iadd"
               : real_mode    ? "fadd"
               :                "????";
    }
    else
    {
        opcode = integer_mode ? "isub"
               : real_mode    ? "fsub"
               :                "????";
    }

    // Emit an add or subtract instruction.
    j_file << "\t" << opcode << endl;

    return value;
}
antlrcpp::Any PassC2Visitor::visitExprFuncID(SimpleCParser::ExprFuncIDContext *ctx){
    string variable_name = ctx->funcID()->ID()->toString();
    TypeSpec *type = ctx->type;

    string type_indicator = (type == Predefined::integer_type) ? "I"
                          : (type == Predefined::real_type)    ? "F"
                          :                                      "?";

    // Emit a field get instruction.
    j_file << "\tgetstatic\t" << program_name
           << "/" << variable_name << " " << type_indicator << endl;

    return visitChildren(ctx);
}

antlrcpp::Any PassC2Visitor::visitIntegerConst(SimpleCParser::IntegerConstContext *ctx)
{
    // Emit a load constant instruction.
    j_file << "\tldc\t" << ctx->getText() << endl;

    return visitChildren(ctx);
}

antlrcpp::Any PassC2Visitor::visitBoolConst(SimpleCParser::BoolConstContext  *ctx)
{
    // Emit a load constant instruction.
    j_file << "\tldc\t" << ctx->getText() << endl;

    return visitChildren(ctx);
}
