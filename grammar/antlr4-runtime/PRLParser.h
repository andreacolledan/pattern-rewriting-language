
// Generated from /Users/andreacolledan/Projects/pattern-rewriting-language/grammar/PRL.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  PRLParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, SYMBOL_ID = 3, SYMBOL_WC = 4, SYMBOL_KW = 5, RULES_KW = 6, 
    NN_NUMBER = 7, IS_KW = 8, LPAR = 9, RPAR = 10, COMMA = 11, BR = 12, 
    WS = 13
  };

  enum {
    RuleProg = 0, RuleSymbolSection = 1, RuleRuleSection = 2, RuleRewritingRule = 3, 
    RulePattern = 4, RuleArrow = 5, RuleRow = 6, RuleSymbol = 7, RuleInitialStateSection = 8, 
    RuleInitialState = 9, RuleShape = 10
  };

  explicit PRLParser(antlr4::TokenStream *input);
  ~PRLParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgContext;
  class SymbolSectionContext;
  class RuleSectionContext;
  class RewritingRuleContext;
  class PatternContext;
  class ArrowContext;
  class RowContext;
  class SymbolContext;
  class InitialStateSectionContext;
  class InitialStateContext;
  class ShapeContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolSectionContext *symbolSection();
    antlr4::tree::TerminalNode *EOF();
    InitialStateSectionContext *initialStateSection();
    std::vector<antlr4::tree::TerminalNode *> BR();
    antlr4::tree::TerminalNode* BR(size_t i);
    RuleSectionContext *ruleSection();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgContext* prog();

  class  SymbolSectionContext : public antlr4::ParserRuleContext {
  public:
    SymbolSectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SYMBOL_KW();
    std::vector<antlr4::tree::TerminalNode *> SYMBOL_ID();
    antlr4::tree::TerminalNode* SYMBOL_ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SymbolSectionContext* symbolSection();

  class  RuleSectionContext : public antlr4::ParserRuleContext {
  public:
    RuleSectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RULES_KW();
    std::vector<antlr4::tree::TerminalNode *> BR();
    antlr4::tree::TerminalNode* BR(size_t i);
    std::vector<RewritingRuleContext *> rewritingRule();
    RewritingRuleContext* rewritingRule(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RuleSectionContext* ruleSection();

  class  RewritingRuleContext : public antlr4::ParserRuleContext {
  public:
    PRLParser::PatternContext *lhs = nullptr;
    PRLParser::PatternContext *rhs = nullptr;
    RewritingRuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArrowContext *arrow();
    std::vector<PatternContext *> pattern();
    PatternContext* pattern(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RewritingRuleContext* rewritingRule();

  class  PatternContext : public antlr4::ParserRuleContext {
  public:
    PatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RowContext *> row();
    RowContext* row(size_t i);
    std::vector<antlr4::tree::TerminalNode *> BR();
    antlr4::tree::TerminalNode* BR(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PatternContext* pattern();

  class  ArrowContext : public antlr4::ParserRuleContext {
  public:
    ArrowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NN_NUMBER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrowContext* arrow();

  class  RowContext : public antlr4::ParserRuleContext {
  public:
    RowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SymbolContext *> symbol();
    SymbolContext* symbol(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RowContext* row();

  class  SymbolContext : public antlr4::ParserRuleContext {
  public:
    SymbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SYMBOL_ID();
    antlr4::tree::TerminalNode *SYMBOL_WC();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SymbolContext* symbol();

  class  InitialStateSectionContext : public antlr4::ParserRuleContext {
  public:
    InitialStateSectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IS_KW();
    InitialStateContext *initialState();
    std::vector<antlr4::tree::TerminalNode *> BR();
    antlr4::tree::TerminalNode* BR(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InitialStateSectionContext* initialStateSection();

  class  InitialStateContext : public antlr4::ParserRuleContext {
  public:
    InitialStateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    InitialStateContext() = default;
    void copyFrom(InitialStateContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExtensionalInitialStateContext : public InitialStateContext {
  public:
    ExtensionalInitialStateContext(InitialStateContext *ctx);

    PatternContext *pattern();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntensionalInitialStateContext : public InitialStateContext {
  public:
    IntensionalInitialStateContext(InitialStateContext *ctx);

    antlr4::tree::TerminalNode *SYMBOL_ID();
    ShapeContext *shape();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  InitialStateContext* initialState();

  class  ShapeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *height = nullptr;
    antlr4::Token *width = nullptr;
    ShapeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<antlr4::tree::TerminalNode *> NN_NUMBER();
    antlr4::tree::TerminalNode* NN_NUMBER(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShapeContext* shape();


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

