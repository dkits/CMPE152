grammar SimpleC;
@header {
#include "wci/intermediate/TypeSpec.h"

using namespace wci::intermediate;
}
/** The start rule; begin parsing here. */
prog:   header block function*; 
header: BIGMAIN;
block: '{'var_table? stat*'}';
stat:   assignment_stat 			       
    | 	if_stat							   
    |	while_stat                         
    |	function                           
    |	func_call                          
    |   print                              
    |	func_re                            
    ;
    

var_table: VARLIST '{'var_dec* '}';
var_dec  : varList '->' varOP ';'  ;
varList  : varID ( ',' varID )* ;
varID    : ID;
varOP    : 'int' |'bool' | 'float';

voidOP   : 'void';

assignment_stat : vari '=' expr ';'    ;

print: PRINT'('string')' ';';  //add string or expr for here. Printf


if_stat:   'if' expr  block   
    	  ('else' (if_stat |  block )? )? ;
    	  
while_stat: 'while' expr '{' stat* '}';

function: (varOP|voidOP) ID  expr? block ; //pass by value procedure

func_call: ID expr ';';

func_re: 'return' expr? ';' ;

expr locals [ TypeSpec *type = nullptr ]
	:   expr mulDivOp expr  #exprMultDiv   
    |   expr addSubOp expr  #exprAddSub
    |   expr compOP   expr  #exprComp  
    |   num       			#exprInt    
    |	booln       	 	#exprBool                     
    |   vari        		#exprVari    
    |   '(' expr ')'        #exprPara
    ;
	
vari: ID;
string: '"'ID+'"';

compOP   : EQU_OP | LEQ_OP | GEQ_OP | LES_OP | GTR_OP;
mulDivOp : MUL_OP | DIV_OP ;
addSubOp : ADD_OP | SUB_OP ;

num  locals [ TypeSpec *type = nullptr ]
    : INT     #integerConst
    | FLOAT   # floatConst    
    ;
    
booln locals [ TypeSpec *type = nullptr ]
	: BOOL #boolConst
	;      
    
MUL_OP :   '*' ; DIV_OP :   '/' ;
ADD_OP :   '+' ; SUB_OP :   '-' ;
EQU_OP :  '==' ; 
LEQ_OP :  '<=' ; GEQ_OP :  '>=' ;
LES_OP :   '<' ; GTR_OP :   '>' ;

VARLIST :   'VARLIST';
BIGMAIN :   'BIGMAIN';


PRINT   :   'print';
BOOL	:   'true'
		|   'false' ;
ID		:   [a-zA-Z][a-zA-Z0-9_]*;      // match identifiers <label id="code.tour.expr.3"/>
INT		:   [0-9]+ ;         // match integers
FLOAT   :   [0-9]+ '.' [0-9]+ ;

NEWLINE : '\r'? '\n' -> skip  ;
WS      : [ \t]+ -> skip ; 
		
