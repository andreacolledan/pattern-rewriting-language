grammar PRL;

/*
Whitespace policy:
    - trailing whitespace is allowed
    - whitespace between tokens is allowed
    - leading whitespace is forbidden unless the line is the n-th (n != 1) line of a pattern
    - Whitespace between pattern symbols is forbidden
 */

prog : symbolSection BR+//symbol declaration
        (ruleSection? BR+ initialStateSection | initialStateSection BR+ ruleSection?) //both orders are acceptable
        BR* EOF; //possible trailing line breaks, then end file

symbolSection : SYMBOL_KW SYMBOL_ID (',' SYMBOL_ID)*;

ruleSection : RULES_KW BR BR* rewritingRule (BR+ rewritingRule)*;
rewritingRule : lhs=pattern arrow rhs=pattern;
pattern : row (BR row)*;
arrow : '-' NN_NUMBER? '>';
row : symbol+;
symbol : SYMBOL_ID | SYMBOL_WC;

initialStateSection : IS_KW BR* initialState;
initialState : SYMBOL_ID  shape #intensionalInitialState
                | pattern       #extensionalInitialState;
shape: LPAR  height=NN_NUMBER  COMMA  width=NN_NUMBER  RPAR ;


//LEXER

SYMBOL_ID : [a-zA-Z.;_@#+^?'=|!"£$%&~:\-];      //Symbols
SYMBOL_WC : '*';                                //Wildcard Symbol
SYMBOL_KW : 'Symbols';                          //Keyword for declaring a symbol

RULES_KW : 'Apply rules';       //Keyword to start rule declaration segment
NN_NUMBER : [1-9][0-9]*;        //Positive numbers, for quantities

IS_KW : 'Starting from';        //Keyword to start initial state declaration

LPAR : '(';
RPAR : ')';
COMMA : ',';

BR : [\n];                     //Line breaks
WS : [ \r\t]+ -> skip;         //Ignore whitespace