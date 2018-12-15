
#include "wci/intermediate/TypeSpec.h"

using namespace wci::intermediate;


// Generated from SimpleC.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  SimpleCParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, MUL_OP = 18, DIV_OP = 19, ADD_OP = 20, 
    SUB_OP = 21, EQU_OP = 22, LEQ_OP = 23, GEQ_OP = 24, LES_OP = 25, GTR_OP = 26, 
    VARLIST = 27, BIGMAIN = 28, PRINT = 29, BOOL = 30, ID = 31, INT = 32, 
    FLOAT = 33, NEWLINE = 34, WS = 35
  };

  enum {
    RuleProg = 0, RuleHeader = 1, RuleBlock = 2, RuleStat = 3, RuleVar_table = 4, 
    RuleVar_dec = 5, RuleVarList = 6, RuleVarID = 7, RuleVarOP = 8, RuleVoidOP = 9, 
    RuleAssignment_stat = 10, RulePrint = 11, RuleIf_stat = 12, RuleWhile_stat = 13, 
    RuleFunction = 14, RuleFunc_call = 15, RuleFunc_re = 16, RuleExpr = 17, 
    RuleVari = 18, RuleString = 19, RuleCompOP = 20, RuleMulDivOp = 21, 
    RuleAddSubOp = 22, RuleNum = 23, RuleBooln = 24
  };

  SimpleCParser(antlr4::TokenStream *input);
  ~SimpleCParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgContext;
  class HeaderContext;
  class BlockContext;
  class StatContext;
  class Var_tableContext;
  class Var_decContext;
  class VarListContext;
  class VarIDContext;
  class VarOPContext;
  class VoidOPContext;
  class Assignment_statContext;
  class PrintContext;
  class If_statContext;
  class While_statContext;
  class FunctionContext;
  class Func_callContext;
  class Func_reContext;
  class ExprContext;
  class VariContext;
  class StringContext;
  class CompOPContext;
  class MulDivOpContext;
  class AddSubOpContext;
  class NumContext;
  class BoolnContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    HeaderContext *header();
    BlockContext *block();
    std::vector<FunctionContext *> function();
    FunctionContext* function(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgContext* prog();

  class  HeaderContext : public antlr4::ParserRuleContext {
  public:
    HeaderContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BIGMAIN();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  HeaderContext* header();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_tableContext *var_table();
    std::vector<StatContext *> stat();
    StatContext* stat(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  StatContext : public antlr4::ParserRuleContext {
  public:
    StatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Assignment_statContext *assignment_stat();
    If_statContext *if_stat();
    While_statContext *while_stat();
    FunctionContext *function();
    Func_callContext *func_call();
    PrintContext *print();
    Func_reContext *func_re();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatContext* stat();

  class  Var_tableContext : public antlr4::ParserRuleContext {
  public:
    Var_tableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VARLIST();
    std::vector<Var_decContext *> var_dec();
    Var_decContext* var_dec(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_tableContext* var_table();

  class  Var_decContext : public antlr4::ParserRuleContext {
  public:
    Var_decContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarListContext *varList();
    VarOPContext *varOP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_decContext* var_dec();

  class  VarListContext : public antlr4::ParserRuleContext {
  public:
    VarListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VarIDContext *> varID();
    VarIDContext* varID(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarListContext* varList();

  class  VarIDContext : public antlr4::ParserRuleContext {
  public:
    VarIDContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarIDContext* varID();

  class  VarOPContext : public antlr4::ParserRuleContext {
  public:
    VarOPContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarOPContext* varOP();

  class  VoidOPContext : public antlr4::ParserRuleContext {
  public:
    VoidOPContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VoidOPContext* voidOP();

  class  Assignment_statContext : public antlr4::ParserRuleContext {
  public:
    Assignment_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariContext *vari();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assignment_statContext* assignment_stat();

  class  PrintContext : public antlr4::ParserRuleContext {
  public:
    PrintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PRINT();
    StringContext *string();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrintContext* print();

  class  If_statContext : public antlr4::ParserRuleContext {
  public:
    If_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    If_statContext *if_stat();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_statContext* if_stat();

  class  While_statContext : public antlr4::ParserRuleContext {
  public:
    While_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    std::vector<StatContext *> stat();
    StatContext* stat(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  While_statContext* while_stat();

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    BlockContext *block();
    VarOPContext *varOP();
    VoidOPContext *voidOP();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionContext* function();

  class  Func_callContext : public antlr4::ParserRuleContext {
  public:
    Func_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_callContext* func_call();

  class  Func_reContext : public antlr4::ParserRuleContext {
  public:
    Func_reContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_reContext* func_re();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    TypeSpec * type = nullptr;
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExprIntContext : public ExprContext {
  public:
    ExprIntContext(ExprContext *ctx);

    NumContext *num();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprMultDivContext : public ExprContext {
  public:
    ExprMultDivContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    MulDivOpContext *mulDivOp();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprCompContext : public ExprContext {
  public:
    ExprCompContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    CompOPContext *compOP();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprAddSubContext : public ExprContext {
  public:
    ExprAddSubContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    AddSubOpContext *addSubOp();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprVariContext : public ExprContext {
  public:
    ExprVariContext(ExprContext *ctx);

    VariContext *vari();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprBoolContext : public ExprContext {
  public:
    ExprBoolContext(ExprContext *ctx);

    BoolnContext *booln();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprParaContext : public ExprContext {
  public:
    ExprParaContext(ExprContext *ctx);

    ExprContext *expr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  VariContext : public antlr4::ParserRuleContext {
  public:
    VariContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariContext* vari();

  class  StringContext : public antlr4::ParserRuleContext {
  public:
    StringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringContext* string();

  class  CompOPContext : public antlr4::ParserRuleContext {
  public:
    CompOPContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQU_OP();
    antlr4::tree::TerminalNode *LEQ_OP();
    antlr4::tree::TerminalNode *GEQ_OP();
    antlr4::tree::TerminalNode *LES_OP();
    antlr4::tree::TerminalNode *GTR_OP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompOPContext* compOP();

  class  MulDivOpContext : public antlr4::ParserRuleContext {
  public:
    MulDivOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MUL_OP();
    antlr4::tree::TerminalNode *DIV_OP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MulDivOpContext* mulDivOp();

  class  AddSubOpContext : public antlr4::ParserRuleContext {
  public:
    AddSubOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADD_OP();
    antlr4::tree::TerminalNode *SUB_OP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AddSubOpContext* addSubOp();

  class  NumContext : public antlr4::ParserRuleContext {
  public:
    TypeSpec * type = nullptr;
    NumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    NumContext() : antlr4::ParserRuleContext() { }
    void copyFrom(NumContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FloatConstContext : public NumContext {
  public:
    FloatConstContext(NumContext *ctx);

    antlr4::tree::TerminalNode *FLOAT();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntegerConstContext : public NumContext {
  public:
    IntegerConstContext(NumContext *ctx);

    antlr4::tree::TerminalNode *INT();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  NumContext* num();

  class  BoolnContext : public antlr4::ParserRuleContext {
  public:
    TypeSpec * type = nullptr;
    BoolnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    BoolnContext() : antlr4::ParserRuleContext() { }
    void copyFrom(BoolnContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BoolConstContext : public BoolnContext {
  public:
    BoolConstContext(BoolnContext *ctx);

    antlr4::tree::TerminalNode *BOOL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  BoolnContext* booln();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

