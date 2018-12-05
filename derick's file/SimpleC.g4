grammar SimpleC;
@header {
#include "wci/intermediate/TypeSpec.h"

using namespace wci::intermediate;
}
/** The start rule; begin parsing here. */
prog:   header '{' block '}'; 
header: MAIN;
block: stat+;
stat:   funcID '=' expr ';' 				   #statID 
    |	'{'(funcID '=' expr ';')? (stat+)? '}' #statID_equals
    | 	var_dec			                   #statVar
    | 	if_stat							   #statIf
    |	while_stat                         #statWhile
    |	function                           #statFunc
    |	func_call                          #statCall
    |	'return' expr? ';'                 #statRet
    ;
    
var_dec: var varList ('=' expr)? ';'  ;
varList: varID ( ',' varID )* ;
varID  : ID;
    
if_stat:   'if' expr stat  
    	  ('else' stat)? ;
    	  
while_stat: 'while' expr  stat ;

function: var ID  expr? stat ; //pass by value procedure
	
func_call: ID expr ';';

expr locals [ TypeSpec *type = nullptr ]
	:   expr mulDivOp expr                #exprMultDiv   
    |   expr addSubOp expr                #exprAddSub
    |   expr compOP   expr                #exprComp  
    |   '#'? num   (',' '#'? expr )?      #exprFuncInt           
    |   '#'? funcID (',' '#'? expr )?     #exprFuncID    
    |	'#'? booln(',' '#'? expr )?       #exprFuncBool              
    |   '(' expr ')'                      #exprPara
    ;
    
var
	:	'void' 
	|	'int'  
	|	'bool'
	;
	
funcID   : ID;

compOP   : '=='|'>='|'<='|'>'|'<';
mulDivOp : MUL_OP | DIV_OP ;
addSubOp : ADD_OP | SUB_OP ;

num  locals [ TypeSpec *type = nullptr ]
    : INT  #integerConst
    ;
    
booln locals [ TypeSpec *type = nullptr ]
	: BOOL #boolConst
	;      
    
MUL_OP :   '*' ; DIV_OP :   '/' ;
ADD_OP :   '+' ; SUB_OP :   '-' ;

MAIN    :   'main';
ID		:   [a-zA-Z_]+ ;      // match identifiers <label id="code.tour.expr.3"/>
INT		:   [0-9]+ ;         // match integers
BOOL	:   'true' 
		|   'false';
WS		:   [ \t\n\r]+ -> skip ; // toss out whitespace
		
