/*
 * PassC1Visitor.h
 *
 *  Created on: Nov 27, 2018
 *      Author: deric
 */

#ifndef PASSC1VISITOR_H_
#define PASSC1VISITOR_H_

#include <iostream>


#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"

#include "SimpleCBaseVisitor.h"
#include "antlr4-runtime.h"
#include "SimpleCVisitor.h"

using namespace wci;
using namespace wci::intermediate;

class PassC1Visitor : public SimpleCBaseVisitor
{
private:
    SymTabStack *symtab_stack;
    SymTabEntry *program_id;
    vector<SymTabEntry *> variable_id_list;
    ofstream j_file;


public:
    PassC1Visitor();
    virtual ~PassC1Visitor();

    ostream& get_assembly_file();
    antlrcpp::Any visitHeader(SimpleCParser::HeaderContext *ctx) override;
    antlrcpp::Any visitBlock(SimpleCParser::BlockContext *ctx) override;
    antlrcpp::Any visitProg(SimpleCParser::ProgContext *ctx) override;
   antlrcpp::Any visitStatExpr(SimpleCParser::StatExprContext *ctx) override;
  antlrcpp::Any visitStatID(SimpleCParser::StatIDContext *ctx) override;
	antlrcpp::Any visitStatID_equals(SimpleCParser::StatID_equalsContext *ctx) override;
	antlrcpp::Any visitStatVar(SimpleCParser::StatVarContext *ctx) override;
	antlrcpp::Any visitStatIf(SimpleCParser::StatIfContext *ctx) override;
	antlrcpp::Any visitStatWhile(SimpleCParser::StatWhileContext *ctx) override;
	antlrcpp::Any visitStatFunc(SimpleCParser::StatFuncContext *ctx) override;
	antlrcpp::Any visitStatCall(SimpleCParser::StatCallContext *ctx) override;
//	antlrcpp::Any visitStatRet(SimpleCParser::StatRetContext *ctx) override;
//	antlrcpp::Any visitVarInt(SimpleCParser::VarIntContext *ctx) override;
//	antlrcpp::Any visitVarBool(SimpleCParser::VarBoolContext *ctx) override;
//  antlrcpp::Any visitIf_stat(SimpleCParser::If_statContext *ctx) override;
//	antlrcpp::Any visitWhile_stat(SimpleCParser::While_statContext *ctx) override;
//	antlrcpp::Any visitFunction(SimpleCParser::FunctionContext *ctx) override;
//	antlrcpp::Any visitFunc_call(SimpleCParser::Func_callContext *ctx) override;
//	antlrcpp::Any visitExprMultDiv(SimpleCParser::ExprMultDivContext *ctx) override;
//	antlrcpp::Any visitExprFuncInt(SimpleCParser::ExprFuncIntContext *ctx) override;
//	antlrcpp::Any visitExprComp(SimpleCParser::ExprCompContext *ctx) override;
//	antlrcpp::Any visitExprAddSub(SimpleCParser::ExprAddSubContext *ctx) override;
//	antlrcpp::Any visitExprPara(SimpleCParser::ExprParaContext *ctx) override;
//	antlrcpp::Any visitExprFuncID(SimpleCParser::ExprFuncIDContext *ctx) override;	antlrcpp::Any visitExprFuncBool(SimpleCParser::ExprFuncBoolContext *ctx) override;
//	antlrcpp::Any visitFuncVoid(SimpleCParser::FuncVoidContext *ctx) override;
//	antlrcpp::Any visitFuncInt(SimpleCParser::FuncIntContext *ctx) override;
//	antlrcpp::Any visitFuncBool(SimpleCParser::FuncBoolContext *ctx) override;

};




#endif /* PASSC1VISITOR_H_ */
