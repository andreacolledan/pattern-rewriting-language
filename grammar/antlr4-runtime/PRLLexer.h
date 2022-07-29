
// Generated from /Users/andreacolledan/Projects/pattern-rewriting-language/grammar/PRL.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  PRLLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, SYMBOL_ID = 3, SYMBOL_WC = 4, SYMBOL_KW = 5, RULES_KW = 6, 
    NN_NUMBER = 7, IS_KW = 8, LPAR = 9, RPAR = 10, COMMA = 11, BR = 12, 
    WS = 13
  };

  explicit PRLLexer(antlr4::CharStream *input);
  ~PRLLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

