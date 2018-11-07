grammar Expr;

/** The start rule; begin parsing here. */
prog:   stat+ ; 

stat:   expr (NEWLINE|';')                
    |   ID '=' expr (NEWLINE|';') stat?
    |   (NEWLINE|';')  
     
    | 	'if' expr ('{' NEWLINE|NEWLINE'{' ) stat '}' NEWLINE?
    	  ('else' (('{' NEWLINE|NEWLINE'{'NEWLINE )stat'}'|stat))?
    	  
   	|	'while' expr('{' NEWLINE|NEWLINE'{' ) stat '}' NEWLINE?
    ;
    
    

expr:   expr ('*'|'/') expr   
    |   expr ('+'|'-') expr
    |   expr ('=='|'>='|'<='|'>'|'<') expr   
    |   INT                    
    |   ID
    |	BOOL                      
    |   '(' expr ')'         
    ;


procedure: 'void' ID '(' ID')' '{' ID '=' expr '}' //pass by value procedure
	|	   'void' ID'('ID'#'')' '{''"' stat '"''}'//pass by reference procedure
	;
	
procedure_call: ID'('expr')' //pass by value call
	|			ID'(' ID')' //pass  by reference call
	;
		
function: 'in' ID'('ID'#'')'  '{' stat 'return' (ID)'}' //pass by reference function
	|	  'in' ID'('ID')' '{''"' expr '"' '}' 	//pass by value function							 
	;
	
function_call: ID'('ID')' //pass by reference
	|			ID'('expr')' //pass by value
	;


ID		:   [a-zA-Z]+ ;      // match identifiers <label id="code.tour.expr.3"/>
INT		:   [0-9]+ ;         // match integers
BOOL	:   [true]+ 
		|   [false]+;
NEWLINE	:   '\r'? '\n' ;     // return newlines to parser (is end-statement signal)
WS		:   [ \t]+ -> skip ; // toss out whitespace
