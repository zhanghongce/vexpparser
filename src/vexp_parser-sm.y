%require "3.2"
%language "c++"
%verbose
%locations
%define api.value.type variant
%define api.token.constructor


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

/* Operator Precedence */


%right  TERNARY                 /* Lowest Precedence */
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
%right  L_NEG B_NEG    /* Highest Precedence. */





expression :
  primary {
    $$ = ast_new_expression_primary($1);
  }
| unary_operator attribute_instances primary{
    $$ = ast_new_unary_expression($3,$1,$2, AST_FALSE);
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
| string {$$ = ast_new_string_expression($1);}
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
| function_call{
      $$ = ast_new_primary_function_call($1);
  }
| hierarchical_identifier sq_bracket_expressions{
      $$ = ast_new_primary(PRIMARY_IDENTIFIER);
      $$ -> value.identifier = $1;
  }
| concatenation{
      $$ = ast_new_primary(PRIMARY_CONCATENATION);
      $$ -> value.concatenation = $1;
  }
| multiple_concatenation{
      $$ = ast_new_primary(PRIMARY_CONCATENATION);
      $$ -> value.concatenation = $1;
  }
| hierarchical_identifier{
      $$ = ast_new_primary(PRIMARY_IDENTIFIER);
      $$ -> value.identifier = $1;
  }
| OPEN_BRACKET mintypmax_expression CLOSE_BRACKET{
      $$ = ast_new_primary(PRIMARY_MINMAX_EXP);
      $$ -> value.minmax = $2;
  }
;


/* A.8.1 Concatenations */

concatenation : 
  OPEN_SQ_BRACE expression concatenation_cont{
    $$ = $3;
    ast_extend_concatenation($3,NULL,$2);
  }
;

concatenation_cont :
  CLOSE_SQ_BRACE {
      $$ = ast_new_empty_concatenation(CONCATENATION_EXPRESSION);
  }
| COMMA expression concatenation_cont{
      $$ = $3;
      ast_extend_concatenation($3,NULL,$2);
  }
;

multiple_concatenation :
  OPEN_SQ_BRACE expression concatenation CLOSE_SQ_BRACE{
    $$ = $3;
    $$ -> repeat = $2;
  }
;


mintypmax_expression :
  expression{
      $$ = ast_new_mintypmax_expression(NULL,$1,NULL);
  }
| expression COLON expression COLON expression{
      $$ = ast_new_mintypmax_expression($1,$3,$5);
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


function_call : hierarchical_function_identifier
 attribute_instances OPEN_BRACKET expressions CLOSE_BRACKET{
    $$ = ast_new_function_call($1,AST_FALSE,AST_FALSE,$2,$4);
 }
 |  hierarchical_function_identifier
 attribute_instances OPEN_BRACKET CLOSE_BRACKET {
   // allow no parameters
 }
;

hierarchical_function_identifier: hierarchical_identifier
    {$$=$1; $$ -> type = ID_FUNCTION;};


expressions :
  expression {
        $$ = ast_list_new();
        ast_list_append($$,$1);
  }
| expressions COMMA expression{
        $$ = $1;
        ast_list_append($$,$3);
  }
;


sq_bracket_expressions :
   sq_bracket_expression 
 | sq_bracket_expression sq_bracket_expressions
;


sq_bracket_expression :
  OPEN_SQ_BRACKET expression CLOSE_SQ_BRACKET{
      $$ = ast_list_new();
      ast_list_append($$,$2);
  }
| OPEN_SQ_BRACKET expression COLON  expression CLOSE_SQ_BRACKET{
      $$ = ast_list_new();
      ast_list_append($$,$2);
  }
| OPEN_SQ_BRACKET expression IDX_PRT_SEL expression %prec IDX_PRT_SEL CLOSE_SQ_BRACKET{
      $$ = ast_list_new();
      ast_list_append($$,$2);
  }
;



string : STRING;

/* A.9.1 Attributes */

attribute_instances : {$$=NULL;}
                    | list_of_attribute_instances {$$=$1;}
                    ;

list_of_attribute_instances : 
  ATTRIBUTE_START attr_specs ATTRIBUTE_END {
      $$ = $2;
  }
| attribute_instances ATTRIBUTE_START attr_specs ATTRIBUTE_END{
    if($1 != NULL){
        ast_append_attribute($1, $3);
        $$ = $1;
    } else {
        $$ = $3;
    }
  }
                            ;

attr_specs : {$$ = NULL;}
           | attr_spec {
               $$ = $1;
           }
           | attr_specs COMMA attr_spec {
               // Append the new item to the existing list and return.
               ast_append_attribute($1,$3);
               $$ = $1;
           }
           ;

attr_spec : attr_name EQ expression
                {$$ = ast_new_attributes($1,$3);}
          | attr_name 
                {$$ = ast_new_attributes($1, NULL);}
          ;

attr_name : identifier {$$=$1;};


hierarchical_identifier : 
  simple_identifier {
      $$ = $1;
  }
| simple_hierarchical_branch DOT simple_identifier{
  // text_macro_usage
      $$ = ast_append_identifier($1,$3);
  }
| simple_hierarchical_branch DOT escaped_identifier{
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


white_space : SPACE | TAB | NEWLINE;


simple_identifier: 
  SIMPLE_ID {
    $$ = $1;
}
;


/* 19.0 Compiler Directives */


text_macro_usage : MACRO_IDENTIFIER list_of_actual_arguments
                 | MACRO_IDENTIFIER
                 ;

list_of_actual_arguments : actual_argument
                         | list_of_actual_arguments COMMA actual_argument
                         ;

actual_argument : expression
                ; 




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


unary_module_path_operator  : L_NEG  {$$=$1;}
                            | B_NEG  {$$=$1;}
                            | B_AND  {$$=$1;}
                            | B_NAND {$$=$1;}
                            | B_OR   {$$=$1;}
                            | B_NOR  {$$=$1;}
                            | B_XOR  {$$=$1;}
                            | B_EQU  {$$=$1;}
                            ;

binary_module_path_operator : L_EQ   {$$=$1;}
                            | L_NEQ  {$$=$1;}
                            | L_AND  {$$=$1;}
                            | L_OR   {$$=$1;}
                            | B_AND  {$$=$1;}
                            | B_OR   {$$=$1;}                    
                            | B_XOR  {$$=$1;}                    
                            | B_EQU  {$$=$1;}
                            ;
