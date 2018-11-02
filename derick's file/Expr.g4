grammar Expr;

/** The start rule; begin parsing here. */
prog:   stat+ ; 

stat:   expr ';'                
    |   ID '=' expr ';' 
    |	'{' ID '=' expr ';' (stat+)? '}'
    | 	if_stat
    |	while_stat
    |	procedure
    ;
    
if_stat:   'if' expr stat  
    	  ('else' stat)? ;
    	  
while_stat: 'while' expr  stat ;

procedure: 'void' ID  expr '#'?  stat  //pass by value procedure
	;

expr:   expr ('*'|'/') expr   
    |   expr ('+'|'-') expr
    |   expr ('=='|'>='|'<='|'>'|'<') expr   
    |   INT                    
    |   ID (','expr)?
    |	BOOL                       
    |   '(' expr ')'         
    ;
    

ID		:   [a-zA-Z_]+ ;      // match identifiers <label id="code.tour.expr.3"/>
INT		:   [0-9]+ ;         // match integers
BOOL	:   'true' 
		|   'false';
WS		:   [ \t\n\r]+ -> skip ; // toss out whitespace
		
