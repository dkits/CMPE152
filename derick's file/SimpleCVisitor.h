
#include "wci/intermediate/TypeSpec.h"

using namespace wci::intermediate;


// Generated from SimpleC.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SimpleCParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SimpleCParser.
 */
class  SimpleCVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SimpleCParser.
   */
    virtual antlrcpp::Any visitProg(SimpleCParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitHeader(SimpleCParser::HeaderContext *context) = 0;

    virtual antlrcpp::Any visitBlock(SimpleCParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitStat(SimpleCParser::StatContext *context) = 0;

    virtual antlrcpp::Any visitVar_table(SimpleCParser::Var_tableContext *context) = 0;

    virtual antlrcpp::Any visitVar_dec(SimpleCParser::Var_decContext *context) = 0;

    virtual antlrcpp::Any visitVarList(SimpleCParser::VarListContext *context) = 0;

    virtual antlrcpp::Any visitVarID(SimpleCParser::VarIDContext *context) = 0;

    virtual antlrcpp::Any visitVarOP(SimpleCParser::VarOPContext *context) = 0;

    virtual antlrcpp::Any visitVoidOP(SimpleCParser::VoidOPContext *context) = 0;

    virtual antlrcpp::Any visitAssignment_stat(SimpleCParser::Assignment_statContext *context) = 0;

    virtual antlrcpp::Any visitPrint(SimpleCParser::PrintContext *context) = 0;

    virtual antlrcpp::Any visitIf_stat(SimpleCParser::If_statContext *context) = 0;

    virtual antlrcpp::Any visitWhile_stat(SimpleCParser::While_statContext *context) = 0;

    virtual antlrcpp::Any visitFunction(SimpleCParser::FunctionContext *context) = 0;

    virtual antlrcpp::Any visitFunc_call(SimpleCParser::Func_callContext *context) = 0;

    virtual antlrcpp::Any visitFunc_re(SimpleCParser::Func_reContext *context) = 0;

    virtual antlrcpp::Any visitExprInt(SimpleCParser::ExprIntContext *context) = 0;

    virtual antlrcpp::Any visitExprMultDiv(SimpleCParser::ExprMultDivContext *context) = 0;

    virtual antlrcpp::Any visitExprComp(SimpleCParser::ExprCompContext *context) = 0;

    virtual antlrcpp::Any visitExprAddSub(SimpleCParser::ExprAddSubContext *context) = 0;

    virtual antlrcpp::Any visitExprVari(SimpleCParser::ExprVariContext *context) = 0;

    virtual antlrcpp::Any visitExprBool(SimpleCParser::ExprBoolContext *context) = 0;

    virtual antlrcpp::Any visitExprPara(SimpleCParser::ExprParaContext *context) = 0;

    virtual antlrcpp::Any visitVari(SimpleCParser::VariContext *context) = 0;

    virtual antlrcpp::Any visitString(SimpleCParser::StringContext *context) = 0;

    virtual antlrcpp::Any visitCompOP(SimpleCParser::CompOPContext *context) = 0;

    virtual antlrcpp::Any visitMulDivOp(SimpleCParser::MulDivOpContext *context) = 0;

    virtual antlrcpp::Any visitAddSubOp(SimpleCParser::AddSubOpContext *context) = 0;

    virtual antlrcpp::Any visitIntegerConst(SimpleCParser::IntegerConstContext *context) = 0;

    virtual antlrcpp::Any visitFloatConst(SimpleCParser::FloatConstContext *context) = 0;

    virtual antlrcpp::Any visitBoolConst(SimpleCParser::BoolConstContext *context) = 0;


};

