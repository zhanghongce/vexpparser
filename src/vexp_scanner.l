%{
#include <verilogparser/verilog_ast.h>
    #include "verilog_parser.tab.h"
    
#include <verilogparser/verilog_preprocessor.h>

    //! Stores all information needed for the preprocessor.
    verilog_preprocessor_context * yy_preproc;

    #define EMIT_TOKEN(x) yy_preproc -> token_count ++; \
                          if(yy_preproc -> emit) {      \
                              return x;                 \
                          }
%}

%option yylineno
%option nodefault 
%option noyywrap 
%option nounistd

/* Single character tokens */

NEWLINE             "\n"|"\r\n"
SPACE               " "
TAB                 "\t"

AT                  "@"
COMMA               ","
HASH                "#"
DOT                 "."
EQ                  "="
COLON               ":"
IDX_PRT_SEL         "+:"|"-:"
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

%%
{ATTRIBUTE_START}      {EMIT_TOKEN(ATTRIBUTE_START);}
{ATTRIBUTE_END}        {EMIT_TOKEN(ATTRIBUTE_END);}

{COMMENT_LINE}         {/*EMIT_TOKEN(COMMENT_LINE); IGNORE */}
{COMMENT_BEGIN}        {BEGIN(in_comment);                    ;}

<in_comment>.|\n       {/* IGNORE                            */}
<in_comment>{COMMENT_END} {BEGIN(INITIAL);                     }


{AT}                   {EMIT_TOKEN(AT);}
{COMMA}                {EMIT_TOKEN(COMMA);}
{HASH}                 {EMIT_TOKEN(HASH);}
{DOT}                  {EMIT_TOKEN(DOT);}
{EQ}                   {yylval.operator = OPERATOR_L_EQ; EMIT_TOKEN(EQ);}
{COLON}                {EMIT_TOKEN(COLON);}
{IDX_PRT_SEL}          {EMIT_TOKEN(IDX_PRT_SEL);}
{SEMICOLON}            {EMIT_TOKEN(SEMICOLON);}
{OPEN_BRACKET}         {EMIT_TOKEN(OPEN_BRACKET);}
{CLOSE_BRACKET}        {EMIT_TOKEN(CLOSE_BRACKET);}
{OPEN_SQ_BRACKET}      {EMIT_TOKEN(OPEN_SQ_BRACKET);}
{CLOSE_SQ_BRACKET}     {EMIT_TOKEN(CLOSE_SQ_BRACKET);}
{OPEN_SQ_BRACE}        {EMIT_TOKEN(OPEN_SQ_BRACE);}
{CLOSE_SQ_BRACE}       {EMIT_TOKEN(CLOSE_SQ_BRACE);}
{STAR}                 {yylval.operator=OPERATOR_STAR   ; EMIT_TOKEN(STAR);}
{PLUS}                 {yylval.operator=OPERATOR_PLUS   ; EMIT_TOKEN(PLUS);}
{MINUS}                {yylval.operator=OPERATOR_MINUS  ; EMIT_TOKEN(MINUS);}
{ASL}                  {yylval.operator=OPERATOR_ASL    ; EMIT_TOKEN(ASL);}
{ASR}                  {yylval.operator=OPERATOR_ASR    ; EMIT_TOKEN(ASR);}
{LSL}                  {yylval.operator=OPERATOR_LSL    ; EMIT_TOKEN(LSL);}
{LSR}                  {yylval.operator=OPERATOR_LSR    ; EMIT_TOKEN(LSR);}
{DIV}                  {yylval.operator=OPERATOR_DIV    ; EMIT_TOKEN(DIV);}
{POW}                  {yylval.operator=OPERATOR_POW    ; EMIT_TOKEN(POW);}
{MOD}                  {yylval.operator=OPERATOR_MOD    ; EMIT_TOKEN(MOD);}
{GTE}                  {yylval.operator=OPERATOR_GTE    ; EMIT_TOKEN(GTE);}
{LTE}                  {yylval.operator=OPERATOR_LTE    ; EMIT_TOKEN(LTE);}
{GT}                   {yylval.operator=OPERATOR_GT     ; EMIT_TOKEN(GT);}
{LT}                   {yylval.operator=OPERATOR_LT     ; EMIT_TOKEN(LT);}
{L_NEG}                {yylval.operator=OPERATOR_L_NEG  ; EMIT_TOKEN(L_NEG);}
{L_AND}                {yylval.operator=OPERATOR_L_AND  ; EMIT_TOKEN(L_AND);}
{L_OR}                 {yylval.operator=OPERATOR_L_OR   ; EMIT_TOKEN(L_OR);}
{C_EQ}                 {yylval.operator=OPERATOR_C_EQ   ; EMIT_TOKEN(C_EQ);}
{L_EQ}                 {yylval.operator=OPERATOR_L_EQ   ; EMIT_TOKEN(L_EQ);}
{C_NEQ}                {yylval.operator=OPERATOR_C_NEQ  ; EMIT_TOKEN(C_NEQ);}
{L_NEQ}                {yylval.operator=OPERATOR_L_NEQ  ; EMIT_TOKEN(L_NEQ);}
{B_NEG}                {yylval.operator=OPERATOR_B_NEG  ; EMIT_TOKEN(B_NEG);}
{B_AND}                {yylval.operator=OPERATOR_B_AND  ; EMIT_TOKEN(B_AND);}
{B_OR}                 {yylval.operator=OPERATOR_B_OR   ; EMIT_TOKEN(B_OR);}
{B_XOR}                {yylval.operator=OPERATOR_B_XOR  ; EMIT_TOKEN(B_XOR);}
{B_EQU}                {yylval.operator=OPERATOR_B_EQU  ; EMIT_TOKEN(B_EQU);}
{B_NAND}               {yylval.operator=OPERATOR_B_NAND ; EMIT_TOKEN(B_NAND);}
{B_NOR}                {yylval.operator=OPERATOR_B_NOR  ; EMIT_TOKEN(B_NOR);}
{TERNARY}              {yylval.operator=OPERATOR_TERNARY; EMIT_TOKEN(TERNARY);}

{BASE_DECIMAL}         {EMIT_TOKEN(DEC_BASE);}
{BASE_HEX}             {BEGIN(in_hex_val); EMIT_TOKEN(HEX_BASE);}
{BASE_OCTAL}           {BEGIN(in_oct_val); EMIT_TOKEN(OCT_BASE);}
{BASE_BINARY}          {BEGIN(in_bin_val); EMIT_TOKEN(BIN_BASE);}

<in_bin_val>{BIN_VALUE} {BEGIN(INITIAL); yylval.string = ast_strdup(yytext); EMIT_TOKEN(BIN_VALUE);}
<in_oct_val>{OCT_VALUE} {BEGIN(INITIAL); yylval.string = ast_strdup(yytext); EMIT_TOKEN(OCT_VALUE);}
<in_hex_val>{HEX_VALUE} {BEGIN(INITIAL); yylval.string = ast_strdup(yytext); EMIT_TOKEN(HEX_VALUE);}

{NUM_REAL}             {yylval.string=ast_strdup(yytext);EMIT_TOKEN(NUM_REAL);}
{NUM_UNSIGNED}         {yylval.string=ast_strdup(yytext);EMIT_TOKEN(UNSIGNED_NUMBER);}

{MACRO_IDENTIFIER}     {
    yylval.identifier = ast_new_identifier(yytext,yylineno); 
    EMIT_TOKEN(MACRO_IDENTIFIER);
}

{SYSTEM_ID}            {
    yylval.identifier = ast_new_identifier(yytext,yylineno); 
    EMIT_TOKEN(SYSTEM_ID);
}
{ESCAPED_ID}           {
    yylval.identifier = ast_new_identifier(yytext,yylineno); 
    EMIT_TOKEN(ESCAPED_ID);
}
{SIMPLE_ID}            {
    yylval.identifier = ast_new_identifier(yytext,yylineno); 
    EMIT_TOKEN(SIMPLE_ID);
}

{STRING}               {yylval.string= ast_strdup(yytext);EMIT_TOKEN(STRING);}

<*>{NEWLINE}              {/*EMIT_TOKEN(NEWLINE); IGNORE */   }
<*>{SPACE}                {/*EMIT_TOKEN(SPACE);   IGNORE */   }
<*>{TAB}                  {/*EMIT_TOKEN(TAB);     IGNORE */   }

.                      {
    EMIT_TOKEN(ANY);
}
