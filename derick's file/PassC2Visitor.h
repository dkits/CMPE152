/*
 * PassC2Visitor.h
 *
 *  Created on: Nov 27, 2018
 *      Author: deric
 */

#ifndef PASSC2VISITOR_H_
#define PASSC2VISITOR_H_


#include <iostream>
#include <string>

#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"

#include "SimpleCBaseVisitor.h"
#include "antlr4-runtime.h"
#include "PassC2Visitor.h"

using namespace wci;
using namespace wci::intermediate;

class PassC2Visitor : public SimpleCBaseVisitor
{
private:
	string program_name;
	ostream& j_file;

public:
	PassC2Visitor(ostream& j_file);
    virtual ~PassC2Visitor();

    antlrcpp::Any visitProg(SimpleCParser::ProgContext *ctx) override;
    antlrcpp::Any visitBlock(SimpleCParser::BlockContext *ctx) override;
    antlrcpp::Any visitStat(SimpleCParser::StatContext *ctx) override;
    antlrcpp::Any visitHeader(SimpleCParser::HeaderContext *ctx) override;


    antlrcpp::Any visitAssignment_stat(SimpleCParser::Assignment_statContext *ctx) override;
	antlrcpp::Any visitIf_stat(SimpleCParser::If_statContext *ctx) override;

	antlrcpp::Any visitExprVari(SimpleCParser::ExprVariContext *ctx) override;
	antlrcpp::Any visitExprAddSub(SimpleCParser::ExprAddSubContext *ctx) override;
	antlrcpp::Any visitExprMultDiv(SimpleCParser::ExprMultDivContext *ctx) override;
	antlrcpp::Any visitExprComp(SimpleCParser::ExprCompContext *ctx) override;

	antlrcpp::Any visitIntegerConst(SimpleCParser::IntegerConstContext *ctx);
	antlrcpp::Any visitBoolConst(SimpleCParser::BoolConstContext *ctx) override;
    antlrcpp::Any visitFloatConst(SimpleCParser::FloatConstContext *ctx) override;



};


#endif /* PASSC2VISITOR_H_ */
