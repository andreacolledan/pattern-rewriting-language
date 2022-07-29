#pragma once

#include "grammar/antlr4-runtime/PRLBaseVisitor.h"
#include "Pattern.hpp"

class ParserVisitor : PRLBaseVisitor {
    public:
        antlrcpp::Any visitProg(PRLParser::ProgContext *ctx);
        antlrcpp::Any visitSymbolSection(PRLParser::SymbolSectionContext *ctx);
        antlrcpp::Any visitRuleSection(PRLParser::RuleSectionContext *ctx);
        antlrcpp::Any visitRewritingRule(PRLParser::RewritingRuleContext *ctx);
        antlrcpp::Any visitArrow(PRLParser::ArrowContext *ctx);
        antlrcpp::Any visitPattern(PRLParser::PatternContext *ctx);
        antlrcpp::Any visitRow(PRLParser::RowContext *ctx);
        antlrcpp::Any visitSymbol(PRLParser::SymbolContext *ctx);
        antlrcpp::Any visitInitialStateSection(PRLParser::InitialStateSectionContext *ctx);
        antlrcpp::Any visitIntensionalInitialState(PRLParser::IntensionalInitialStateContext *ctx);
        antlrcpp::Any visitExtensionalInitialState(PRLParser::ExtensionalInitialStateContext *ctx);
        antlrcpp::Any visitShape(PRLParser::ShapeContext *ctx);
    
    private:
        static char stoc(std::string s);
        static Pattern makePatternFromIntension(Symbol symbol, int height, int width);
};