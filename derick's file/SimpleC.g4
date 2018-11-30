grammar SimpleC;

/** The start rule; begin parsing here. */
prog:   header '{' block '}'; 
header: MAIN;
block: stat+;
stat:   expr ';' 						   #statExpr               
    |   ID '=' expr ';' 				   #statID 
    |	'{'(ID '=' expr ';')? (stat+)? '}' #statID_equals
    | 	var_dec			                   #statVar
    | 	if_stat							   #statIf
    |	while_stat                         #statWhile
    |	function                           #statFunc
    |	func_call                          #statCall
    |	'return' expr? ';'                 #statRet
    ;

var_dec
	:	'int'  expr ('=' expr)? ';'        #varInt
	|	'bool' expr ('=' expr)? ';'        #varBool
	;    
if_stat:   'if' expr stat  
    	  ('else' stat)? ;
    	  
while_stat: 'while' expr  stat ;

function: func_synt ID  expr? stat ; //pass by value procedure
	
func_call: ID expr ';';

expr:   expr ('*'|'/') expr                #exprMultDiv   
    |   expr ('+'|'-') expr                #exprAddSub
    |   expr ('=='|'>='|'<='|'>'|'<') expr #exprComp  
    |   '#'? INT (',' '#'? expr )?         #exprFuncInt           
    |   '#'? ID  (',' '#'? expr )?         #exprFuncID    
    |	'#'? BOOL(',' '#'? expr )?         #exprFuncBool              
    |   '(' expr ')'                       #exprPara
    ;

func_synt
	:	'void' #funcVoid
	|	'int'  #funcInt
	|	'bool' #funcBool
	;
MAIN    :   'main';
ID		:   [a-zA-Z_]+ ;      // match identifiers <label id="code.tour.expr.3"/>
INT		:   [0-9]+ ;         // match integers
BOOL	:   'true' 
		|   'false';
WS		:   [ \t\n\r]+ -> skip ; // toss out whitespace
		
