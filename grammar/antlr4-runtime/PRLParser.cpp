
// Generated from /Users/andreacolledan/Projects/pattern-rewriting-language/grammar/PRL.g4 by ANTLR 4.9.2


#include "PRLVisitor.h"

#include "PRLParser.h"


using namespace antlrcpp;
using namespace antlr4;

PRLParser::PRLParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

PRLParser::~PRLParser() {
  delete _interpreter;
}

std::string PRLParser::getGrammarFileName() const {
  return "PRL.g4";
}

const std::vector<std::string>& PRLParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& PRLParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

PRLParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PRLParser::SymbolSectionContext* PRLParser::ProgContext::symbolSection() {
  return getRuleContext<PRLParser::SymbolSectionContext>(0);
}

tree::TerminalNode* PRLParser::ProgContext::EOF() {
  return getToken(PRLParser::EOF, 0);
}

PRLParser::InitialStateSectionContext* PRLParser::ProgContext::initialStateSection() {
  return getRuleContext<PRLParser::InitialStateSectionContext>(0);
}

std::vector<tree::TerminalNode *> PRLParser::ProgContext::BR() {
  return getTokens(PRLParser::BR);
}

tree::TerminalNode* PRLParser::ProgContext::BR(size_t i) {
  return getToken(PRLParser::BR, i);
}

PRLParser::RuleSectionContext* PRLParser::ProgContext::ruleSection() {
  return getRuleContext<PRLParser::RuleSectionContext>(0);
}


size_t PRLParser::ProgContext::getRuleIndex() const {
  return PRLParser::RuleProg;
}


antlrcpp::Any PRLParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PRLVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

PRLParser::ProgContext* PRLParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, PRLParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(22);
    symbolSection();
    setState(24); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(23);
              match(PRLParser::BR);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(26); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(46);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PRLParser::RULES_KW:
      case PRLParser::BR: {
        setState(29);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PRLParser::RULES_KW) {
          setState(28);
          ruleSection();
        }
        setState(32); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(31);
          match(PRLParser::BR);
          setState(34); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == PRLParser::BR);
        setState(36);
        initialStateSection();
        break;
      }

      case PRLParser::IS_KW: {
        setState(37);
        initialStateSection();
        setState(39); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(38);
                  match(PRLParser::BR);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(41); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        setState(44);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PRLParser::RULES_KW) {
          setState(43);
          ruleSection();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(51);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PRLParser::BR) {
      setState(48);
      match(PRLParser::BR);
      setState(53);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(54);
    match(PRLParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SymbolSectionContext ------------------------------------------------------------------

PRLParser::SymbolSectionContext::SymbolSectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PRLParser::SymbolSectionContext::SYMBOL_KW() {
  return getToken(PRLParser::SYMBOL_KW, 0);
}

std::vector<tree::TerminalNode *> PRLParser::SymbolSectionContext::SYMBOL_ID() {
  return getTokens(PRLParser::SYMBOL_ID);
}

tree::TerminalNode* PRLParser::SymbolSectionContext::SYMBOL_ID(size_t i) {
  return getToken(PRLParser::SYMBOL_ID, i);
}

std::vector<tree::TerminalNode *> PRLParser::SymbolSectionContext::COMMA() {
  return getTokens(PRLParser::COMMA);
}

tree::TerminalNode* PRLParser::SymbolSectionContext::COMMA(size_t i) {
  return getToken(PRLParser::COMMA, i);
}


size_t PRLParser::SymbolSectionContext::getRuleIndex() const {
  return PRLParser::RuleSymbolSection;
}


antlrcpp::Any PRLParser::SymbolSectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PRLVisitor*>(visitor))
    return parserVisitor->visitSymbolSection(this);
  else
    return visitor->visitChildren(this);
}

PRLParser::SymbolSectionContext* PRLParser::symbolSection() {
  SymbolSectionContext *_localctx = _tracker.createInstance<SymbolSectionContext>(_ctx, getState());
  enterRule(_localctx, 2, PRLParser::RuleSymbolSection);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    match(PRLParser::SYMBOL_KW);
    setState(57);
    match(PRLParser::SYMBOL_ID);
    setState(62);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PRLParser::COMMA) {
      setState(58);
      match(PRLParser::COMMA);
      setState(59);
      match(PRLParser::SYMBOL_ID);
      setState(64);
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

//----------------- RuleSectionContext ------------------------------------------------------------------

PRLParser::RuleSectionContext::RuleSectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PRLParser::RuleSectionContext::RULES_KW() {
  return getToken(PRLParser::RULES_KW, 0);
}

std::vector<tree::TerminalNode *> PRLParser::RuleSectionContext::BR() {
  return getTokens(PRLParser::BR);
}

tree::TerminalNode* PRLParser::RuleSectionContext::BR(size_t i) {
  return getToken(PRLParser::BR, i);
}

std::vector<PRLParser::RewritingRuleContext *> PRLParser::RuleSectionContext::rewritingRule() {
  return getRuleContexts<PRLParser::RewritingRuleContext>();
}

PRLParser::RewritingRuleContext* PRLParser::RuleSectionContext::rewritingRule(size_t i) {
  return getRuleContext<PRLParser::RewritingRuleContext>(i);
}


size_t PRLParser::RuleSectionContext::getRuleIndex() const {
  return PRLParser::RuleRuleSection;
}


antlrcpp::Any PRLParser::RuleSectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PRLVisitor*>(visitor))
    return parserVisitor->visitRuleSection(this);
  else
    return visitor->visitChildren(this);
}

PRLParser::RuleSectionContext* PRLParser::ruleSection() {
  RuleSectionContext *_localctx = _tracker.createInstance<RuleSectionContext>(_ctx, getState());
  enterRule(_localctx, 4, PRLParser::RuleRuleSection);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(65);
    match(PRLParser::RULES_KW);
    setState(66);
    match(PRLParser::BR);
    setState(70);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PRLParser::BR) {
      setState(67);
      match(PRLParser::BR);
      setState(72);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(73);
    rewritingRule();
    setState(82);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(75); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(74);
          match(PRLParser::BR);
          setState(77); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == PRLParser::BR);
        setState(79);
        rewritingRule(); 
      }
      setState(84);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RewritingRuleContext ------------------------------------------------------------------

PRLParser::RewritingRuleContext::RewritingRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PRLParser::ArrowContext* PRLParser::RewritingRuleContext::arrow() {
  return getRuleContext<PRLParser::ArrowContext>(0);
}

std::vector<PRLParser::PatternContext *> PRLParser::RewritingRuleContext::pattern() {
  return getRuleContexts<PRLParser::PatternContext>();
}

PRLParser::PatternContext* PRLParser::RewritingRuleContext::pattern(size_t i) {
  return getRuleContext<PRLParser::PatternContext>(i);
}


size_t PRLParser::RewritingRuleContext::getRuleIndex() const {
  return PRLParser::RuleRewritingRule;
}


antlrcpp::Any PRLParser::RewritingRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PRLVisitor*>(visitor))
    return parserVisitor->visitRewritingRule(this);
  else
    return visitor->visitChildren(this);
}

PRLParser::RewritingRuleContext* PRLParser::rewritingRule() {
  RewritingRuleContext *_localctx = _tracker.createInstance<RewritingRuleContext>(_ctx, getState());
  enterRule(_localctx, 6, PRLParser::RuleRewritingRule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    dynamic_cast<RewritingRuleContext *>(_localctx)->lhs = pattern();
    setState(86);
    arrow();
    setState(87);
    dynamic_cast<RewritingRuleContext *>(_localctx)->rhs = pattern();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PatternContext ------------------------------------------------------------------

PRLParser::PatternContext::PatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PRLParser::RowContext *> PRLParser::PatternContext::row() {
  return getRuleContexts<PRLParser::RowContext>();
}

PRLParser::RowContext* PRLParser::PatternContext::row(size_t i) {
  return getRuleContext<PRLParser::RowContext>(i);
}

std::vector<tree::TerminalNode *> PRLParser::PatternContext::BR() {
  return getTokens(PRLParser::BR);
}

tree::TerminalNode* PRLParser::PatternContext::BR(size_t i) {
  return getToken(PRLParser::BR, i);
}


size_t PRLParser::PatternContext::getRuleIndex() const {
  return PRLParser::RulePattern;
}


antlrcpp::Any PRLParser::PatternContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PRLVisitor*>(visitor))
    return parserVisitor->visitPattern(this);
  else
    return visitor->visitChildren(this);
}

PRLParser::PatternContext* PRLParser::pattern() {
  PatternContext *_localctx = _tracker.createInstance<PatternContext>(_ctx, getState());
  enterRule(_localctx, 8, PRLParser::RulePattern);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(89);
    row();
    setState(94);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(90);
        match(PRLParser::BR);
        setState(91);
        row(); 
      }
      setState(96);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrowContext ------------------------------------------------------------------

PRLParser::ArrowContext::ArrowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PRLParser::ArrowContext::NN_NUMBER() {
  return getToken(PRLParser::NN_NUMBER, 0);
}


size_t PRLParser::ArrowContext::getRuleIndex() const {
  return PRLParser::RuleArrow;
}


antlrcpp::Any PRLParser::ArrowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PRLVisitor*>(visitor))
    return parserVisitor->visitArrow(this);
  else
    return visitor->visitChildren(this);
}

PRLParser::ArrowContext* PRLParser::arrow() {
  ArrowContext *_localctx = _tracker.createInstance<ArrowContext>(_ctx, getState());
  enterRule(_localctx, 10, PRLParser::RuleArrow);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97);
    match(PRLParser::T__0);
    setState(99);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PRLParser::NN_NUMBER) {
      setState(98);
      match(PRLParser::NN_NUMBER);
    }
    setState(101);
    match(PRLParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RowContext ------------------------------------------------------------------

PRLParser::RowContext::RowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PRLParser::SymbolContext *> PRLParser::RowContext::symbol() {
  return getRuleContexts<PRLParser::SymbolContext>();
}

PRLParser::SymbolContext* PRLParser::RowContext::symbol(size_t i) {
  return getRuleContext<PRLParser::SymbolContext>(i);
}


size_t PRLParser::RowContext::getRuleIndex() const {
  return PRLParser::RuleRow;
}


antlrcpp::Any PRLParser::RowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PRLVisitor*>(visitor))
    return parserVisitor->visitRow(this);
  else
    return visitor->visitChildren(this);
}

PRLParser::RowContext* PRLParser::row() {
  RowContext *_localctx = _tracker.createInstance<RowContext>(_ctx, getState());
  enterRule(_localctx, 12, PRLParser::RuleRow);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(103);
      symbol();
      setState(106); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == PRLParser::SYMBOL_ID

    || _la == PRLParser::SYMBOL_WC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SymbolContext ------------------------------------------------------------------

PRLParser::SymbolContext::SymbolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PRLParser::SymbolContext::SYMBOL_ID() {
  return getToken(PRLParser::SYMBOL_ID, 0);
}

tree::TerminalNode* PRLParser::SymbolContext::SYMBOL_WC() {
  return getToken(PRLParser::SYMBOL_WC, 0);
}


size_t PRLParser::SymbolContext::getRuleIndex() const {
  return PRLParser::RuleSymbol;
}


antlrcpp::Any PRLParser::SymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PRLVisitor*>(visitor))
    return parserVisitor->visitSymbol(this);
  else
    return visitor->visitChildren(this);
}

PRLParser::SymbolContext* PRLParser::symbol() {
  SymbolContext *_localctx = _tracker.createInstance<SymbolContext>(_ctx, getState());
  enterRule(_localctx, 14, PRLParser::RuleSymbol);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    _la = _input->LA(1);
    if (!(_la == PRLParser::SYMBOL_ID

    || _la == PRLParser::SYMBOL_WC)) {
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

//----------------- InitialStateSectionContext ------------------------------------------------------------------

PRLParser::InitialStateSectionContext::InitialStateSectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PRLParser::InitialStateSectionContext::IS_KW() {
  return getToken(PRLParser::IS_KW, 0);
}

PRLParser::InitialStateContext* PRLParser::InitialStateSectionContext::initialState() {
  return getRuleContext<PRLParser::InitialStateContext>(0);
}

std::vector<tree::TerminalNode *> PRLParser::InitialStateSectionContext::BR() {
  return getTokens(PRLParser::BR);
}

tree::TerminalNode* PRLParser::InitialStateSectionContext::BR(size_t i) {
  return getToken(PRLParser::BR, i);
}


size_t PRLParser::InitialStateSectionContext::getRuleIndex() const {
  return PRLParser::RuleInitialStateSection;
}


antlrcpp::Any PRLParser::InitialStateSectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PRLVisitor*>(visitor))
    return parserVisitor->visitInitialStateSection(this);
  else
    return visitor->visitChildren(this);
}

PRLParser::InitialStateSectionContext* PRLParser::initialStateSection() {
  InitialStateSectionContext *_localctx = _tracker.createInstance<InitialStateSectionContext>(_ctx, getState());
  enterRule(_localctx, 16, PRLParser::RuleInitialStateSection);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    match(PRLParser::IS_KW);
    setState(114);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PRLParser::BR) {
      setState(111);
      match(PRLParser::BR);
      setState(116);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(117);
    initialState();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitialStateContext ------------------------------------------------------------------

PRLParser::InitialStateContext::InitialStateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PRLParser::InitialStateContext::getRuleIndex() const {
  return PRLParser::RuleInitialState;
}

void PRLParser::InitialStateContext::copyFrom(InitialStateContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExtensionalInitialStateContext ------------------------------------------------------------------

PRLParser::PatternContext* PRLParser::ExtensionalInitialStateContext::pattern() {
  return getRuleContext<PRLParser::PatternContext>(0);
}

PRLParser::ExtensionalInitialStateContext::ExtensionalInitialStateContext(InitialStateContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PRLParser::ExtensionalInitialStateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PRLVisitor*>(visitor))
    return parserVisitor->visitExtensionalInitialState(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntensionalInitialStateContext ------------------------------------------------------------------

tree::TerminalNode* PRLParser::IntensionalInitialStateContext::SYMBOL_ID() {
  return getToken(PRLParser::SYMBOL_ID, 0);
}

PRLParser::ShapeContext* PRLParser::IntensionalInitialStateContext::shape() {
  return getRuleContext<PRLParser::ShapeContext>(0);
}

PRLParser::IntensionalInitialStateContext::IntensionalInitialStateContext(InitialStateContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PRLParser::IntensionalInitialStateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PRLVisitor*>(visitor))
    return parserVisitor->visitIntensionalInitialState(this);
  else
    return visitor->visitChildren(this);
}
PRLParser::InitialStateContext* PRLParser::initialState() {
  InitialStateContext *_localctx = _tracker.createInstance<InitialStateContext>(_ctx, getState());
  enterRule(_localctx, 18, PRLParser::RuleInitialState);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(122);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<InitialStateContext *>(_tracker.createInstance<PRLParser::IntensionalInitialStateContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(119);
      match(PRLParser::SYMBOL_ID);
      setState(120);
      shape();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<InitialStateContext *>(_tracker.createInstance<PRLParser::ExtensionalInitialStateContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(121);
      pattern();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShapeContext ------------------------------------------------------------------

PRLParser::ShapeContext::ShapeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PRLParser::ShapeContext::LPAR() {
  return getToken(PRLParser::LPAR, 0);
}

tree::TerminalNode* PRLParser::ShapeContext::COMMA() {
  return getToken(PRLParser::COMMA, 0);
}

tree::TerminalNode* PRLParser::ShapeContext::RPAR() {
  return getToken(PRLParser::RPAR, 0);
}

std::vector<tree::TerminalNode *> PRLParser::ShapeContext::NN_NUMBER() {
  return getTokens(PRLParser::NN_NUMBER);
}

tree::TerminalNode* PRLParser::ShapeContext::NN_NUMBER(size_t i) {
  return getToken(PRLParser::NN_NUMBER, i);
}


size_t PRLParser::ShapeContext::getRuleIndex() const {
  return PRLParser::RuleShape;
}


antlrcpp::Any PRLParser::ShapeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PRLVisitor*>(visitor))
    return parserVisitor->visitShape(this);
  else
    return visitor->visitChildren(this);
}

PRLParser::ShapeContext* PRLParser::shape() {
  ShapeContext *_localctx = _tracker.createInstance<ShapeContext>(_ctx, getState());
  enterRule(_localctx, 20, PRLParser::RuleShape);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    match(PRLParser::LPAR);
    setState(125);
    dynamic_cast<ShapeContext *>(_localctx)->height = match(PRLParser::NN_NUMBER);
    setState(126);
    match(PRLParser::COMMA);
    setState(127);
    dynamic_cast<ShapeContext *>(_localctx)->width = match(PRLParser::NN_NUMBER);
    setState(128);
    match(PRLParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> PRLParser::_decisionToDFA;
atn::PredictionContextCache PRLParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN PRLParser::_atn;
std::vector<uint16_t> PRLParser::_serializedATN;

std::vector<std::string> PRLParser::_ruleNames = {
  "prog", "symbolSection", "ruleSection", "rewritingRule", "pattern", "arrow", 
  "row", "symbol", "initialStateSection", "initialState", "shape"
};

std::vector<std::string> PRLParser::_literalNames = {
  "", "'-'", "'>'", "", "'*'", "'Symbols'", "'Apply rules'", "", "'Starting from'", 
  "'('", "')'", "','"
};

std::vector<std::string> PRLParser::_symbolicNames = {
  "", "", "", "SYMBOL_ID", "SYMBOL_WC", "SYMBOL_KW", "RULES_KW", "NN_NUMBER", 
  "IS_KW", "LPAR", "RPAR", "COMMA", "BR", "WS"
};

dfa::Vocabulary PRLParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> PRLParser::_tokenNames;

PRLParser::Initializer::Initializer() {
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

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0xf, 0x85, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x3, 0x2, 0x3, 0x2, 0x6, 
       0x2, 0x1b, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x1c, 0x3, 0x2, 0x5, 0x2, 
       0x20, 0xa, 0x2, 0x3, 0x2, 0x6, 0x2, 0x23, 0xa, 0x2, 0xd, 0x2, 0xe, 
       0x2, 0x24, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x6, 0x2, 0x2a, 0xa, 0x2, 
       0xd, 0x2, 0xe, 0x2, 0x2b, 0x3, 0x2, 0x5, 0x2, 0x2f, 0xa, 0x2, 0x5, 
       0x2, 0x31, 0xa, 0x2, 0x3, 0x2, 0x7, 0x2, 0x34, 0xa, 0x2, 0xc, 0x2, 
       0xe, 0x2, 0x37, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x3f, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 
       0x42, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x47, 0xa, 
       0x4, 0xc, 0x4, 0xe, 0x4, 0x4a, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x6, 
       0x4, 0x4e, 0xa, 0x4, 0xd, 0x4, 0xe, 0x4, 0x4f, 0x3, 0x4, 0x7, 0x4, 
       0x53, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x56, 0xb, 0x4, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 
       0x5f, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x62, 0xb, 0x6, 0x3, 0x7, 0x3, 
       0x7, 0x5, 0x7, 0x66, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x6, 
       0x8, 0x6b, 0xa, 0x8, 0xd, 0x8, 0xe, 0x8, 0x6c, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x73, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 
       0x76, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
       0x5, 0xb, 0x7d, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
       0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x2, 0x2, 0xd, 0x2, 0x4, 0x6, 0x8, 
       0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x2, 0x3, 0x3, 0x2, 0x5, 0x6, 
       0x2, 0x89, 0x2, 0x18, 0x3, 0x2, 0x2, 0x2, 0x4, 0x3a, 0x3, 0x2, 0x2, 
       0x2, 0x6, 0x43, 0x3, 0x2, 0x2, 0x2, 0x8, 0x57, 0x3, 0x2, 0x2, 0x2, 
       0xa, 0x5b, 0x3, 0x2, 0x2, 0x2, 0xc, 0x63, 0x3, 0x2, 0x2, 0x2, 0xe, 
       0x6a, 0x3, 0x2, 0x2, 0x2, 0x10, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x12, 0x70, 
       0x3, 0x2, 0x2, 0x2, 0x14, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x16, 0x7e, 0x3, 
       0x2, 0x2, 0x2, 0x18, 0x1a, 0x5, 0x4, 0x3, 0x2, 0x19, 0x1b, 0x7, 0xe, 
       0x2, 0x2, 0x1a, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1c, 0x3, 0x2, 0x2, 
       0x2, 0x1c, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x3, 0x2, 0x2, 0x2, 
       0x1d, 0x30, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x20, 0x5, 0x6, 0x4, 0x2, 0x1f, 
       0x1e, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x3, 0x2, 0x2, 0x2, 0x20, 0x22, 
       0x3, 0x2, 0x2, 0x2, 0x21, 0x23, 0x7, 0xe, 0x2, 0x2, 0x22, 0x21, 0x3, 
       0x2, 0x2, 0x2, 0x23, 0x24, 0x3, 0x2, 0x2, 0x2, 0x24, 0x22, 0x3, 0x2, 
       0x2, 0x2, 0x24, 0x25, 0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0x3, 0x2, 0x2, 
       0x2, 0x26, 0x31, 0x5, 0x12, 0xa, 0x2, 0x27, 0x29, 0x5, 0x12, 0xa, 
       0x2, 0x28, 0x2a, 0x7, 0xe, 0x2, 0x2, 0x29, 0x28, 0x3, 0x2, 0x2, 0x2, 
       0x2a, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2b, 
       0x2c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2f, 
       0x5, 0x6, 0x4, 0x2, 0x2e, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x3, 
       0x2, 0x2, 0x2, 0x2f, 0x31, 0x3, 0x2, 0x2, 0x2, 0x30, 0x1f, 0x3, 0x2, 
       0x2, 0x2, 0x30, 0x27, 0x3, 0x2, 0x2, 0x2, 0x31, 0x35, 0x3, 0x2, 0x2, 
       0x2, 0x32, 0x34, 0x7, 0xe, 0x2, 0x2, 0x33, 0x32, 0x3, 0x2, 0x2, 0x2, 
       0x34, 0x37, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 
       0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 0x38, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 
       0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x7, 0x2, 0x2, 0x3, 0x39, 0x3, 0x3, 
       0x2, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0x7, 0x2, 0x2, 0x3b, 0x40, 0x7, 0x5, 
       0x2, 0x2, 0x3c, 0x3d, 0x7, 0xd, 0x2, 0x2, 0x3d, 0x3f, 0x7, 0x5, 0x2, 
       0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x42, 0x3, 0x2, 0x2, 0x2, 
       0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x3, 0x2, 0x2, 0x2, 0x41, 
       0x5, 0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 
       0x7, 0x8, 0x2, 0x2, 0x44, 0x48, 0x7, 0xe, 0x2, 0x2, 0x45, 0x47, 0x7, 
       0xe, 0x2, 0x2, 0x46, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x4a, 0x3, 0x2, 
       0x2, 0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x3, 0x2, 0x2, 
       0x2, 0x49, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 
       0x4b, 0x54, 0x5, 0x8, 0x5, 0x2, 0x4c, 0x4e, 0x7, 0xe, 0x2, 0x2, 0x4d, 
       0x4c, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4d, 
       0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x3, 
       0x2, 0x2, 0x2, 0x51, 0x53, 0x5, 0x8, 0x5, 0x2, 0x52, 0x4d, 0x3, 0x2, 
       0x2, 0x2, 0x53, 0x56, 0x3, 0x2, 0x2, 0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 
       0x2, 0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 0x55, 0x7, 0x3, 0x2, 0x2, 0x2, 
       0x56, 0x54, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x5, 0xa, 0x6, 0x2, 0x58, 
       0x59, 0x5, 0xc, 0x7, 0x2, 0x59, 0x5a, 0x5, 0xa, 0x6, 0x2, 0x5a, 0x9, 
       0x3, 0x2, 0x2, 0x2, 0x5b, 0x60, 0x5, 0xe, 0x8, 0x2, 0x5c, 0x5d, 0x7, 
       0xe, 0x2, 0x2, 0x5d, 0x5f, 0x5, 0xe, 0x8, 0x2, 0x5e, 0x5c, 0x3, 0x2, 
       0x2, 0x2, 0x5f, 0x62, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5e, 0x3, 0x2, 0x2, 
       0x2, 0x60, 0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 0xb, 0x3, 0x2, 0x2, 0x2, 
       0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x63, 0x65, 0x7, 0x3, 0x2, 0x2, 0x64, 
       0x66, 0x7, 0x9, 0x2, 0x2, 0x65, 0x64, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 
       0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 
       0x4, 0x2, 0x2, 0x68, 0xd, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6b, 0x5, 0x10, 
       0x9, 0x2, 0x6a, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x3, 0x2, 0x2, 
       0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 
       0x6d, 0xf, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x9, 0x2, 0x2, 0x2, 0x6f, 
       0x11, 0x3, 0x2, 0x2, 0x2, 0x70, 0x74, 0x7, 0xa, 0x2, 0x2, 0x71, 0x73, 
       0x7, 0xe, 0x2, 0x2, 0x72, 0x71, 0x3, 0x2, 0x2, 0x2, 0x73, 0x76, 0x3, 
       0x2, 0x2, 0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x3, 0x2, 
       0x2, 0x2, 0x75, 0x77, 0x3, 0x2, 0x2, 0x2, 0x76, 0x74, 0x3, 0x2, 0x2, 
       0x2, 0x77, 0x78, 0x5, 0x14, 0xb, 0x2, 0x78, 0x13, 0x3, 0x2, 0x2, 
       0x2, 0x79, 0x7a, 0x7, 0x5, 0x2, 0x2, 0x7a, 0x7d, 0x5, 0x16, 0xc, 
       0x2, 0x7b, 0x7d, 0x5, 0xa, 0x6, 0x2, 0x7c, 0x79, 0x3, 0x2, 0x2, 0x2, 
       0x7c, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x15, 0x3, 0x2, 0x2, 0x2, 0x7e, 
       0x7f, 0x7, 0xb, 0x2, 0x2, 0x7f, 0x80, 0x7, 0x9, 0x2, 0x2, 0x80, 0x81, 
       0x7, 0xd, 0x2, 0x2, 0x81, 0x82, 0x7, 0x9, 0x2, 0x2, 0x82, 0x83, 0x7, 
       0xc, 0x2, 0x2, 0x83, 0x17, 0x3, 0x2, 0x2, 0x2, 0x12, 0x1c, 0x1f, 
       0x24, 0x2b, 0x2e, 0x30, 0x35, 0x40, 0x48, 0x4f, 0x54, 0x60, 0x65, 
       0x6c, 0x74, 0x7c, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

PRLParser::Initializer PRLParser::_init;
