
{SYSTEM_ID}            {
    yylval.identifier = ast_new_identifier(yytext,yylineno); 
    EMIT_TOKEN(SYSTEM_ID);
}




unary_operator voperator
text_macro_usage VExprAstPtr


