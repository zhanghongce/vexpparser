%require "3.0"
%language "c++"
%verbose
%locations
%define api.value.type variant
%define api.token.constructor
%define api.token.prefix {TOK_}
%define parse.error verbose
%define parse.trace

%code requires{
  #include <vexp.h>
}

%{
  typedef VExprAst::VExprAstPtr VExprAstPtr;
%}

/* Operators Precedence */

%token <voperator> STAR
%token <voperator> PLUS
%token <voperator> MINUS
%token <voperator> ASL     
%token <voperator> ASR     
%token <voperator> LSL     
%token <voperator> LSR     
%token <voperator> DIV     
%token <voperator> POW     
%token <voperator> MOD     
%token <voperator> GTE     
%token <voperator> LTE     
%token <voperator> GT      
%token <voperator> LT      
%token <voperator> L_NEG   
%token <voperator> L_AND   
%token <voperator> L_OR    
%token <voperator> C_EQ    
%token <voperator> L_EQ    
%token <voperator> C_NEQ   
%token <voperator> L_NEQ   
%token <voperator> B_NEG   
%token <voperator> B_AND   
%token <voperator> B_OR    
%token <voperator> B_XOR   
%token <voperator> B_EQU   
%token <voperator> B_NAND  
%token <voperator> B_NOR   
%token <voperator> TERNARY 
%token <voperator> AT 

%token OPEN_SQ_BRACKET
%token CLOSE_SQ_BRACKET
%token OPEN_BRACKET
%token CLOSE_BRACKET
%token HASH
%token OPEN_SQ_BRACE
%token CLOSE_SQ_BRACE
%token COMMA
%token COLON
%token BIN_BASE 
%token HEX_BASE 
%token OCT_BASE
%token DEC_BASE 
%token IDX_PRT_SEL_PLUS
%token IDX_PRT_SEL_MINUS
%token ATTRIBUTE_START
%token ATTRIBUTE_END
%token EQ
%token DOT

%token <std::string> SIMPLE_ID
%token <std::string> ESCAPED_ID
%token <std::string> MACRO_IDENTIFIER
%token <std::string> NUM_REAL
%token <std::string> BIN_VALUE
%token <std::string> HEX_VALUE
%token <std::string> OCT_VALUE
%token <std::string> UNSIGNED_NUMBER
%token <std::string> STRING


%nterm<VExprAst::VExprAstPtr> expression primary conditional_expression number function_call
%nterm<VExprAst::VExprAstPtr> concatenation multiple_concatenation
%nterm<voperator> unary_operator
%nterm<Attribute> attribute_instances list_of_attribute_instances attr_specs
%nterm<std::string> unsigned_number
%nterm<std::string> hierarchical_identifier_special_name text_macro_usage
%nterm<std::string> identifier simple_identifier escaped_identifier attr_name
%nterm<std::string> string
%nterm<std::vector<std::string>> hierarchical_identifier
%nterm<VExprAst::VExprAstPtrVec> expressions

/* Operator Precedence */


%precedence  COLON                 /* Lowest Precedence. */
%right  TERNARY
%left   L_OR
%left   L_AND
%left   B_OR B_NOR
%left   B_EQU B_XOR
%left   B_NAND B_AND
%left   L_EQ C_EQ L_NEQ C_NEQ
%left   GT LT GTE LTE
%left   LSL LSR ASR ASL
%left   PLUS MINUS
%left   STAR DIV MOD
%left   POW
%nonassoc AT                    /* Runtime error */
/* turn out the followings are not necessary */
/* %left   OPEN_BRACKET */
/* %left   OPEN_SQ_BRACKET */
%right  L_NEG B_NEG            /* Highest Precedence. */


%%


expression :
  primary {
    $$ = ast_new_expression_primary($1);
  }
| unary_operator attribute_instances primary{
    $$ = ast_new_unary_expression($3,$1,$2, AST_FALSE);
  }
| expression AT  attribute_instances expression{
    // this is the A@B shortcut
  }
| expression PLUS  attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression MINUS attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression STAR  attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression DIV   attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression MOD   attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression L_EQ  attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression L_NEQ attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression C_EQ  attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression C_NEQ attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression L_AND attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression L_OR  attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression POW   attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression LT    attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression LTE   attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression GT    attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression GTE   attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression B_AND attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression B_OR  attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression B_XOR attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression B_NOR attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression B_NAND attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression B_EQU attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression LSR   attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression LSL   attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression ASR   attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| expression ASL   attribute_instances expression{
    $$ = ast_new_binary_expression($1,$4,$2,$3,AST_FALSE);
  }
| conditional_expression {$$=$1;}

| function_call {
      $$ = ast_new_primary_function_call($1);
  }

;



/* A.8.3 Expressions */

conditional_expression : 
  expression TERNARY attribute_instances expression COLON expression{
    $$ = ast_new_conditional_expression($1,$4,$6,$3);
  }

;


primary :
  number{
      $$ = ast_new_primary(PRIMARY_NUMBER);
      $$ -> value.number = $1;
  }
| hierarchical_identifier {
  
  }
| primary sq_bracket_expression {
  
  }
| string {$$ = ast_new_string_expression($1);}
| hierarchical_identifier_special_name {
  // 
}
| concatenation{
      $$ = ast_new_primary(PRIMARY_CONCATENATION);
      $$ -> value.concatenation = $1;
  }
| multiple_concatenation{
      $$ = ast_new_primary(PRIMARY_CONCATENATION);
      $$ -> value.concatenation = $1;
  }
| OPEN_BRACKET expression CLOSE_BRACKET{
   // this is also the sub-()
      $$ = ast_new_primary(PRIMARY_MINMAX_EXP);
      $$ -> value.minmax = $2;
  }
;



hierarchical_identifier_special_name :
 HASH SIMPLE_ID HASH {
  /* this is #a# */
  }
;


/* A.8.1 Concatenations */

concatenation : 
  OPEN_SQ_BRACE expressions CLOSE_SQ_BRACE{
  }
;


multiple_concatenation :
  OPEN_SQ_BRACE expression concatenation CLOSE_SQ_BRACE{
    $$ = $3;
    $$ -> repeat = $2; // you need to change this to use REPEAT operator // check here to be constant?
  }
;


number :
  NUM_REAL{
    $$ = ast_new_number(BASE_DECIMAL,REP_BITS,$1);
  }
| BIN_BASE BIN_VALUE {
    $$ = ast_new_number(BASE_BINARY, REP_BITS, $2);
}
| HEX_BASE HEX_VALUE {
    $$ = ast_new_number(BASE_HEX, REP_BITS, $2);
}
| OCT_BASE OCT_VALUE {
    $$ = ast_new_number(BASE_OCTAL, REP_BITS, $2);
}
| DEC_BASE UNSIGNED_NUMBER{
    $$ = ast_new_number(BASE_DECIMAL, REP_BITS, $2);
}
| UNSIGNED_NUMBER BIN_BASE BIN_VALUE {
    $$ = ast_new_number(BASE_BINARY, REP_BITS, $3);
    $$->width = ast_string_to_unsigned_number($1);
}
| UNSIGNED_NUMBER HEX_BASE HEX_VALUE {
    $$ = ast_new_number(BASE_HEX, REP_BITS, $3);
    $$->width = ast_string_to_unsigned_number($1);
}
| UNSIGNED_NUMBER OCT_BASE OCT_VALUE {
    $$ = ast_new_number(BASE_OCTAL, REP_BITS, $3);
    $$->width = ast_string_to_unsigned_number($1);
}
| UNSIGNED_NUMBER DEC_BASE UNSIGNED_NUMBER{
    $$ = ast_new_number(BASE_DECIMAL, REP_BITS, $3);
    $$->width = ast_string_to_unsigned_number($1);
}
| unsigned_number {$$ = $1;}
;


unsigned_number :
  UNSIGNED_NUMBER {
    $$ = ast_new_number(BASE_DECIMAL, REP_BITS, $1);
  }
;


function_call : hierarchical_identifier
 attribute_instances OPEN_BRACKET expressions CLOSE_BRACKET{
    $$ = ast_new_function_call($1,AST_FALSE,AST_FALSE,$2,$4);
 }
 |  hierarchical_identifier
 attribute_instances OPEN_BRACKET CLOSE_BRACKET {
   // allow no parameters
 }
;


expressions :
  expression {
   $$ = VExprAst::VExprAstPtrVec();
   $$.push_back($1);
  }
| expressions COMMA expression{
  $$ = $1;
  ($$).push_back($3);
  }
;



sq_bracket_expression :
  OPEN_SQ_BRACKET expression CLOSE_SQ_BRACKET{
    // create one and replace as needed
  }
| OPEN_SQ_BRACKET expression COLON  expression CLOSE_SQ_BRACKET{
  }
| OPEN_SQ_BRACKET expression IDX_PRT_SEL_PLUS expression CLOSE_SQ_BRACKET{
  }
| OPEN_SQ_BRACKET expression IDX_PRT_SEL_MINUS expression CLOSE_SQ_BRACKET{
      // $2 $4
  }
;



string : STRING;

/* A.9.1 Attributes */

attribute_instances : {$$=NULL;}
                    | list_of_attribute_instances {$$=$1;}
                    ;

list_of_attribute_instances : 
  ATTRIBUTE_START attr_specs ATTRIBUTE_END {
      
  }
| ATTRIBUTE_START attr_specs ATTRIBUTE_END list_of_attribute_instances{

  }
;

attr_specs : { /*make empty one*/ }
           | attr_name EQ expression {
               // make new one
           }
           | attr_name EQ expression COMMA attr_specs {
               // Append the new item to the existing list and return.
           }
           ;


attr_name : identifier {$$=$1;};


hierarchical_identifier : 
  simple_identifier {
      $$ = $1;
  }
| hierarchical_identifier DOT simple_identifier{
  // text_macro_usage
      $$ = ast_append_identifier($1,$3);
  }
| hierarchical_identifier DOT escaped_identifier{
      $$ = ast_append_identifier($1,$3);
  }
;




identifier : 
  simple_identifier  {$$=$1;}
| escaped_identifier {$$=$1;}
| text_macro_usage {$$=$1;}
;


escaped_identifier  : ESCAPED_ID {
    $$=$1;
};



simple_identifier: 
  SIMPLE_ID {
    $$ = VExprAst::MakeVar($1);
}
;


/* 19.0 Compiler Directives */


text_macro_usage : MACRO_IDENTIFIER {
  
};



/* A.8.6 Operators */

unary_operator : PLUS    {$$ = $1;}
               | MINUS   {$$ = $1;}
               | L_NEG   {$$ = $1;}
               | B_NEG   {$$ = $1;}
               | B_AND   {$$ = $1;}
               | B_NAND  {$$ = $1;}
               | B_OR    {$$ = $1;}
               | B_NOR   {$$ = $1;}
               | B_XOR   {$$ = $1;}
               | B_EQU   {$$ = $1;}
               ;


%%

