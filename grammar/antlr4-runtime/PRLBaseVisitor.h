
// Generated from /Users/andreacolledan/Projects/pattern-rewriting-language/grammar/PRL.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "PRLVisitor.h"


/**
 * This class provides an empty implementation of PRLVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  PRLBaseVisitor : public PRLVisitor {
public:

  virtual antlrcpp::Any visitProg(PRLParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSymbolSection(PRLParser::SymbolSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRuleSection(PRLParser::RuleSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRewritingRule(PRLParser::RewritingRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPattern(PRLParser::PatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrow(PRLParser::ArrowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRow(PRLParser::RowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSymbol(PRLParser::SymbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInitialStateSection(PRLParser::InitialStateSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntensionalInitialState(PRLParser::IntensionalInitialStateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExtensionalInitialState(PRLParser::ExtensionalInitialStateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShape(PRLParser::ShapeContext *ctx) override {
    return visitChildren(ctx);
  }


};

