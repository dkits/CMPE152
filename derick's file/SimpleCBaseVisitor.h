
#include "wci/intermediate/TypeSpec.h"

using namespace wci::intermediate;


// Generated from SimpleC.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SimpleCVisitor.h"


/**
 * This class provides an empty implementation of SimpleCVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SimpleCBaseVisitor : public SimpleCVisitor {
public:

  virtual antlrcpp::Any visitProg(SimpleCParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHeader(SimpleCParser::HeaderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(SimpleCParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStat(SimpleCParser::StatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_table(SimpleCParser::Var_tableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_dec(SimpleCParser::Var_decContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarList(SimpleCParser::VarListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarID(SimpleCParser::VarIDContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarOP(SimpleCParser::VarOPContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVoidOP(SimpleCParser::VoidOPContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment_stat(SimpleCParser::Assignment_statContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrint(SimpleCParser::PrintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_stat(SimpleCParser::If_statContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhile_stat(SimpleCParser::While_statContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction(SimpleCParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunc_call(SimpleCParser::Func_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunc_re(SimpleCParser::Func_reContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprInt(SimpleCParser::ExprIntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprMultDiv(SimpleCParser::ExprMultDivContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprComp(SimpleCParser::ExprCompContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprAddSub(SimpleCParser::ExprAddSubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprVari(SimpleCParser::ExprVariContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprBool(SimpleCParser::ExprBoolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprPara(SimpleCParser::ExprParaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVari(SimpleCParser::VariContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitString(SimpleCParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompOP(SimpleCParser::CompOPContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulDivOp(SimpleCParser::MulDivOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddSubOp(SimpleCParser::AddSubOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntegerConst(SimpleCParser::IntegerConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFloatConst(SimpleCParser::FloatConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolConst(SimpleCParser::BoolConstContext *ctx) override {
    return visitChildren(ctx);
  }


};

