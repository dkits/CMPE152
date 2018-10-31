grammar Expr;

/** The start rule; begin parsing here. */
prog:   stat+ ; 

stat:   expr ';'                
    |   ID '=' expr ';'
    | 	if_stat
    |	while_stat
    ;
    
if_stat:   'if' expr '{' stat '}' 
    	  ('else' ('{'stat'}'|stat))? ;
    	  
while_stat: 'while' expr '{' stat '}' ;


expr:   expr ('*'|'/') expr   
    |   expr ('+'|'-') expr
    |   expr ('=='|'>='|'<='|'>'|'<') expr   
    |   INT                    
    |   ID
    |	BOOL                       
    |   '(' expr ')'         
    ;


ID		:   [a-zA-Z]+ ;      // match identifiers <label id="code.tour.expr.3"/>
INT		:   [0-9]+ ;         // match integers
BOOL	:   'true' 
		|   'false';
WS		:   [ \t\n\r]+ -> skip ; // toss out whitespace
		
