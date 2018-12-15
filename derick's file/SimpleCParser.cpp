
#include "wci/intermediate/TypeSpec.h"

using namespace wci::intermediate;


// Generated from SimpleC.g4 by ANTLR 4.7.1


#include "SimpleCVisitor.h"

#include "SimpleCParser.h"


using namespace antlrcpp;
using namespace antlr4;

SimpleCParser::SimpleCParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SimpleCParser::~SimpleCParser() {
  delete _interpreter;
}

std::string SimpleCParser::getGrammarFileName() const {
  return "SimpleC.g4";
}

const std::vector<std::string>& SimpleCParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SimpleCParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

SimpleCParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::HeaderContext* SimpleCParser::ProgContext::header() {
  return getRuleContext<SimpleCParser::HeaderContext>(0);
}

SimpleCParser::BlockContext* SimpleCParser::ProgContext::block() {
  return getRuleContext<SimpleCParser::BlockContext>(0);
}

std::vector<SimpleCParser::FunctionContext *> SimpleCParser::ProgContext::function() {
  return getRuleContexts<SimpleCParser::FunctionContext>();
}

SimpleCParser::FunctionContext* SimpleCParser::ProgContext::function(size_t i) {
  return getRuleContext<SimpleCParser::FunctionContext>(i);
}


size_t SimpleCParser::ProgContext::getRuleIndex() const {
  return SimpleCParser::RuleProg;
}

antlrcpp::Any SimpleCParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::ProgContext* SimpleCParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, SimpleCParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(50);
    header();
    setState(51);
    block();
    setState(55);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimpleCParser::T__5)
      | (1ULL << SimpleCParser::T__6)
      | (1ULL << SimpleCParser::T__7)
      | (1ULL << SimpleCParser::T__8))) != 0)) {
      setState(52);
      function();
      setState(57);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HeaderContext ------------------------------------------------------------------

SimpleCParser::HeaderContext::HeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleCParser::HeaderContext::BIGMAIN() {
  return getToken(SimpleCParser::BIGMAIN, 0);
}


size_t SimpleCParser::HeaderContext::getRuleIndex() const {
  return SimpleCParser::RuleHeader;
}

antlrcpp::Any SimpleCParser::HeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitHeader(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::HeaderContext* SimpleCParser::header() {
  HeaderContext *_localctx = _tracker.createInstance<HeaderContext>(_ctx, getState());
  enterRule(_localctx, 2, SimpleCParser::RuleHeader);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    match(SimpleCParser::BIGMAIN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

SimpleCParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::Var_tableContext* SimpleCParser::BlockContext::var_table() {
  return getRuleContext<SimpleCParser::Var_tableContext>(0);
}

std::vector<SimpleCParser::StatContext *> SimpleCParser::BlockContext::stat() {
  return getRuleContexts<SimpleCParser::StatContext>();
}

SimpleCParser::StatContext* SimpleCParser::BlockContext::stat(size_t i) {
  return getRuleContext<SimpleCParser::StatContext>(i);
}


size_t SimpleCParser::BlockContext::getRuleIndex() const {
  return SimpleCParser::RuleBlock;
}

antlrcpp::Any SimpleCParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::BlockContext* SimpleCParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 4, SimpleCParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    match(SimpleCParser::T__0);
    setState(62);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SimpleCParser::VARLIST) {
      setState(61);
      var_table();
    }
    setState(67);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimpleCParser::T__5)
      | (1ULL << SimpleCParser::T__6)
      | (1ULL << SimpleCParser::T__7)
      | (1ULL << SimpleCParser::T__8)
      | (1ULL << SimpleCParser::T__12)
      | (1ULL << SimpleCParser::T__14)
      | (1ULL << SimpleCParser::T__15)
      | (1ULL << SimpleCParser::PRINT)
      | (1ULL << SimpleCParser::ID))) != 0)) {
      setState(64);
      stat();
      setState(69);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(70);
    match(SimpleCParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatContext ------------------------------------------------------------------

SimpleCParser::StatContext::StatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::Assignment_statContext* SimpleCParser::StatContext::assignment_stat() {
  return getRuleContext<SimpleCParser::Assignment_statContext>(0);
}

SimpleCParser::If_statContext* SimpleCParser::StatContext::if_stat() {
  return getRuleContext<SimpleCParser::If_statContext>(0);
}

SimpleCParser::While_statContext* SimpleCParser::StatContext::while_stat() {
  return getRuleContext<SimpleCParser::While_statContext>(0);
}

SimpleCParser::FunctionContext* SimpleCParser::StatContext::function() {
  return getRuleContext<SimpleCParser::FunctionContext>(0);
}

SimpleCParser::Func_callContext* SimpleCParser::StatContext::func_call() {
  return getRuleContext<SimpleCParser::Func_callContext>(0);
}

SimpleCParser::PrintContext* SimpleCParser::StatContext::print() {
  return getRuleContext<SimpleCParser::PrintContext>(0);
}

SimpleCParser::Func_reContext* SimpleCParser::StatContext::func_re() {
  return getRuleContext<SimpleCParser::Func_reContext>(0);
}


size_t SimpleCParser::StatContext::getRuleIndex() const {
  return SimpleCParser::RuleStat;
}

antlrcpp::Any SimpleCParser::StatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitStat(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::StatContext* SimpleCParser::stat() {
  StatContext *_localctx = _tracker.createInstance<StatContext>(_ctx, getState());
  enterRule(_localctx, 6, SimpleCParser::RuleStat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(79);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(72);
      assignment_stat();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(73);
      if_stat();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(74);
      while_stat();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(75);
      function();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(76);
      func_call();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(77);
      print();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(78);
      func_re();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_tableContext ------------------------------------------------------------------

SimpleCParser::Var_tableContext::Var_tableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleCParser::Var_tableContext::VARLIST() {
  return getToken(SimpleCParser::VARLIST, 0);
}

std::vector<SimpleCParser::Var_decContext *> SimpleCParser::Var_tableContext::var_dec() {
  return getRuleContexts<SimpleCParser::Var_decContext>();
}

SimpleCParser::Var_decContext* SimpleCParser::Var_tableContext::var_dec(size_t i) {
  return getRuleContext<SimpleCParser::Var_decContext>(i);
}


size_t SimpleCParser::Var_tableContext::getRuleIndex() const {
  return SimpleCParser::RuleVar_table;
}

antlrcpp::Any SimpleCParser::Var_tableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitVar_table(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::Var_tableContext* SimpleCParser::var_table() {
  Var_tableContext *_localctx = _tracker.createInstance<Var_tableContext>(_ctx, getState());
  enterRule(_localctx, 8, SimpleCParser::RuleVar_table);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(81);
    match(SimpleCParser::VARLIST);
    setState(82);
    match(SimpleCParser::T__0);
    setState(86);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleCParser::ID) {
      setState(83);
      var_dec();
      setState(88);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(89);
    match(SimpleCParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_decContext ------------------------------------------------------------------

SimpleCParser::Var_decContext::Var_decContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::VarListContext* SimpleCParser::Var_decContext::varList() {
  return getRuleContext<SimpleCParser::VarListContext>(0);
}

SimpleCParser::VarOPContext* SimpleCParser::Var_decContext::varOP() {
  return getRuleContext<SimpleCParser::VarOPContext>(0);
}


size_t SimpleCParser::Var_decContext::getRuleIndex() const {
  return SimpleCParser::RuleVar_dec;
}

antlrcpp::Any SimpleCParser::Var_decContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitVar_dec(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::Var_decContext* SimpleCParser::var_dec() {
  Var_decContext *_localctx = _tracker.createInstance<Var_decContext>(_ctx, getState());
  enterRule(_localctx, 10, SimpleCParser::RuleVar_dec);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91);
    varList();
    setState(92);
    match(SimpleCParser::T__2);
    setState(93);
    varOP();
    setState(94);
    match(SimpleCParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarListContext ------------------------------------------------------------------

SimpleCParser::VarListContext::VarListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimpleCParser::VarIDContext *> SimpleCParser::VarListContext::varID() {
  return getRuleContexts<SimpleCParser::VarIDContext>();
}

SimpleCParser::VarIDContext* SimpleCParser::VarListContext::varID(size_t i) {
  return getRuleContext<SimpleCParser::VarIDContext>(i);
}


size_t SimpleCParser::VarListContext::getRuleIndex() const {
  return SimpleCParser::RuleVarList;
}

antlrcpp::Any SimpleCParser::VarListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitVarList(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::VarListContext* SimpleCParser::varList() {
  VarListContext *_localctx = _tracker.createInstance<VarListContext>(_ctx, getState());
  enterRule(_localctx, 12, SimpleCParser::RuleVarList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    varID();
    setState(101);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleCParser::T__4) {
      setState(97);
      match(SimpleCParser::T__4);
      setState(98);
      varID();
      setState(103);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarIDContext ------------------------------------------------------------------

SimpleCParser::VarIDContext::VarIDContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleCParser::VarIDContext::ID() {
  return getToken(SimpleCParser::ID, 0);
}


size_t SimpleCParser::VarIDContext::getRuleIndex() const {
  return SimpleCParser::RuleVarID;
}

antlrcpp::Any SimpleCParser::VarIDContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitVarID(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::VarIDContext* SimpleCParser::varID() {
  VarIDContext *_localctx = _tracker.createInstance<VarIDContext>(_ctx, getState());
  enterRule(_localctx, 14, SimpleCParser::RuleVarID);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    match(SimpleCParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarOPContext ------------------------------------------------------------------

SimpleCParser::VarOPContext::VarOPContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SimpleCParser::VarOPContext::getRuleIndex() const {
  return SimpleCParser::RuleVarOP;
}

antlrcpp::Any SimpleCParser::VarOPContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitVarOP(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::VarOPContext* SimpleCParser::varOP() {
  VarOPContext *_localctx = _tracker.createInstance<VarOPContext>(_ctx, getState());
  enterRule(_localctx, 16, SimpleCParser::RuleVarOP);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(106);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimpleCParser::T__5)
      | (1ULL << SimpleCParser::T__6)
      | (1ULL << SimpleCParser::T__7))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VoidOPContext ------------------------------------------------------------------

SimpleCParser::VoidOPContext::VoidOPContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SimpleCParser::VoidOPContext::getRuleIndex() const {
  return SimpleCParser::RuleVoidOP;
}

antlrcpp::Any SimpleCParser::VoidOPContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitVoidOP(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::VoidOPContext* SimpleCParser::voidOP() {
  VoidOPContext *_localctx = _tracker.createInstance<VoidOPContext>(_ctx, getState());
  enterRule(_localctx, 18, SimpleCParser::RuleVoidOP);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    match(SimpleCParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assignment_statContext ------------------------------------------------------------------

SimpleCParser::Assignment_statContext::Assignment_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::VariContext* SimpleCParser::Assignment_statContext::vari() {
  return getRuleContext<SimpleCParser::VariContext>(0);
}

SimpleCParser::ExprContext* SimpleCParser::Assignment_statContext::expr() {
  return getRuleContext<SimpleCParser::ExprContext>(0);
}


size_t SimpleCParser::Assignment_statContext::getRuleIndex() const {
  return SimpleCParser::RuleAssignment_stat;
}

antlrcpp::Any SimpleCParser::Assignment_statContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitAssignment_stat(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::Assignment_statContext* SimpleCParser::assignment_stat() {
  Assignment_statContext *_localctx = _tracker.createInstance<Assignment_statContext>(_ctx, getState());
  enterRule(_localctx, 20, SimpleCParser::RuleAssignment_stat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    vari();
    setState(111);
    match(SimpleCParser::T__9);
    setState(112);
    expr(0);
    setState(113);
    match(SimpleCParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintContext ------------------------------------------------------------------

SimpleCParser::PrintContext::PrintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleCParser::PrintContext::PRINT() {
  return getToken(SimpleCParser::PRINT, 0);
}

SimpleCParser::StringContext* SimpleCParser::PrintContext::string() {
  return getRuleContext<SimpleCParser::StringContext>(0);
}


size_t SimpleCParser::PrintContext::getRuleIndex() const {
  return SimpleCParser::RulePrint;
}

antlrcpp::Any SimpleCParser::PrintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitPrint(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::PrintContext* SimpleCParser::print() {
  PrintContext *_localctx = _tracker.createInstance<PrintContext>(_ctx, getState());
  enterRule(_localctx, 22, SimpleCParser::RulePrint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    match(SimpleCParser::PRINT);
    setState(116);
    match(SimpleCParser::T__10);
    setState(117);
    string();
    setState(118);
    match(SimpleCParser::T__11);
    setState(119);
    match(SimpleCParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_statContext ------------------------------------------------------------------

SimpleCParser::If_statContext::If_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::ExprContext* SimpleCParser::If_statContext::expr() {
  return getRuleContext<SimpleCParser::ExprContext>(0);
}

std::vector<SimpleCParser::BlockContext *> SimpleCParser::If_statContext::block() {
  return getRuleContexts<SimpleCParser::BlockContext>();
}

SimpleCParser::BlockContext* SimpleCParser::If_statContext::block(size_t i) {
  return getRuleContext<SimpleCParser::BlockContext>(i);
}

SimpleCParser::If_statContext* SimpleCParser::If_statContext::if_stat() {
  return getRuleContext<SimpleCParser::If_statContext>(0);
}


size_t SimpleCParser::If_statContext::getRuleIndex() const {
  return SimpleCParser::RuleIf_stat;
}

antlrcpp::Any SimpleCParser::If_statContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitIf_stat(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::If_statContext* SimpleCParser::if_stat() {
  If_statContext *_localctx = _tracker.createInstance<If_statContext>(_ctx, getState());
  enterRule(_localctx, 24, SimpleCParser::RuleIf_stat);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    match(SimpleCParser::T__12);
    setState(122);
    expr(0);
    setState(123);
    block();
    setState(129);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SimpleCParser::T__13) {
      setState(124);
      match(SimpleCParser::T__13);
      setState(127);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
      case 1: {
        setState(125);
        if_stat();
        break;
      }

      case 2: {
        setState(126);
        block();
        break;
      }

      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_statContext ------------------------------------------------------------------

SimpleCParser::While_statContext::While_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::ExprContext* SimpleCParser::While_statContext::expr() {
  return getRuleContext<SimpleCParser::ExprContext>(0);
}

std::vector<SimpleCParser::StatContext *> SimpleCParser::While_statContext::stat() {
  return getRuleContexts<SimpleCParser::StatContext>();
}

SimpleCParser::StatContext* SimpleCParser::While_statContext::stat(size_t i) {
  return getRuleContext<SimpleCParser::StatContext>(i);
}


size_t SimpleCParser::While_statContext::getRuleIndex() const {
  return SimpleCParser::RuleWhile_stat;
}

antlrcpp::Any SimpleCParser::While_statContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitWhile_stat(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::While_statContext* SimpleCParser::while_stat() {
  While_statContext *_localctx = _tracker.createInstance<While_statContext>(_ctx, getState());
  enterRule(_localctx, 26, SimpleCParser::RuleWhile_stat);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131);
    match(SimpleCParser::T__14);
    setState(132);
    expr(0);
    setState(133);
    match(SimpleCParser::T__0);
    setState(137);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimpleCParser::T__5)
      | (1ULL << SimpleCParser::T__6)
      | (1ULL << SimpleCParser::T__7)
      | (1ULL << SimpleCParser::T__8)
      | (1ULL << SimpleCParser::T__12)
      | (1ULL << SimpleCParser::T__14)
      | (1ULL << SimpleCParser::T__15)
      | (1ULL << SimpleCParser::PRINT)
      | (1ULL << SimpleCParser::ID))) != 0)) {
      setState(134);
      stat();
      setState(139);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(140);
    match(SimpleCParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

SimpleCParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleCParser::FunctionContext::ID() {
  return getToken(SimpleCParser::ID, 0);
}

SimpleCParser::BlockContext* SimpleCParser::FunctionContext::block() {
  return getRuleContext<SimpleCParser::BlockContext>(0);
}

SimpleCParser::VarOPContext* SimpleCParser::FunctionContext::varOP() {
  return getRuleContext<SimpleCParser::VarOPContext>(0);
}

SimpleCParser::VoidOPContext* SimpleCParser::FunctionContext::voidOP() {
  return getRuleContext<SimpleCParser::VoidOPContext>(0);
}

SimpleCParser::ExprContext* SimpleCParser::FunctionContext::expr() {
  return getRuleContext<SimpleCParser::ExprContext>(0);
}


size_t SimpleCParser::FunctionContext::getRuleIndex() const {
  return SimpleCParser::RuleFunction;
}

antlrcpp::Any SimpleCParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::FunctionContext* SimpleCParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 28, SimpleCParser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::T__5:
      case SimpleCParser::T__6:
      case SimpleCParser::T__7: {
        setState(142);
        varOP();
        break;
      }

      case SimpleCParser::T__8: {
        setState(143);
        voidOP();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(146);
    match(SimpleCParser::ID);
    setState(148);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimpleCParser::T__10)
      | (1ULL << SimpleCParser::BOOL)
      | (1ULL << SimpleCParser::ID)
      | (1ULL << SimpleCParser::INT)
      | (1ULL << SimpleCParser::FLOAT))) != 0)) {
      setState(147);
      expr(0);
    }
    setState(150);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_callContext ------------------------------------------------------------------

SimpleCParser::Func_callContext::Func_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleCParser::Func_callContext::ID() {
  return getToken(SimpleCParser::ID, 0);
}

SimpleCParser::ExprContext* SimpleCParser::Func_callContext::expr() {
  return getRuleContext<SimpleCParser::ExprContext>(0);
}


size_t SimpleCParser::Func_callContext::getRuleIndex() const {
  return SimpleCParser::RuleFunc_call;
}

antlrcpp::Any SimpleCParser::Func_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitFunc_call(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::Func_callContext* SimpleCParser::func_call() {
  Func_callContext *_localctx = _tracker.createInstance<Func_callContext>(_ctx, getState());
  enterRule(_localctx, 30, SimpleCParser::RuleFunc_call);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(152);
    match(SimpleCParser::ID);
    setState(153);
    expr(0);
    setState(154);
    match(SimpleCParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_reContext ------------------------------------------------------------------

SimpleCParser::Func_reContext::Func_reContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleCParser::ExprContext* SimpleCParser::Func_reContext::expr() {
  return getRuleContext<SimpleCParser::ExprContext>(0);
}


size_t SimpleCParser::Func_reContext::getRuleIndex() const {
  return SimpleCParser::RuleFunc_re;
}

antlrcpp::Any SimpleCParser::Func_reContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitFunc_re(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::Func_reContext* SimpleCParser::func_re() {
  Func_reContext *_localctx = _tracker.createInstance<Func_reContext>(_ctx, getState());
  enterRule(_localctx, 32, SimpleCParser::RuleFunc_re);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(SimpleCParser::T__15);
    setState(158);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimpleCParser::T__10)
      | (1ULL << SimpleCParser::BOOL)
      | (1ULL << SimpleCParser::ID)
      | (1ULL << SimpleCParser::INT)
      | (1ULL << SimpleCParser::FLOAT))) != 0)) {
      setState(157);
      expr(0);
    }
    setState(160);
    match(SimpleCParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

SimpleCParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SimpleCParser::ExprContext::getRuleIndex() const {
  return SimpleCParser::RuleExpr;
}

void SimpleCParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- ExprIntContext ------------------------------------------------------------------

SimpleCParser::NumContext* SimpleCParser::ExprIntContext::num() {
  return getRuleContext<SimpleCParser::NumContext>(0);
}

SimpleCParser::ExprIntContext::ExprIntContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any SimpleCParser::ExprIntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitExprInt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprMultDivContext ------------------------------------------------------------------

std::vector<SimpleCParser::ExprContext *> SimpleCParser::ExprMultDivContext::expr() {
  return getRuleContexts<SimpleCParser::ExprContext>();
}

SimpleCParser::ExprContext* SimpleCParser::ExprMultDivContext::expr(size_t i) {
  return getRuleContext<SimpleCParser::ExprContext>(i);
}

SimpleCParser::MulDivOpContext* SimpleCParser::ExprMultDivContext::mulDivOp() {
  return getRuleContext<SimpleCParser::MulDivOpContext>(0);
}

SimpleCParser::ExprMultDivContext::ExprMultDivContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any SimpleCParser::ExprMultDivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitExprMultDiv(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprCompContext ------------------------------------------------------------------

std::vector<SimpleCParser::ExprContext *> SimpleCParser::ExprCompContext::expr() {
  return getRuleContexts<SimpleCParser::ExprContext>();
}

SimpleCParser::ExprContext* SimpleCParser::ExprCompContext::expr(size_t i) {
  return getRuleContext<SimpleCParser::ExprContext>(i);
}

SimpleCParser::CompOPContext* SimpleCParser::ExprCompContext::compOP() {
  return getRuleContext<SimpleCParser::CompOPContext>(0);
}

SimpleCParser::ExprCompContext::ExprCompContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any SimpleCParser::ExprCompContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitExprComp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprAddSubContext ------------------------------------------------------------------

std::vector<SimpleCParser::ExprContext *> SimpleCParser::ExprAddSubContext::expr() {
  return getRuleContexts<SimpleCParser::ExprContext>();
}

SimpleCParser::ExprContext* SimpleCParser::ExprAddSubContext::expr(size_t i) {
  return getRuleContext<SimpleCParser::ExprContext>(i);
}

SimpleCParser::AddSubOpContext* SimpleCParser::ExprAddSubContext::addSubOp() {
  return getRuleContext<SimpleCParser::AddSubOpContext>(0);
}

SimpleCParser::ExprAddSubContext::ExprAddSubContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any SimpleCParser::ExprAddSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitExprAddSub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprVariContext ------------------------------------------------------------------

SimpleCParser::VariContext* SimpleCParser::ExprVariContext::vari() {
  return getRuleContext<SimpleCParser::VariContext>(0);
}

SimpleCParser::ExprVariContext::ExprVariContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any SimpleCParser::ExprVariContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitExprVari(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprBoolContext ------------------------------------------------------------------

SimpleCParser::BoolnContext* SimpleCParser::ExprBoolContext::booln() {
  return getRuleContext<SimpleCParser::BoolnContext>(0);
}

SimpleCParser::ExprBoolContext::ExprBoolContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any SimpleCParser::ExprBoolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitExprBool(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprParaContext ------------------------------------------------------------------

SimpleCParser::ExprContext* SimpleCParser::ExprParaContext::expr() {
  return getRuleContext<SimpleCParser::ExprContext>(0);
}

SimpleCParser::ExprParaContext::ExprParaContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any SimpleCParser::ExprParaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitExprPara(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::ExprContext* SimpleCParser::expr() {
   return expr(0);
}

SimpleCParser::ExprContext* SimpleCParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleCParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  SimpleCParser::ExprContext *previousContext = _localctx;
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, SimpleCParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(170);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::INT:
      case SimpleCParser::FLOAT: {
        _localctx = _tracker.createInstance<ExprIntContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(163);
        num();
        break;
      }

      case SimpleCParser::BOOL: {
        _localctx = _tracker.createInstance<ExprBoolContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(164);
        booln();
        break;
      }

      case SimpleCParser::ID: {
        _localctx = _tracker.createInstance<ExprVariContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(165);
        vari();
        break;
      }

      case SimpleCParser::T__10: {
        _localctx = _tracker.createInstance<ExprParaContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(166);
        match(SimpleCParser::T__10);
        setState(167);
        expr(0);
        setState(168);
        match(SimpleCParser::T__11);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(186);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(184);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprMultDivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(172);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(173);
          mulDivOp();
          setState(174);
          expr(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprAddSubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(176);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(177);
          addSubOp();
          setState(178);
          expr(7);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprCompContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(180);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(181);
          compOP();
          setState(182);
          expr(6);
          break;
        }

        } 
      }
      setState(188);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VariContext ------------------------------------------------------------------

SimpleCParser::VariContext::VariContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleCParser::VariContext::ID() {
  return getToken(SimpleCParser::ID, 0);
}


size_t SimpleCParser::VariContext::getRuleIndex() const {
  return SimpleCParser::RuleVari;
}

antlrcpp::Any SimpleCParser::VariContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitVari(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::VariContext* SimpleCParser::vari() {
  VariContext *_localctx = _tracker.createInstance<VariContext>(_ctx, getState());
  enterRule(_localctx, 36, SimpleCParser::RuleVari);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    match(SimpleCParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

SimpleCParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> SimpleCParser::StringContext::ID() {
  return getTokens(SimpleCParser::ID);
}

tree::TerminalNode* SimpleCParser::StringContext::ID(size_t i) {
  return getToken(SimpleCParser::ID, i);
}


size_t SimpleCParser::StringContext::getRuleIndex() const {
  return SimpleCParser::RuleString;
}

antlrcpp::Any SimpleCParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::StringContext* SimpleCParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 38, SimpleCParser::RuleString);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
    match(SimpleCParser::T__16);
    setState(193); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(192);
      match(SimpleCParser::ID);
      setState(195); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SimpleCParser::ID);
    setState(197);
    match(SimpleCParser::T__16);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompOPContext ------------------------------------------------------------------

SimpleCParser::CompOPContext::CompOPContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleCParser::CompOPContext::EQU_OP() {
  return getToken(SimpleCParser::EQU_OP, 0);
}

tree::TerminalNode* SimpleCParser::CompOPContext::LEQ_OP() {
  return getToken(SimpleCParser::LEQ_OP, 0);
}

tree::TerminalNode* SimpleCParser::CompOPContext::GEQ_OP() {
  return getToken(SimpleCParser::GEQ_OP, 0);
}

tree::TerminalNode* SimpleCParser::CompOPContext::LES_OP() {
  return getToken(SimpleCParser::LES_OP, 0);
}

tree::TerminalNode* SimpleCParser::CompOPContext::GTR_OP() {
  return getToken(SimpleCParser::GTR_OP, 0);
}


size_t SimpleCParser::CompOPContext::getRuleIndex() const {
  return SimpleCParser::RuleCompOP;
}

antlrcpp::Any SimpleCParser::CompOPContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitCompOP(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::CompOPContext* SimpleCParser::compOP() {
  CompOPContext *_localctx = _tracker.createInstance<CompOPContext>(_ctx, getState());
  enterRule(_localctx, 40, SimpleCParser::RuleCompOP);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SimpleCParser::EQU_OP)
      | (1ULL << SimpleCParser::LEQ_OP)
      | (1ULL << SimpleCParser::GEQ_OP)
      | (1ULL << SimpleCParser::LES_OP)
      | (1ULL << SimpleCParser::GTR_OP))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulDivOpContext ------------------------------------------------------------------

SimpleCParser::MulDivOpContext::MulDivOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleCParser::MulDivOpContext::MUL_OP() {
  return getToken(SimpleCParser::MUL_OP, 0);
}

tree::TerminalNode* SimpleCParser::MulDivOpContext::DIV_OP() {
  return getToken(SimpleCParser::DIV_OP, 0);
}


size_t SimpleCParser::MulDivOpContext::getRuleIndex() const {
  return SimpleCParser::RuleMulDivOp;
}

antlrcpp::Any SimpleCParser::MulDivOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitMulDivOp(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::MulDivOpContext* SimpleCParser::mulDivOp() {
  MulDivOpContext *_localctx = _tracker.createInstance<MulDivOpContext>(_ctx, getState());
  enterRule(_localctx, 42, SimpleCParser::RuleMulDivOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    _la = _input->LA(1);
    if (!(_la == SimpleCParser::MUL_OP

    || _la == SimpleCParser::DIV_OP)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddSubOpContext ------------------------------------------------------------------

SimpleCParser::AddSubOpContext::AddSubOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleCParser::AddSubOpContext::ADD_OP() {
  return getToken(SimpleCParser::ADD_OP, 0);
}

tree::TerminalNode* SimpleCParser::AddSubOpContext::SUB_OP() {
  return getToken(SimpleCParser::SUB_OP, 0);
}


size_t SimpleCParser::AddSubOpContext::getRuleIndex() const {
  return SimpleCParser::RuleAddSubOp;
}

antlrcpp::Any SimpleCParser::AddSubOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitAddSubOp(this);
  else
    return visitor->visitChildren(this);
}

SimpleCParser::AddSubOpContext* SimpleCParser::addSubOp() {
  AddSubOpContext *_localctx = _tracker.createInstance<AddSubOpContext>(_ctx, getState());
  enterRule(_localctx, 44, SimpleCParser::RuleAddSubOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(203);
    _la = _input->LA(1);
    if (!(_la == SimpleCParser::ADD_OP

    || _la == SimpleCParser::SUB_OP)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumContext ------------------------------------------------------------------

SimpleCParser::NumContext::NumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SimpleCParser::NumContext::getRuleIndex() const {
  return SimpleCParser::RuleNum;
}

void SimpleCParser::NumContext::copyFrom(NumContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- FloatConstContext ------------------------------------------------------------------

tree::TerminalNode* SimpleCParser::FloatConstContext::FLOAT() {
  return getToken(SimpleCParser::FLOAT, 0);
}

SimpleCParser::FloatConstContext::FloatConstContext(NumContext *ctx) { copyFrom(ctx); }

antlrcpp::Any SimpleCParser::FloatConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitFloatConst(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntegerConstContext ------------------------------------------------------------------

tree::TerminalNode* SimpleCParser::IntegerConstContext::INT() {
  return getToken(SimpleCParser::INT, 0);
}

SimpleCParser::IntegerConstContext::IntegerConstContext(NumContext *ctx) { copyFrom(ctx); }

antlrcpp::Any SimpleCParser::IntegerConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitIntegerConst(this);
  else
    return visitor->visitChildren(this);
}
SimpleCParser::NumContext* SimpleCParser::num() {
  NumContext *_localctx = _tracker.createInstance<NumContext>(_ctx, getState());
  enterRule(_localctx, 46, SimpleCParser::RuleNum);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(207);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleCParser::INT: {
        _localctx = dynamic_cast<NumContext *>(_tracker.createInstance<SimpleCParser::IntegerConstContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(205);
        match(SimpleCParser::INT);
        break;
      }

      case SimpleCParser::FLOAT: {
        _localctx = dynamic_cast<NumContext *>(_tracker.createInstance<SimpleCParser::FloatConstContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(206);
        match(SimpleCParser::FLOAT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolnContext ------------------------------------------------------------------

SimpleCParser::BoolnContext::BoolnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SimpleCParser::BoolnContext::getRuleIndex() const {
  return SimpleCParser::RuleBooln;
}

void SimpleCParser::BoolnContext::copyFrom(BoolnContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- BoolConstContext ------------------------------------------------------------------

tree::TerminalNode* SimpleCParser::BoolConstContext::BOOL() {
  return getToken(SimpleCParser::BOOL, 0);
}

SimpleCParser::BoolConstContext::BoolConstContext(BoolnContext *ctx) { copyFrom(ctx); }

antlrcpp::Any SimpleCParser::BoolConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleCVisitor*>(visitor))
    return parserVisitor->visitBoolConst(this);
  else
    return visitor->visitChildren(this);
}
SimpleCParser::BoolnContext* SimpleCParser::booln() {
  BoolnContext *_localctx = _tracker.createInstance<BoolnContext>(_ctx, getState());
  enterRule(_localctx, 48, SimpleCParser::RuleBooln);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<BoolnContext *>(_tracker.createInstance<SimpleCParser::BoolConstContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(209);
    match(SimpleCParser::BOOL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool SimpleCParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 17: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SimpleCParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> SimpleCParser::_decisionToDFA;
atn::PredictionContextCache SimpleCParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SimpleCParser::_atn;
std::vector<uint16_t> SimpleCParser::_serializedATN;

std::vector<std::string> SimpleCParser::_ruleNames = {
  "prog", "header", "block", "stat", "var_table", "var_dec", "varList", 
  "varID", "varOP", "voidOP", "assignment_stat", "print", "if_stat", "while_stat", 
  "function", "func_call", "func_re", "expr", "vari", "string", "compOP", 
  "mulDivOp", "addSubOp", "num", "booln"
};

std::vector<std::string> SimpleCParser::_literalNames = {
  "", "'{'", "'}'", "'->'", "';'", "','", "'int'", "'bool'", "'float'", 
  "'void'", "'='", "'('", "')'", "'if'", "'else'", "'while'", "'return'", 
  "'\"'", "'*'", "'/'", "'+'", "'-'", "'=='", "'<='", "'>='", "'<'", "'>'", 
  "'VARLIST'", "'BIGMAIN'", "'print'"
};

std::vector<std::string> SimpleCParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "MUL_OP", "DIV_OP", "ADD_OP", "SUB_OP", "EQU_OP", "LEQ_OP", "GEQ_OP", 
  "LES_OP", "GTR_OP", "VARLIST", "BIGMAIN", "PRINT", "BOOL", "ID", "INT", 
  "FLOAT", "NEWLINE", "WS"
};

dfa::Vocabulary SimpleCParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SimpleCParser::_tokenNames;

SimpleCParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x25, 0xd6, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 
    0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x7, 0x2, 0x38, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x3b, 0xb, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x41, 0xa, 0x4, 0x3, 0x4, 
    0x7, 0x4, 0x44, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x47, 0xb, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0x52, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 
    0x6, 0x57, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x5a, 0xb, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x7, 0x8, 0x66, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x69, 0xb, 
    0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x82, 0xa, 0xe, 0x5, 0xe, 0x84, 0xa, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x8a, 0xa, 0xf, 
    0xc, 0xf, 0xe, 0xf, 0x8d, 0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x5, 0x10, 0x93, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x97, 
    0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xa1, 0xa, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xad, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0xbb, 0xa, 0x13, 0xc, 
    0x13, 0xe, 0x13, 0xbe, 0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 
    0x15, 0x6, 0x15, 0xc4, 0xa, 0x15, 0xd, 0x15, 0xe, 0x15, 0xc5, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0xd2, 0xa, 0x19, 0x3, 0x1a, 0x3, 
    0x1a, 0x3, 0x1a, 0x2, 0x3, 0x24, 0x1b, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
    0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x2, 0x6, 0x3, 0x2, 0x8, 0xa, 
    0x3, 0x2, 0x18, 0x1c, 0x3, 0x2, 0x14, 0x15, 0x3, 0x2, 0x16, 0x17, 0x2, 
    0xd6, 0x2, 0x34, 0x3, 0x2, 0x2, 0x2, 0x4, 0x3c, 0x3, 0x2, 0x2, 0x2, 
    0x6, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x8, 0x51, 0x3, 0x2, 0x2, 0x2, 0xa, 0x53, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0x5d, 0x3, 0x2, 0x2, 0x2, 0xe, 0x62, 0x3, 0x2, 
    0x2, 0x2, 0x10, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x12, 0x6c, 0x3, 0x2, 0x2, 
    0x2, 0x14, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x16, 0x70, 0x3, 0x2, 0x2, 0x2, 
    0x18, 0x75, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x1c, 
    0x85, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x92, 0x3, 0x2, 0x2, 0x2, 0x20, 0x9a, 
    0x3, 0x2, 0x2, 0x2, 0x22, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x24, 0xac, 0x3, 
    0x2, 0x2, 0x2, 0x26, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x28, 0xc1, 0x3, 0x2, 
    0x2, 0x2, 0x2a, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xcb, 0x3, 0x2, 0x2, 
    0x2, 0x2e, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x30, 0xd1, 0x3, 0x2, 0x2, 0x2, 
    0x32, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x5, 0x4, 0x3, 0x2, 0x35, 
    0x39, 0x5, 0x6, 0x4, 0x2, 0x36, 0x38, 0x5, 0x1e, 0x10, 0x2, 0x37, 0x36, 
    0x3, 0x2, 0x2, 0x2, 0x38, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x39, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x39, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x1e, 0x2, 
    0x2, 0x3d, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x40, 0x7, 0x3, 0x2, 0x2, 
    0x3f, 0x41, 0x5, 0xa, 0x6, 0x2, 0x40, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0x41, 0x45, 0x3, 0x2, 0x2, 0x2, 0x42, 0x44, 
    0x5, 0x8, 0x5, 0x2, 0x43, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 0x47, 0x3, 
    0x2, 0x2, 0x2, 0x45, 0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0x3, 0x2, 
    0x2, 0x2, 0x46, 0x48, 0x3, 0x2, 0x2, 0x2, 0x47, 0x45, 0x3, 0x2, 0x2, 
    0x2, 0x48, 0x49, 0x7, 0x4, 0x2, 0x2, 0x49, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x52, 0x5, 0x16, 0xc, 0x2, 0x4b, 0x52, 0x5, 0x1a, 0xe, 0x2, 0x4c, 
    0x52, 0x5, 0x1c, 0xf, 0x2, 0x4d, 0x52, 0x5, 0x1e, 0x10, 0x2, 0x4e, 0x52, 
    0x5, 0x20, 0x11, 0x2, 0x4f, 0x52, 0x5, 0x18, 0xd, 0x2, 0x50, 0x52, 0x5, 
    0x22, 0x12, 0x2, 0x51, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x51, 0x4b, 0x3, 0x2, 
    0x2, 0x2, 0x51, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x51, 0x4d, 0x3, 0x2, 0x2, 
    0x2, 0x51, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 
    0x51, 0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 0x9, 0x3, 0x2, 0x2, 0x2, 0x53, 
    0x54, 0x7, 0x1d, 0x2, 0x2, 0x54, 0x58, 0x7, 0x3, 0x2, 0x2, 0x55, 0x57, 
    0x5, 0xc, 0x7, 0x2, 0x56, 0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 0x5a, 0x3, 
    0x2, 0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0x59, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 
    0x2, 0x5b, 0x5c, 0x7, 0x4, 0x2, 0x2, 0x5c, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x5d, 0x5e, 0x5, 0xe, 0x8, 0x2, 0x5e, 0x5f, 0x7, 0x5, 0x2, 0x2, 0x5f, 
    0x60, 0x5, 0x12, 0xa, 0x2, 0x60, 0x61, 0x7, 0x6, 0x2, 0x2, 0x61, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x62, 0x67, 0x5, 0x10, 0x9, 0x2, 0x63, 0x64, 0x7, 
    0x7, 0x2, 0x2, 0x64, 0x66, 0x5, 0x10, 0x9, 0x2, 0x65, 0x63, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x69, 0x3, 0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 
    0x2, 0x67, 0x68, 0x3, 0x2, 0x2, 0x2, 0x68, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x7, 0x21, 0x2, 0x2, 0x6b, 
    0x11, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x9, 0x2, 0x2, 0x2, 0x6d, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0xb, 0x2, 0x2, 0x6f, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0x70, 0x71, 0x5, 0x26, 0x14, 0x2, 0x71, 0x72, 0x7, 0xc, 
    0x2, 0x2, 0x72, 0x73, 0x5, 0x24, 0x13, 0x2, 0x73, 0x74, 0x7, 0x6, 0x2, 
    0x2, 0x74, 0x17, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x7, 0x1f, 0x2, 0x2, 
    0x76, 0x77, 0x7, 0xd, 0x2, 0x2, 0x77, 0x78, 0x5, 0x28, 0x15, 0x2, 0x78, 
    0x79, 0x7, 0xe, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x6, 0x2, 0x2, 0x7a, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0xf, 0x2, 0x2, 0x7c, 0x7d, 0x5, 
    0x24, 0x13, 0x2, 0x7d, 0x83, 0x5, 0x6, 0x4, 0x2, 0x7e, 0x81, 0x7, 0x10, 
    0x2, 0x2, 0x7f, 0x82, 0x5, 0x1a, 0xe, 0x2, 0x80, 0x82, 0x5, 0x6, 0x4, 
    0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x80, 0x3, 0x2, 0x2, 0x2, 
    0x81, 0x82, 0x3, 0x2, 0x2, 0x2, 0x82, 0x84, 0x3, 0x2, 0x2, 0x2, 0x83, 
    0x7e, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x3, 0x2, 0x2, 0x2, 0x84, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x7, 0x11, 0x2, 0x2, 0x86, 0x87, 0x5, 
    0x24, 0x13, 0x2, 0x87, 0x8b, 0x7, 0x3, 0x2, 0x2, 0x88, 0x8a, 0x5, 0x8, 
    0x5, 0x2, 0x89, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8d, 0x3, 0x2, 0x2, 
    0x2, 0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 
    0x8c, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8e, 
    0x8f, 0x7, 0x4, 0x2, 0x2, 0x8f, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x90, 0x93, 
    0x5, 0x12, 0xa, 0x2, 0x91, 0x93, 0x5, 0x14, 0xb, 0x2, 0x92, 0x90, 0x3, 
    0x2, 0x2, 0x2, 0x92, 0x91, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 
    0x2, 0x2, 0x94, 0x96, 0x7, 0x21, 0x2, 0x2, 0x95, 0x97, 0x5, 0x24, 0x13, 
    0x2, 0x96, 0x95, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x3, 0x2, 0x2, 0x2, 
    0x97, 0x98, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x5, 0x6, 0x4, 0x2, 0x99, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x21, 0x2, 0x2, 0x9b, 0x9c, 
    0x5, 0x24, 0x13, 0x2, 0x9c, 0x9d, 0x7, 0x6, 0x2, 0x2, 0x9d, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0x9e, 0xa0, 0x7, 0x12, 0x2, 0x2, 0x9f, 0xa1, 0x5, 0x24, 
    0x13, 0x2, 0xa0, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x3, 0x2, 0x2, 
    0x2, 0xa1, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x7, 0x6, 0x2, 0x2, 
    0xa3, 0x23, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x8, 0x13, 0x1, 0x2, 0xa5, 
    0xad, 0x5, 0x30, 0x19, 0x2, 0xa6, 0xad, 0x5, 0x32, 0x1a, 0x2, 0xa7, 
    0xad, 0x5, 0x26, 0x14, 0x2, 0xa8, 0xa9, 0x7, 0xd, 0x2, 0x2, 0xa9, 0xaa, 
    0x5, 0x24, 0x13, 0x2, 0xaa, 0xab, 0x7, 0xe, 0x2, 0x2, 0xab, 0xad, 0x3, 
    0x2, 0x2, 0x2, 0xac, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xac, 0xa6, 0x3, 0x2, 
    0x2, 0x2, 0xac, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xac, 0xa8, 0x3, 0x2, 0x2, 
    0x2, 0xad, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0xc, 0x9, 0x2, 0x2, 
    0xaf, 0xb0, 0x5, 0x2c, 0x17, 0x2, 0xb0, 0xb1, 0x5, 0x24, 0x13, 0xa, 
    0xb1, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0xc, 0x8, 0x2, 0x2, 0xb3, 
    0xb4, 0x5, 0x2e, 0x18, 0x2, 0xb4, 0xb5, 0x5, 0x24, 0x13, 0x9, 0xb5, 
    0xbb, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0xc, 0x7, 0x2, 0x2, 0xb7, 0xb8, 
    0x5, 0x2a, 0x16, 0x2, 0xb8, 0xb9, 0x5, 0x24, 0x13, 0x8, 0xb9, 0xbb, 
    0x3, 0x2, 0x2, 0x2, 0xba, 0xae, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb2, 0x3, 
    0x2, 0x2, 0x2, 0xba, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbe, 0x3, 0x2, 
    0x2, 0x2, 0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 0x2, 0x2, 
    0x2, 0xbd, 0x25, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbc, 0x3, 0x2, 0x2, 0x2, 
    0xbf, 0xc0, 0x7, 0x21, 0x2, 0x2, 0xc0, 0x27, 0x3, 0x2, 0x2, 0x2, 0xc1, 
    0xc3, 0x7, 0x13, 0x2, 0x2, 0xc2, 0xc4, 0x7, 0x21, 0x2, 0x2, 0xc3, 0xc2, 
    0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc3, 0x3, 
    0x2, 0x2, 0x2, 0xc5, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x3, 0x2, 
    0x2, 0x2, 0xc7, 0xc8, 0x7, 0x13, 0x2, 0x2, 0xc8, 0x29, 0x3, 0x2, 0x2, 
    0x2, 0xc9, 0xca, 0x9, 0x3, 0x2, 0x2, 0xca, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0xcb, 0xcc, 0x9, 0x4, 0x2, 0x2, 0xcc, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xcd, 
    0xce, 0x9, 0x5, 0x2, 0x2, 0xce, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd2, 
    0x7, 0x22, 0x2, 0x2, 0xd0, 0xd2, 0x7, 0x23, 0x2, 0x2, 0xd1, 0xcf, 0x3, 
    0x2, 0x2, 0x2, 0xd1, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd2, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0xd3, 0xd4, 0x7, 0x20, 0x2, 0x2, 0xd4, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x13, 0x39, 0x40, 0x45, 0x51, 0x58, 0x67, 0x81, 0x83, 0x8b, 0x92, 
    0x96, 0xa0, 0xac, 0xba, 0xbc, 0xc5, 0xd1, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SimpleCParser::Initializer SimpleCParser::_init;
