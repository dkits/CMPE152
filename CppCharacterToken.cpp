/*
 * CppCharacterToken.cpp
 *
 *  Created on: Sep 6, 2018
 *      Author: kenny
 */

#include "../../cpp/tokens/CppCharacterToken.h"

#include <string>

#include "../../cpp/CppError.h"

namespace wci { namespace frontend { namespace cpp { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::cpp;

CppCharacterToken::CppCharacterToken(Source *source) throw(string)
			: CppToken(source)
{
	extract();
}

void CppCharacterToken::extract() throw(string)
{
	string value_char = "";
	char current_ch = next_char();

	text += "\'";

	// get char characters
	do
	{
		if (current_ch != '\'')
		{
			if (current_ch == '\\' && peek_char() == '\\' && value_char == "")
			{
				text += current_ch;
				text += '\\';
				value_char = '\\';
				current_ch = next_char();
				current_ch = next_char();
			}
			else
			{
				if (current_ch == '\\' && peek_char() == '\'' && value_char == "")
				{
					text += current_ch;
					text += '\'';
					value_char = '\'';
					current_ch = next_char();
					current_ch = next_char();
				}
				else
				{
					text += current_ch;
					value_char += current_ch;
					current_ch = next_char();
				}
			}
		}
		if (current_ch == '\'')
		{
			while((current_ch == '\'') && (peek_char() == '\''))
			{
				text += current_ch;
				value_char += current_ch;
				current_ch = next_char();
				current_ch = next_char();
			}
		}
	} while ((current_ch != '\'') && (current_ch != Source::END_OF_FILE));

	if (current_ch == '\'')
	{
		next_char();
		text += '\'';
		type = (TokenType) PT_CHAR;
		value = value_char;
	}
	else
	{
		type = (TokenType) PT_ERROR;
		value = (int) UNEXPECTED_EOF;
	}
}
}}}}
