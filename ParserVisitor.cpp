#include "ParserVisitor.hpp"
#include "Rule.hpp"
#include "Cartridge.hpp"

antlrcpp::Any ParserVisitor::visitProg(PRLParser::ProgContext *ctx) {
    Cartridge cartridge;
    std::vector<Symbol> symbols = visitSymbolSection(ctx->symbolSection()).as<std::vector<Symbol>>();
    for (Symbol symbol : symbols) {
        cartridge.defineSymbol(symbol);
    }
    std::vector<Rule> rules = visitRuleSection(ctx->ruleSection()).as<std::vector<Rule>>();
    for (Rule rule : rules) {
        cartridge.defineRule(rule);
    }
    Pattern startingField = visitInitialStateSection(ctx->initialStateSection()).as<Pattern>();
    cartridge.setStartingField(startingField);
    return cartridge;
}

antlrcpp::Any ParserVisitor::visitSymbolSection(PRLParser::SymbolSectionContext *ctx) {
    std::vector<Symbol> symbols;
    for(auto symbolToken : ctx->SYMBOL_ID()) {
        Symbol symbol(stoc(symbolToken->getText()));
        symbols.push_back(symbol);
    }
    return symbols;
}

antlrcpp::Any ParserVisitor::visitRuleSection(PRLParser::RuleSectionContext *ctx) {
    std::vector<Rule> rules;
    for (auto ruleNode : ctx->rewritingRule()) {
        rules.push_back(visitRewritingRule(ruleNode).as<Rule>());
    }
    return rules;
}

antlrcpp::Any ParserVisitor::visitRewritingRule(PRLParser::RewritingRuleContext *ctx) {
    Pattern lhs = visitPattern(ctx->lhs).as<Pattern>();
    Pattern rhs = visitPattern(ctx->rhs).as<Pattern>();
    int uses = visitArrow(ctx->arrow()).as<int>();
    Rule rule(lhs, rhs, uses);
    return rule;
}

antlrcpp::Any ParserVisitor::visitArrow(PRLParser::ArrowContext *ctx) {
    if (ctx->NN_NUMBER()) {
        return std::stoi(ctx->NN_NUMBER()->getText());
    } else {
        return -1;
    }
}

antlrcpp::Any ParserVisitor::visitPattern(PRLParser::PatternContext *ctx) {
    std::vector<std::vector<Symbol>> rows;
    for (auto rowNode : ctx->row()) {
        rows.push_back(visitRow(rowNode).as<std::vector<Symbol>>());
    }
    Pattern pattern(rows);
    return pattern;
}

antlrcpp::Any ParserVisitor::visitRow(PRLParser::RowContext *ctx) {
    std::vector<Symbol> symbols;
    for (auto symbolNode : ctx->symbol()) {
        symbols.push_back(visitSymbol(symbolNode).as<Symbol>());
    }
    return symbols;
}

antlrcpp::Any ParserVisitor::visitSymbol(PRLParser::SymbolContext *ctx) {
    if(ctx->SYMBOL_WC()) {
        return Symbol();
    } else {
        return Symbol(stoc(ctx->SYMBOL_ID()->getText()));
    }
}

antlrcpp::Any ParserVisitor::visitInitialStateSection(PRLParser::InitialStateSectionContext *ctx) {
    return visit(ctx->initialState()).as<Pattern>();
}

antlrcpp::Any ParserVisitor::visitIntensionalInitialState(PRLParser::IntensionalInitialStateContext *ctx) {
    Symbol startingSymbol(stoc(ctx->SYMBOL_ID()->getText()));
    std::pair<int,int> shape = visitShape(ctx->shape()).as<std::pair<int,int>>();
    return makePatternFromIntension(startingSymbol, shape.first, shape.second);
}

antlrcpp::Any ParserVisitor::visitExtensionalInitialState(PRLParser::ExtensionalInitialStateContext *ctx) {
    return visitPattern(ctx->pattern()).as<Pattern>();
}

antlrcpp::Any ParserVisitor::visitShape(PRLParser::ShapeContext *ctx) {
    int height = std::stoi(ctx->height->getText());
    int width = std::stoi(ctx->width->getText());
    std::pair<int,int> shape(height, width);
    return shape;
}

char ParserVisitor::stoc(std::string s) {
    assert(s.size() == 1);
    return s[0];
}

Pattern ParserVisitor::makePatternFromIntension(Symbol symbol, int height, int width) {
    std::vector<std::vector<Symbol>> rows;
    for(int i = 0; i < height; i++) {
        std::vector<Symbol> row;
        for(int j = 0; j < width; j++) {
            row.push_back(symbol);
        }
        rows.push_back(row);
    }
    Pattern pattern(rows);
    return pattern;
}