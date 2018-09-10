/**
 * <h1>CppStringToken</h1>
 *
 * <p> Cpp string tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "../../cpp/tokens/CppStringToken.h"

#include <string>

#include "../../cpp/CppError.h"

namespace wci { namespace frontend { namespace cpp { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::cpp;

CppStringToken::CppStringToken(Source *source) throw (string)
    : CppToken(source)
{
    extract();
}

void CppStringToken::extract() throw (string)
{
    string value_str = "";

    char current_ch = next_char();  // consume initial quote
    text += "\"";

    // Get string characters.
    do
    {
        // Replace any whitespace character with a blank.
        if (isspace(current_ch)) current_ch = ' ';



        // If a \ is detected it will read the next char

        if ((current_ch != '\"') && (current_ch != EOF))
			{
            if (current_ch == '\\')
            {
                while ((current_ch == '\\') )
                {

                    text += current_ch;
                    value_str  += current_ch;
                    //value_str  += current_ch;  // append double-quote
                    //current_ch = next_char();  // consume pair of quotes
                    current_ch = next_char();
                }
            }
				text += current_ch;
				value_str  += current_ch;
				current_ch = next_char();  // consume character
			}
    } while ((current_ch != '\"') && (current_ch != Source::END_OF_FILE));

    if (current_ch == '\"')
    {
        next_char();  // consume final quote
        text += '\"';
        type = (TokenType) PT_STRING;
        value = value_str;
    }
    else
    {
        type = (TokenType) PT_ERROR;
        value = (int) UNEXPECTED_EOF;
    }
}

}}}}  // namespace wci::frontend::Cpp::tokens
