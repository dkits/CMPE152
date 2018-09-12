/**
 * <h1>CppScanner</h1>
 *
 * <p>The Cpp scanner.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */

#include "../cpp/CppScanner.h"

#include <iostream>

#include "../cpp/CppError.h"
#include "../cpp/CppToken.h"
#include "../cpp/tokens/CppErrorToken.h"
#include "../cpp/tokens/CppNumberToken.h"
#include "../cpp/tokens/CppSpecialSymbolToken.h"
#include "../cpp/tokens/CppStringToken.h"
#include "../cpp/tokens/CppWordToken.h"
#include "../Source.h"

namespace wci { namespace frontend { namespace cpp {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::cpp::tokens;

CppScanner::CppScanner(Source *source) : Scanner(source)
{
}

Token *CppScanner::extract_token() throw (string)
{
    skip_white_space();

    Token *token;
    char current_ch = current_char();
    string string_ch = " ";

    string_ch[0] = current_ch;

    // Construct the next token.  The current character determines the
    // token type.
    if (current_ch == Source::END_OF_FILE)
    {
        token = nullptr;
    }
    else if (isalpha(current_ch))
    {
        token = new CppWordToken(source);
    }
    else if (isdigit(current_ch))
    {
        token = new CppNumberToken(source);
    }
    else if (current_ch == '\'')
    {
        token = new CppStringToken(source);
    }
    else if (CppToken::SPECIAL_SYMBOLS.find(string_ch)
                != CppToken::SPECIAL_SYMBOLS.end())
    {
        token = new CppSpecialSymbolToken(source);
    }
    else
    {
        token = new CppErrorToken(source, INVALID_CHARACTER, string_ch);
        next_char();  // consume character
    }

    return token;
}

void CppScanner::skip_white_space() throw (string)
{//slash * or slash slash
    char current_ch = current_char();

    while (isspace(current_ch) || (current_ch == '/*')) {

        // Start of a comment?
        if (current_ch == '/*')
        {
            do
            {
                current_ch = next_char();  // consume comment characters
            } while ((current_ch != '*/') &&
                     (current_ch != Source::END_OF_FILE));

            // Found closing '}'?
            if (current_ch == '*/')
            {
                current_ch = next_char();  // consume the '}'
            }
        }

        // Not a comment.
        else current_ch = next_char();  // consume whitespace character
    }
}

}}} // namespace wci::frontend::Cpp
