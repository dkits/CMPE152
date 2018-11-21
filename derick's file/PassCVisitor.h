/*
 * PassCVisitor.h
 *
 *  Created on: Nov 20, 2018
 *      Author: deric
 */

#ifndef PASSCVISITOR_H_
#define PASSCVISITOR_H_

#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"

#include "SimpleCBaseVisitor.h"
#include "antlr4-runtime.h"
#include "SimpleCVisitor.h"

using namespace wci;
using namespace wci::intermediate;

class PassCVisitor : public SimpleCBaseVisitor
{
private:
    SymTabStack *symtab_stack;
    SymTabEntry *program_id;
    vector<SymTabEntry *> variable_id_list;
    ofstream j_file;

public:
    PassCVisitor();
    virtual ~PassCVisitor();

    ostream& get_assembly_file();

    antlrcpp::Any visitProg(SimpleCParser::ProgContext *context) override;
    antlrcpp::Any visitStat(SimpleCParser::StatContext *context)  override;
    antlrcpp::Any visitIf_stat(SimpleCParser::If_statContext *context)  override;
    antlrcpp::Any visitWhile_stat(SimpleCParser::While_statContext *context)  override;
    antlrcpp::Any visitFunction(SimpleCParser::FunctionContext *context)  override;
    antlrcpp::Any visitFunc_call(SimpleCParser::Func_callContext *context)  override;
    antlrcpp::Any visitExpr(SimpleCParser::ExprContext *context)  override;
 	antlrcpp::Any visitVar_dec(SimpleCParser::Var_decContext *context)  override;
 	antlrcpp::Any visitFunc_synt(SimpleCParser::Func_syntContext *context)  override;

};



#endif /* PASSCVISITOR_H_ */
