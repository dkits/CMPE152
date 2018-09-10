/**
 * <h1>CppWordToken</h1>
 *
 * <p> Cpp word tokens (identifiers and reserved words).</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "../../cpp/tokens/CppWordToken.h"

#include <iostream>
#include <string>
#include <map>

#include "../../cpp/CppError.h"

namespace wci { namespace frontend { namespace cpp { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::cpp;

CppWordToken::CppWordToken(Source *source) throw (string)
    : CppToken(source)
{
    extract();
}

/**
 * Extract a Cpp word token from the source.
 * @throws Exception if an error occurred.
 */
void CppWordToken::extract() throw (string)
{
    char current_ch = current_char();

    // Get the word characters (letter or digit). The scanner has
    // already determined that the first character is a letter.
    while (isalnum(current_ch))
    {
        text += current_ch;
        current_ch = next_char();  // consume character
    }

    // Is it a reserved word or an identifier?
    string upper_case = text;
    if (CppToken::RESERVED_WORDS.find(upper_case)
            != CppToken::RESERVED_WORDS.end())
    {
        // Reserved word.
        type = (TokenType) CppToken::RESERVED_WORDS[upper_case];
        value = upper_case;
    }
    else
    {
        // Identifier.
        type = (TokenType) PT_IDENTIFIER;
    }
}

}}}}  // namespace wci::frontend::Cpp::tokens
