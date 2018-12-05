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
    antlrcpp::Any visitStatID(SimpleCParser::StatIDContext *ctx) override;
    antlrcpp::Any visitStatID_equals(SimpleCParser::StatID_equalsContext *ctx) override;

	antlrcpp::Any visitExprFuncID(SimpleCParser::ExprFuncIDContext *ctx) override;

	antlrcpp::Any visitExprAddSub(SimpleCParser::ExprAddSubContext *ctx) override;
	antlrcpp::Any visitExprMultDiv(SimpleCParser::ExprMultDivContext *ctx) override;

	antlrcpp::Any visitIntegerConst(SimpleCParser::IntegerConstContext *ctx);
	antlrcpp::Any visitBoolConst(SimpleCParser::BoolConstContext *ctx) override;



};


#endif /* PASSC2VISITOR_H_ */
