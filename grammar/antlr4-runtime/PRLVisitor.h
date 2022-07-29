
// Generated from /Users/andreacolledan/Projects/pattern-rewriting-language/grammar/PRL.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "PRLParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PRLParser.
 */
class  PRLVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PRLParser.
   */
    virtual antlrcpp::Any visitProg(PRLParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitSymbolSection(PRLParser::SymbolSectionContext *context) = 0;

    virtual antlrcpp::Any visitRuleSection(PRLParser::RuleSectionContext *context) = 0;

    virtual antlrcpp::Any visitRewritingRule(PRLParser::RewritingRuleContext *context) = 0;

    virtual antlrcpp::Any visitPattern(PRLParser::PatternContext *context) = 0;

    virtual antlrcpp::Any visitArrow(PRLParser::ArrowContext *context) = 0;

    virtual antlrcpp::Any visitRow(PRLParser::RowContext *context) = 0;

    virtual antlrcpp::Any visitSymbol(PRLParser::SymbolContext *context) = 0;

    virtual antlrcpp::Any visitInitialStateSection(PRLParser::InitialStateSectionContext *context) = 0;

    virtual antlrcpp::Any visitIntensionalInitialState(PRLParser::IntensionalInitialStateContext *context) = 0;

    virtual antlrcpp::Any visitExtensionalInitialState(PRLParser::ExtensionalInitialStateContext *context) = 0;

    virtual antlrcpp::Any visitShape(PRLParser::ShapeContext *context) = 0;


};

