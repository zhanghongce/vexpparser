%require "3.0"
%skeleton "lalr1.cc" /* -*- C++ -*- */
%verbose
%locations
%defines
%define parser_class_name {Parser}
%define api.value.type variant
%define api.token.constructor
%define api.namespace {Vexp}
%define parse.error verbose
%define parse.trace
%define api.token.prefix {TOK_}

%code requires
{
  #include <vexp.h>
  typedef VExprAst::VExprAstPtr VExprAstPtr;
  
  namespace Vexp {
    class Scanner;
    class Interpreter;
  };
}

%code top
{
  #include "scanner.h"
  #include "vexp_parser.hh"
  #include "interpreter.h"
  #include "location.hh"

    // yylex() arguments are defined in parser.y
    static Vexp::Parser::symbol_type yylex(Vexp::Scanner &scanner, Vexp::Interpreter &driver) {
        return scanner.get_next_token();
    }
    
    // you can accomplish the same thing by inlining the code using preprocessor
    // x and y are same as in above static function
    // #define yylex(x, y) scanner.get_next_token()
    
    using namespace Vexp;

}

%lex-param { Vexp::Scanner &scanner }
%lex-param { Vexp::Interpreter &driver }
%parse-param { Vexp::Scanner &scanner }
%parse-param { Vexp::Interpreter &driver }


/* Operators Precedence */

%token END 0 "end of file"
%token SEMICOLON "semicolon";

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


%nterm<VExprAst::VExprAstPtr> astroot expression primary conditional_expression number function_call
%nterm<VExprAst::VExprAstPtr> concatenation multiple_concatenation
%nterm<voperator> unary_operator
%nterm<Attribute> attribute_instances list_of_attribute_instances attr_specs
%nterm<std::string> unsigned_number
%nterm<std::string> hierarchical_identifier_special_name text_macro_usage
%nterm<std::string> identifier simple_identifier escaped_identifier attr_name
%nterm<std::string> string
%nterm<std::string> hierarchical_identifier
%nterm<VExprAst::VExprAstPtrVec> expressions
%nterm<SuffixOp>  sq_bracket_expression

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

astroot : expression {
    // TODO : set ast_root
    driver.SetAstRoot($1);
  } 
;

expression :
  primary {
    $$ = $1;
  }
| unary_operator attribute_instances primary{
    $$ = VExprAst::MakeUnaryAst( $1, $3 );
  }
| expression AT  attribute_instances expression{
    // this is the A@B shortcut
    $$ = VExprAst::MakeBinaryAst(voperator::AT, $1, $4);
  }
| expression PLUS  attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::PLUS, $1, $4);
  }
| expression MINUS attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::MINUS, $1, $4);
  }
| expression STAR  attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::STAR, $1, $4);
  }
| expression DIV   attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::DIV, $1, $4);
  }
| expression MOD   attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::MOD, $1, $4);
  }
| expression L_EQ  attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::L_EQ, $1, $4);
  }
| expression L_NEQ attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::L_NEQ, $1, $4);
  }
| expression C_EQ  attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::C_EQ, $1, $4);
  }
| expression C_NEQ attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::C_NEQ, $1, $4);
  }
| expression L_AND attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::L_AND, $1, $4);
  }
| expression L_OR  attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::L_OR, $1, $4);
  }
| expression POW   attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::POW, $1, $4);
  }
| expression LT    attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::LT, $1, $4);
  }
| expression LTE   attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::LTE, $1, $4);
  }
| expression GT    attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::GT, $1, $4);
  }
| expression GTE   attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::GTE, $1, $4);
  }
| expression B_AND attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::B_AND, $1, $4);
  }
| expression B_OR  attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::B_OR, $1, $4);
  }
| expression B_XOR attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::B_XOR, $1, $4);
  }
| expression B_NOR attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::B_NOR, $1, $4);
  }
| expression B_NAND attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::B_NAND, $1, $4);
  }
| expression B_EQU attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::B_EQU, $1, $4);
  }
| expression LSR   attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::LSR, $1, $4);
  }
| expression LSL   attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::LSL, $1, $4);
  }
| expression ASR   attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::ASR, $1, $4);
  }
| expression ASL   attribute_instances expression{
    $$ = VExprAst::MakeBinaryAst(voperator::ASL, $1, $4);
  }
| conditional_expression {$$=$1;}

| function_call {
      $$ = $1;
  }

;



/* A.8.3 Expressions */

conditional_expression : 
  expression TERNARY attribute_instances expression COLON expression{
    $$ = VExprAst::MakeTernaryAst( voperator::TERNARY, $1,$4,$6);
  }
;


primary :
  number{
      $$ = $1;
  }
| hierarchical_identifier {
      $$ = VExprAst::MakeVar($1);
  }
| primary sq_bracket_expression {
    if ( $2.op == voperator::INDEX ) {
      // binary operation
      $$ = VExprAst::MakeBinaryAst($2.op, $1, $2.ranges.at(0));
    } else {
      // ternary operation
      $$ = VExprAst::MakeTernaryAst($2.op, $1, $2.ranges.at(0), $2.ranges.at(1));
    }
  }
| string {$$ = VExprAst::MakeSpecialName($1);}
| hierarchical_identifier_special_name {
  $$ = VExprAst::MakeSpecialName($1);
}
| concatenation{
    $$ = $1;
  }
| multiple_concatenation{
    $$ = $1;
  }
| OPEN_BRACKET expression CLOSE_BRACKET{
    $$ = $2;
  }
;



hierarchical_identifier_special_name :
 HASH SIMPLE_ID HASH {
  /* this is #a#, but we return the string in the middle */
  $$ = $2;
  }
;


/* A.8.1 Concatenations */

concatenation : 
  OPEN_SQ_BRACE expressions CLOSE_SQ_BRACE{
   $$ = VExprAst::MakeNaryAst(voperator::CONCAT, $2 );
  }
;


multiple_concatenation :
  OPEN_SQ_BRACE expression concatenation CLOSE_SQ_BRACE{
    $$ =  VExprAst::MakeBinaryAst(voperator::REPEAT, $2, $3 );
  }
;


number :
  NUM_REAL{
    $$ = VExprAst::MakeConstant(0,0,$1);
  }
| BIN_BASE BIN_VALUE {
  // TODO : 1. auto width determine
  //        2. width check
  //        3. check?
  // NOTE: you can also add internal translation annotations
  //       when handling this pass
    $$ = VExprAst::MakeConstant(2, 0 ,$2);
}
| HEX_BASE HEX_VALUE {
    $$ = VExprAst::MakeConstant(16, 0 ,$2);
}
| OCT_BASE OCT_VALUE {
    $$ = VExprAst::MakeConstant(8, 0 ,$2);
}
| DEC_BASE UNSIGNED_NUMBER {
    $$ = VExprAst::MakeConstant(10, 0 ,$2);
}
| UNSIGNED_NUMBER BIN_BASE BIN_VALUE {
    $$ = VExprAst::MakeConstant(2, width_to_int($1) ,$3);
}
| UNSIGNED_NUMBER HEX_BASE HEX_VALUE {
    $$ = VExprAst::MakeConstant(16, width_to_int($1) ,$3);
}
| UNSIGNED_NUMBER OCT_BASE OCT_VALUE {
    $$ = VExprAst::MakeConstant(8, width_to_int($1) ,$3);
}
| UNSIGNED_NUMBER DEC_BASE UNSIGNED_NUMBER{
    $$ = VExprAst::MakeConstant(10, width_to_int($1) ,$3);
}
| unsigned_number {
    $$ = VExprAst::MakeConstant(0,0,$1);}
;


unsigned_number :
  UNSIGNED_NUMBER {
    $$ = $1;
  }
;


function_call : hierarchical_identifier
 attribute_instances OPEN_BRACKET expressions CLOSE_BRACKET{
    ($4).insert(($4).begin(), VExprAst::MakeVar($1));
    $$ = VExprAst::MakeNaryAst(voperator::FUNCTION_APP, $4 );
 }
 |  hierarchical_identifier
 attribute_instances OPEN_BRACKET CLOSE_BRACKET {
   VExprAst::VExprAstPtrVec tmp;
   tmp.push_back(VExprAst::MakeVar($1));
   $$ = VExprAst::MakeNaryAst(voperator::FUNCTION_APP, tmp );
 }
;


expressions :
  expression {
   $$ = VExprAst::VExprAstPtrVec();
   ($$).push_back($1);
  }
| expressions COMMA expression{
  $$ = $1;
  ($$).push_back($3);
  }
;



sq_bracket_expression :
  OPEN_SQ_BRACKET expression CLOSE_SQ_BRACKET{
    // create one and replace as needed
    $$ = SuffixOp();
    ($$).op = voperator::INDEX;
    ($$).ranges.push_back($2);
  }
| OPEN_SQ_BRACKET expression COLON  expression CLOSE_SQ_BRACKET{
    $$ = SuffixOp();
    ($$).op = voperator::RANGE_INDEX;
    ($$).ranges.push_back($2);
    ($$).ranges.push_back($4);
  }
| OPEN_SQ_BRACKET expression IDX_PRT_SEL_PLUS expression CLOSE_SQ_BRACKET{
    $$ = SuffixOp();
    ($$).op = voperator::IDX_PRT_SEL_PLUS;
    ($$).ranges.push_back($2);
    ($$).ranges.push_back($4);
  }
| OPEN_SQ_BRACKET expression IDX_PRT_SEL_MINUS expression CLOSE_SQ_BRACKET{
      // $2 $4
    $$ = SuffixOp();
    ($$).op = voperator::IDX_PRT_SEL_MINUS;
    ($$).ranges.push_back($2);
    ($$).ranges.push_back($4);
  }
;



string : STRING {$$=$1;} ;

/* A.9.1 Attributes */

attribute_instances : { $$=Attribute(); }
                    | list_of_attribute_instances { $$=$1; }
                    ;

list_of_attribute_instances : 
  ATTRIBUTE_START attr_specs ATTRIBUTE_END {
      $$ = $2;
  }
| ATTRIBUTE_START attr_specs ATTRIBUTE_END list_of_attribute_instances{
      $$ = $2;
      ($$).Append($4);
  }
;

attr_specs : { $$ = Attribute(); }
           | attr_name EQ expression {
               // make new one
               $$ = Attribute();
               ($$).AddAttribute($1,$3);
           }
           | attr_name EQ expression COMMA attr_specs {
               // Append the new item to the existing list and return.
               $$ = $5;
               ($$).AddAttribute($1,$3);               
           }
           ;


attr_name : identifier {$$=$1;};


hierarchical_identifier : 
  simple_identifier {
      $$ = $1;
  }
| hierarchical_identifier DOT simple_identifier{
  // text_macro_usage
      $$ = $1 + "." + $3;
  }
| hierarchical_identifier DOT escaped_identifier{
      $$ = $1 + "." + $3;
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
    $$ = $1; /* VExprAst::MakeVar($1); */
}
;


/* 19.0 Compiler Directives */


text_macro_usage : MACRO_IDENTIFIER {
  $$=$1;
};



/* A.8.6 Operators */

unary_operator : PLUS    {$$ = voperator::PLUS;}
               | MINUS   {$$ = voperator::MINUS;}
               | L_NEG   {$$ = voperator::L_NEG;}
               | B_NEG   {$$ = voperator::B_NEG;}
               | B_AND   {$$ = voperator::B_AND;}
               | B_NAND  {$$ = voperator::B_NAND;}
               | B_OR    {$$ = voperator::B_OR;}
               | B_NOR   {$$ = voperator::B_NOR;}
               | B_XOR   {$$ = voperator::B_XOR;}
               | B_EQU   {$$ = voperator::B_EQU;}
               ;


%%

// Bison expects us to provide implementation - otherwise linker complains
void Vexp::Parser::error(const location &loc , const std::string &message) {
        
        // Location should be initialized inside scanner action, but is not in this example.
        // Let's grab location directly from driver class.
	// cout << "Error: " << message << endl << "Location: " << loc << endl;
	
        std::cout << "Error: " << message << std::endl << "Error location: " << driver.location() << std::endl;
}
