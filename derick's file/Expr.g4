grammar Expr;

/** The start rule; begin parsing here. */
prog:   stat+ ; 

stat:   expr ';'                
    |   ID '=' expr ';' 
    |	'{' ID '=' expr ';' (stat+)? '}'
    | 	if_stat
    |	while_stat
    |	function
    |	func_call
    |	'return' expr? ';'
    ;
    
if_stat:   'if' expr stat  
    	  ('else' stat)? ;
    	  
while_stat: 'while' expr  stat ;

function: func_synt ID  expr stat ; //pass by value procedure
	
func_call: ID expr ';';

expr:   expr ('*'|'/') expr   
    |   expr ('+'|'-') expr
    |   expr ('=='|'>='|'<='|'>'|'<') expr   
    |   '#'? INT (',' '#'? expr )?                    
    |   '#'? ID  (',' '#'? expr )?
    |	'#'? BOOL(',' '#'? expr )?                       
    |   '(' expr ')'         
    ;
func_synt
	:	'void'
	|	'int'
	|	'bool'
	;
ID		:   [a-zA-Z_]+ ;      // match identifiers <label id="code.tour.expr.3"/>
INT		:   [0-9]+ ;         // match integers
BOOL	:   'true' 
		|   'false';
WS		:   [ \t\n\r]+ -> skip ; // toss out whitespace
		
