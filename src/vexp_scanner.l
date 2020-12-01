%{
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <cstring> // strerror
# include <string>
# include "driver.hh"
# include "parser.hh"
%}

%option noyywrap nounput noinput batch debug nounistd

/* Single character tokens */

NEWLINE             "\n"|"\r\n"
BLANK               [ \t\r]

AT                  "@"
COMMA               ","
HASH                "#"
DOT                 "."
EQ                  "="
COLON               ":"
IDX_PRT_SEL_PLUS    "+:"
IDX_PRT_SEL_MINUS   "-:"
SEMICOLON           ";"
OPEN_BRACKET        "\("
CLOSE_BRACKET       "\)"
OPEN_SQ_BRACKET     "\["
CLOSE_SQ_BRACKET    "\]"
OPEN_SQ_BRACE       "{"
CLOSE_SQ_BRACE      "}"


/* Tokens related to numbers */

EXP                 "e"|"E"
UNDERSCORE          "_"
SIGN                {PLUS}|{MINUS}
X                   "x"|"X"
Z                   "z"|"Z"|"?"

DIGIT_DECIMAL       [0-9]
DIGIT_DECMIAL_NZ    [1-9]
DIGIT_BINARY        [0-1]|{X}|{Z}
DIGIT_OCTAL         [0-7]|{X}|{Z}
DIGIT_HEX           [0-9a-fA-F]|{X}|{Z}

BASE_DECIMAL        '[sS]?[dD]
BASE_BINARY         '[sS]?[bB]
BASE_OCTAL          '[sS]?[oO]
BASE_HEX            '[sS]?[hH]

NUM_REAL_EXP        {NUM_UNSIGNED}({DOT}{NUM_UNSIGNED})?{EXP}({SIGN})?{NUM_UNSIGNED}

BIN_VALUE           {DIGIT_BINARY}({UNDERSCORE}|{DIGIT_BINARY})*
OCT_VALUE           {DIGIT_OCTAL}({UNDERSCORE}|{DIGIT_OCTAL})*
HEX_VALUE           {DIGIT_HEX}({UNDERSCORE}|{DIGIT_HEX})*

%x in_hex_val
%x in_oct_val
%x in_bin_val
%s in_number

NUM_REAL            {NUM_UNSIGNED}{DOT}{NUM_UNSIGNED}|{NUM_REAL_EXP}
NUM_UNSIGNED        {DIGIT_DECIMAL}({UNDERSCORE}|{DIGIT_DECIMAL})*

/* Identifiers */

SYSTEM_ID           \$[a-zA-Z0-9_\$]+
SIMPLE_ID           [a-zA-Z_][a-zA-Z0-9_$]*
ESCAPED_ID          \\{SIMPLE_ID}
MACRO_IDENTIFIER    `{SIMPLE_ID}

MACRO_TEXT          .*\n

%x in_define
%x in_define_t

/* Attributes */

ATTRIBUTE_START     \(\*
ATTRIBUTE_END       \*\)

/* Comments */
COMMENT_LINE        "//".*\n

COMMENT_BEGIN       "/*"
COMMENT_END         "*/"

%x in_comment

/* Strings */

STRING              \".*\"

/* Operators */

STAR                "\*"
PLUS                "+"
MINUS               "-"
ASL                 "<<<"
ASR                 ">>>"
LSL                 "<<"
LSR                 ">>"
DIV                 "/"
POW                 "**"
MOD                 "%"
GTE                 ">="
LTE                 "<="
GT                  ">"
LT                  "<"
L_NEG               "!"
L_AND               "&&"
L_OR                "||"
C_EQ                "==="
L_EQ                "=="
C_NEQ               "!=="
L_NEQ               "!="
B_NEG               "~"
B_AND               "&"
B_OR                "|"
B_XOR               "^"
B_EQU               "^~"|"~^"
B_NAND              "~&"
B_NOR               "~|"
TERNARY             "?"

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}

%%

%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = drv.location;
  // Code run each time yylex is called.
  loc.step ();
%}

{ATTRIBUTE_START}      { return yy::parser::make_ATTRIBUTE_START(loc);}
{ATTRIBUTE_END}        { return yy::parser::make_ATTRIBUTE_END(loc); }

{COMMENT_LINE}         { /* IGNORE */ }
{COMMENT_BEGIN}        {BEGIN(in_comment);                    ;}

<in_comment>.|\n       { /* IGNORE */ }
<in_comment>{COMMENT_END} {BEGIN(INITIAL);                     }


{AT}                   { return yy::parser::make_AT               ( voperator::AT, loc       ) ; /*this should be an operator*/ }
{COMMA}                { return yy::parser::make_COMMA            ( loc                      ) ;}
{HASH}                 { return yy::parser::make_HASH             ( loc                      ) ;}
{DOT}                  { return yy::parser::make_DOT              ( loc                      ) ;}
{COLON}                { return yy::parser::make_COLON            ( loc                      ) ;}
{IDX_PRT_SEL_PLUS}     { return yy::parser::make_IDX_PRT_SEL_PLUS ( loc                      ) ;}
{IDX_PRT_SEL_MINUS}    { return yy::parser::make_IDX_PRT_SEL_MINUS( loc                      ) ;}
{SEMICOLON}            { return yy::parser::make_SEMICOLON        ( loc                      ) ;}
{OPEN_BRACKET}         { return yy::parser::make_OPEN_BRACKET     ( loc                      ) ;}
{CLOSE_BRACKET}        { return yy::parser::make_CLOSE_BRACKET    ( loc                      ) ;}
{OPEN_SQ_BRACKET}      { return yy::parser::make_OPEN_SQ_BRACKET  ( loc                      ) ;}
{CLOSE_SQ_BRACKET}     { return yy::parser::make_CLOSE_SQ_BRACKET ( loc                      ) ;}
{OPEN_SQ_BRACE}        { return yy::parser::make_OPEN_SQ_BRACE    ( loc                      ) ;}
{CLOSE_SQ_BRACE}       { return yy::parser::make_CLOSE_SQ_BRACE   ( loc                      ) ;}
{STAR}                 { return yy::parser::make_STAR             ( voperator::STAR    , loc ) ;}
{PLUS}                 { return yy::parser::make_PLUS             ( voperator::PLUS    , loc ) ;}
{MINUS}                { return yy::parser::make_MINUS            ( voperator::MINUS   , loc ) ;}
{ASL}                  { return yy::parser::make_ASL              ( voperator::ASL     , loc ) ;}
{ASR}                  { return yy::parser::make_ASR              ( voperator::ASR     , loc ) ;}
{LSL}                  { return yy::parser::make_LSL              ( voperator::LSL     , loc ) ;}
{LSR}                  { return yy::parser::make_LSR              ( voperator::LSR     , loc ) ;}
{DIV}                  { return yy::parser::make_DIV              ( voperator::DIV     , loc ) ;}
{POW}                  { return yy::parser::make_POW              ( voperator::POW     , loc ) ;}
{MOD}                  { return yy::parser::make_MOD              ( voperator::MOD     , loc ) ;}
{GTE}                  { return yy::parser::make_GTE              ( voperator::GTE     , loc ) ;}
{LTE}                  { return yy::parser::make_LTE              ( voperator::LTE     , loc ) ;}
{GT}                   { return yy::parser::make_GT               ( voperator::GT      , loc ) ;}
{LT}                   { return yy::parser::make_LT               ( voperator::LT      , loc ) ;}
{L_NEG}                { return yy::parser::make_L_NEG            ( voperator::L_NEG   , loc ) ;}
{L_AND}                { return yy::parser::make_L_AND            ( voperator::L_AND   , loc ) ;}
{L_OR}                 { return yy::parser::make_L_OR             ( voperator::L_OR    , loc ) ;}
{C_EQ}                 { return yy::parser::make_C_EQ             ( voperator::C_EQ    , loc ) ;}
{L_EQ}                 { return yy::parser::make_L_EQ             ( voperator::L_EQ    , loc ) ;}
{C_NEQ}                { return yy::parser::make_C_NEQ            ( voperator::C_NEQ   , loc ) ;}
{L_NEQ}                { return yy::parser::make_L_NEQ            ( voperator::L_NEQ   , loc ) ;}
{B_NEG}                { return yy::parser::make_B_NEG            ( voperator::B_NEG   , loc ) ;}
{B_AND}                { return yy::parser::make_B_AND            ( voperator::B_AND   , loc ) ;}
{B_OR}                 { return yy::parser::make_B_OR             ( voperator::B_OR    , loc ) ;}
{B_XOR}                { return yy::parser::make_B_XOR            ( voperator::B_XOR   , loc ) ;}
{B_EQU}                { return yy::parser::make_B_EQU            ( voperator::B_EQU   , loc ) ;}
{B_NAND}               { return yy::parser::make_B_NAND           ( voperator::B_NAND  , loc ) ;}
{B_NOR}                { return yy::parser::make_B_NOR            ( voperator::B_NOR   , loc ) ;}
{TERNARY}              { return yy::parser::make_TERNAR           ( voperator::TERNARY , loc ) ;}
{EQ}                   { return yy::parser::make_EQ               ( loc                      ) ; /*this is just a symbol not OP*/ }

{BASE_DECIMAL}         {return yy::parser::make_DEC_BASE(loc);}
{BASE_HEX}             {BEGIN(in_hex_val); return yy::parser::make_HEX_BASE(loc);}
{BASE_OCTAL}           {BEGIN(in_oct_val); return yy::parser::make_OCT_BASE(loc);}
{BASE_BINARY}          {BEGIN(in_bin_val); return yy::parser::make_BIN_BASE(loc);}

<in_bin_val>{BIN_VALUE} {BEGIN(INITIAL); return yy::parser::make_BIN_VALUE(yytext,loc); }
<in_oct_val>{OCT_VALUE} {BEGIN(INITIAL); return yy::parser::make_OCT_VALUE(yytext,loc); }
<in_hex_val>{HEX_VALUE} {BEGIN(INITIAL); return yy::parser::make_HEX_VALUE(yytext,loc); }

{NUM_REAL}             { return yy::parser::make_NUM_REAL(yytext, loc); }
{NUM_UNSIGNED}         { return yy::parser::make_UNSIGNED_NUMBER(yytext, loc); }

{MACRO_IDENTIFIER}     {
    return yy::parser::make_MACRO_IDENTIFIER(yytext, loc);
}

{ESCAPED_ID}           {
    return yy::parser::make_ESCAPED_ID(yytext, loc);
}
{SIMPLE_ID}            {
    return yy::parser::make_SIMPLE_ID(yytext, loc);
}

{STRING}               { return yy::parser::make_STRING(yytext, loc);}

<*>{BLANK}+          { loc.step (); }
<*>{NEWLINE}+        { loc.lines (yyleng); loc.step (); }

<<EOF>>                { return yy::parser::make_EOF (loc);}
.                      {
    EMIT_TOKEN(ANY);
}
