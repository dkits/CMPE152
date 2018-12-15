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

    antlrcpp::Any visitProg(SimpleCParser::ProgContext *ctx) override;
    antlrcpp::Any visitHeader(SimpleCParser::HeaderContext *ctx) override;

 	antlrcpp::Any visitVar_table(SimpleCParser::Var_tableContext *ctx) override;
 	antlrcpp::Any visitVar_dec(SimpleCParser::Var_decContext *ctx) override;
    antlrcpp::Any visitVarList(SimpleCParser::VarListContext *ctx) override;
    antlrcpp::Any visitVarID(SimpleCParser::VarIDContext *ctx) override;
 	antlrcpp::Any visitVarOP(SimpleCParser::VarOPContext *ctx) override;


	antlrcpp::Any visitExprVari(SimpleCParser::ExprVariContext *ctx) override;
	antlrcpp::Any visitExprMultDiv(SimpleCParser::ExprMultDivContext *ctx) override;
	antlrcpp::Any visitExprAddSub(SimpleCParser::ExprAddSubContext *ctx) override;
	antlrcpp::Any visitExprComp(SimpleCParser::ExprCompContext *ctx) override;

 	antlrcpp::Any visitPrint(SimpleCParser::PrintContext *ctx) override;
	antlrcpp::Any visitString(SimpleCParser::StringContext *ctx) override;

	antlrcpp::Any visitExprInt(SimpleCParser::ExprIntContext *ctx) override;
	antlrcpp::Any visitExprBool(SimpleCParser::ExprBoolContext *ctx) override;
	antlrcpp::Any visitExprPara(SimpleCParser::ExprParaContext *ctx) override;
	antlrcpp::Any visitIntegerConst(SimpleCParser::IntegerConstContext *ctx) override;
	antlrcpp::Any visitBoolConst(SimpleCParser::BoolConstContext *ctx) override;
    antlrcpp::Any visitFloatConst(SimpleCParser::FloatConstContext *ctx) override;



	//	antlrcpp::Any visitWhile_stat(SimpleCParser::While_statContext *ctx) override;
	//	antlrcpp::Any visitFunction(SimpleCParser::FunctionContext *ctx) override;
	//	antlrcpp::Any visitFunc_call(SimpleCParser::Func_callContext *ctx) override;


	//	antlrcpp::Any visitVarInt(SimpleCParser::VarIntContext *ctx) override;
	//	antlrcpp::Any visitVarBool(SimpleCParser::VarBoolContext *ctx) override;

};




#endif /* PASSC1VISITOR_H_ */
