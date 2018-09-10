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
	char value_char = ' ';

	char current_ch = next_char();
	char_text += '\'';

	// Get char characters
	do
	{
		if (current_ch != '\'' and current_ch != '\\')
		{
			char_text += current_ch;
			value_char += current_ch;
			current_ch = next_char(); // consume character
		}

		if (current_ch == '\\')
		{
			if (peek_char() == '\'')
			{
				char_text = '\'';
				value = '\'';
				next_char();
			}
		}
	} while (current_ch != '\'');

	if (current_ch == '\'')
	{
		next_char();
		char_text += '\'';
		type = (TokenType) PT_CHAR;
		value = value_char;
	}
	else
	{
		type = (TokenType) PT_ERROR;
		value = (int) UNEXPECTED_EOF;
	}
	/*char current_ch = current_char();
	bool good_char = true;

	char_text = current_ch;
	switch(current_ch)
	{
		case 'a': case 'b': case 'c': case 'd':
		case 'e': case 'f': case 'g': case 'h':
		case 'i': case 'j': case 'k': case 'l':
		case 'm': case 'n': case 'o': case 'p':
		case 'q': case 'r': case 's': case 't':
		case 'u': case 'v': case 'w': case 'x':
		case 'y': case 'z': case 'A': case 'B':
		case 'C': case 'D': case 'E': case 'F':
		case 'G': case 'H': case 'I': case 'J':
		case 'K': case 'L': case 'M': case 'N':
		case 'O': case 'P': case 'Q': case 'R':
		case 'S': case 'T': case 'U': case 'V':
		case 'W': case 'X': case 'Y': case 'Z':
		{
			next_char();
			break;
		}
		// single quote
		case '\'':
		{
			current_ch = next_char(); // consume '
			if (current_ch == '\\')
			{
				char_text = current_ch;
				next_char(); // consume '\'
			}
			break;
		}
		// '\n' and '\t' and '\\'
		case '\\':
		{
			current_ch = next_char(); // consume '\'
			if (current_ch == 'n' or current_ch == 't')
			{
				char_text += current_ch; // concatenate
				next_char(); // consume n, or t
			}
			if (current_ch == '\'' or current_ch == '\\') // ' or '\'
			{
				char_text = current_ch;
				next_char();
			}
			break;
		}
		// case ' ': break; // whitespace
		default:
		{
			next_char();  // consume bad character
			type = (TokenType) (PT_ERROR);
			value = (int) INVALID_CHARACTER;
			good_char = false;
		}
	}
    // Set the type if it wasn't an error.
    if (good_char) {
        type = (TokenType) (CppToken::CHARACTERS[char_text]);
    }*/
}
}}}}
