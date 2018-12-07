grammar SimpleC;
@header {
#include "wci/intermediate/TypeSpec.h"

using namespace wci::intermediate;
}
/** The start rule; begin parsing here. */
prog:   header block function*; 
header: MAIN;
block: '{'stat+'}';
stat:   funcID '=' expr ';' 				   #statID 
//    |	'{'(funcID '=' expr ';')? (stat+)? '}' #statID_equals
    | 	var_dec			                   #statVar
    | 	if_stat							   #statIf
    |	while_stat                         #statWhile
    |	function                           #statFunc
    |	func_call                          #statCall
    |   print                              #statPrint
    |	'return' expr? ';'                 #statRet
    ;
    
var_dec: varOP varList ('=' expr)? ';'  ;
varList: varID ( ',' varID )* ;
varID  : ID;
varOP :	'int' |'bool';

print: PRINT'('string+')' ';';  //add string or expr for here. Printf


if_stat:   'if' expr '{' stat* '}'  
    	  ('else' (if_stat | '{' stat* '}')? )? ;
    	  
while_stat: 'while' expr '{' stat* '}';

function: (varOP|'void') ID  expr? '{' stat* '}' ; //pass by value procedure

func_call: ID expr ';';

expr locals [ TypeSpec *type = nullptr ]
	:   expr mulDivOp expr                #exprMultDiv   
    |   expr addSubOp expr                #exprAddSub
    |   expr compOP   expr                #exprComp  
    |   num         #exprFuncInt           
    |   funcID      #exprFuncID    
    |	booln       #exprFuncBool              
    |   '(' expr ')'                      #exprPara
    ;
	
funcID   : ID;
string: ID;


compOP   : '=='|'>='|'<='|'>'|'<';
mulDivOp : '*' | '/' ;
addSubOp : '+' | '-' ;

num  locals [ TypeSpec *type = nullptr ]
    : INT  #integerConst
    ;
    
booln locals [ TypeSpec *type = nullptr ]
	: BOOL #boolConst
	;      
    

MAIN    :   'main';
PRINT   :   'print';
ID		:   [a-zA-Z][a-zA-Z0-9_]*;      // match identifiers <label id="code.tour.expr.3"/>
INT		:   [0-9]+ ;         // match integers
BOOL	:   'true' 
		|   'false';
WS		:   [ \t\n\r]+ -> skip ; // toss out whitespace
		
