grammar Expr;

/** The start rule; begin parsing here. */
prog:   stat+ ; 

stat:   expr NEWLINE                
    |   ID '=' expr NEWLINE    
    | ID '=' expr 
    |   NEWLINE        
    | expr NEWLINE    
    | INT
    | 'FOR' stat ';' stat ';' stat
	| 'TO'
	| 'DO'
	| 'WHILE' stat DO stat
    ;

expr:   expr ('*'|'/') expr   
    |   expr ('+'|'-') expr   
    |   INT                    
    |   ID                    
    |   '(' expr ')'         
    ;

pas_for: FOR ID '=' expr TO expr DO stat
	;
	
pas_while: WHILE stat DO stat
	;
	
		

TO: 'TO';
DO: 'DO';


ID  :   [a-zA-Z]+ ;      // match identifiers <label id="code.tour.expr.3"/>
INT :   [0-9]+ ;         // match integers
NEWLINE:'\r'? '\n' ;     // return newlines to parser (is end-statement signal)
WS  :   [ \t]+ -> skip ; // toss out whitespace
