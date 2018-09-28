/**
 * <h1>CaseStatementParser</h1>
 *gggg
 * <p>Parse a Pascal CASE statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <set>
#include "WhenStatementParser.h"
#include "StatementParser.h"
#include "AssignmentStatementParser.h"
#include "ExpressionParser.h"
#include "../PascalParserTD.h"
#include "../PascalToken.h"
#include "../PascalError.h"
#include "../../Token.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/ICodeFactory.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;
using namespace wci::intermediate::icodeimpl;

set<PascalTokenType> WhenStatementParser::THEN_EQUALS_SET;


bool WhenStatementParser::INITIALIZED = false;

void WhenStatementParser::initialize()
{
    if (INITIALIZED) return;

    THEN_EQUALS_SET = StatementParser::STMT_START_SET;
    THEN_EQUALS_SET.insert(PascalTokenType::THEN_EQUALS);

    set<PascalTokenType>::iterator it;
    for (it  = StatementParser::STMT_FOLLOW_SET.begin();
         it != StatementParser::STMT_FOLLOW_SET.end();
         it++)
    {
    	THEN_EQUALS_SET.insert(*it);
    }

    INITIALIZED = true;
}

WhenStatementParser::WhenStatementParser(PascalParserTD *parent)
    : StatementParser(parent)
{
    initialize();
}

ICodeNode *WhenStatementParser::parse_statement(Token *token) throw (string)
{
    token = next_token(token);  // consume the WHEN
    bool otherwiseCheck = true;
    ICodeNode *if_node =
        	            ICodeFactory::create_icode_node((ICodeNodeType) NT_IF);

    // Create an IF node.

        // Parse the expression.
        // The IF node adopts the expression subtree as its first child.
        ExpressionParser expression_parser(this);
        if_node->add_child(expression_parser.parse_statement(token));

        // Synchronize at the =>.
        token = synchronize(THEN_EQUALS_SET);
        if (token->get_type() == (TokenType) PT_THEN_EQUALS)
        {
            token = next_token(token);  // consume the THEN_EQUALS
        }
        else {
            error_handler.flag(token, MISSING_THEN_EQUALS, this);
        }

        // Parse the => statement.
        // The IF node adopts the statement subtree as its second child.
        StatementParser statement_parser(this);
        if_node->add_child(statement_parser.parse_statement(token));
        token = current_token();

        // Look for an ;.

        if (token->get_type() == (TokenType) PT_SEMICOLON)
        {
            token = next_token(token);  // consume the ;
        }
        //New Parent temp that points to the original if node
        ICodeNode *parent_temp_if_node = if_node;
        //Run through the code again with a new node
        while ((token != nullptr) &&
                   (token->get_type() != (TokenType) PT_END)){
        	ICodeNode *temp_if_node =
        	                	     ICodeFactory::create_icode_node((ICodeNodeType) NT_IF);

        	temp_if_node->add_child(expression_parser.parse_statement(token));

        	        // Synchronize at the =>.
			token = synchronize(THEN_EQUALS_SET);
			if (token->get_type() == (TokenType) PT_THEN_EQUALS)
			{
				token = next_token(token);  // consume the THEN_EQUALS
			}
			else {
				error_handler.flag(token, MISSING_THEN_EQUALS, this);
			}

			// Parse the => statement.
			// The IF node adopts the statement subtree as its second child.
			StatementParser statement_parser(this);
			temp_if_node->add_child(statement_parser.parse_statement(token));
			token = current_token();
	        if (token->get_type() == (TokenType) PT_SEMICOLON)
	        {
	            token = next_token(token);  // consume the ;

	        }
			// Look for an ;.
	        if(token->get_type() == (TokenType) PT_OTHERWISE)
	        {
				token = next_token(token);  // consume the OTHERWISE
				token = synchronize(THEN_EQUALS_SET);
				if (token->get_type() == (TokenType) PT_THEN_EQUALS)
				{
					token = next_token(token);  // consume the THEN_EQUALS
				}
				else {
					error_handler.flag(token, MISSING_THEN_EQUALS, this);
				}

				// Parse the => statement.
				// The IF node adopts the statement subtree as its second child.
				temp_if_node->add_child(statement_parser.parse_statement(token));
				token = current_token();
				otherwiseCheck = false;

			}
	        //WHEN statement requires an otherwise at the end
	        //The node is added to the parent node
	        //and the parent node is then reseted for another loop
	        parent_temp_if_node ->add_child(temp_if_node);
	        parent_temp_if_node = temp_if_node;



        }
        //THere should always be a otherwise for WHEN
        if(otherwiseCheck){
			error_handler.flag(token, MISSING_OTHERWISE, this);
		}
        if (token->get_type() == (TokenType) PT_END)
		{
			token = next_token(token);  // consume END
		}
        return if_node;


}


}}}}  // namespace wci::frontend::pascal::parsers
