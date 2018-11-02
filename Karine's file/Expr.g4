grammar Expr;

/** The start rule; begin parsing here. */
prog:   stat+ ; 

stat:   expr ';'                
    |   ID '=' expr ';'
    |   '{' ID '=' expr ';' (stat+)? '}'
    | 	if_stat
    |	while_stat
    |	procedure
    |   procedure_call
    |	function
    |	function_call
    ;
    
if_stat:   'if' expr stat  
    	  ('else' stat)? ;
    	  
while_stat: 'while' expr  stat  ;



procedure: /*ID '(' ID '#'?')' '{'stat'}'*/ //with a hash is pass by reference 
			 'void' ID  expr '#'?  stat 	 
	;
	
procedure_call: 'void' ID  expr ';'
	;
		
function: ID'('ID'#'?')'  '{' (stat| expr) 'return' '('ID ')' ';' '}' //pass by reference function
	|	  ID'('ID')' '{''"' stat|expr '"' 'return' '('ID ')' ';''}' 	//pass by value function							 
	;
	
function_call:  ID'(' ID ')' ';' 
	|			ID'(' '"' ID '"' ')' ';' 
	;


expr:   expr ('*'|'/') expr   
    |   expr ('+'|'++'|'-') expr
    |   expr ('=='|'>='|'<='|'>'|'<') expr   
    |   INT                    
    |   ID
    |	BOOL                       
    |   '(' expr '#'?')'  
    ;

ID		:   [a-zA-Z_]+ ;      // match identifiers <label id="code.tour.expr.3"/>
INT		:   [0-9]+ ;         // match integers
BOOL	:   'true' 
		|   'false';
WS		:   [ \t\n\r]+ -> skip ; // toss out whitespace
