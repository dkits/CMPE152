/**
 * <h1>CppScanner</h1>
 *
 * <p>The Cpp scanner.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_Cpp_CppSCANNER_H_
#define WCI_FRONTEND_Cpp_CppSCANNER_H_

#include "../Scanner.h"
#include "../Source.h"
#include "../Token.h"

namespace wci { namespace frontend { namespace cpp {

using namespace std;
using namespace wci::frontend;

class CppScanner : public Scanner
{
public:
    /**
     * Constructor
     * @param source the source to be used with this scanner.
     */
    CppScanner(Source *source);

protected:
    /**
     * Extract and return the next Cpp token from the source.
     * @return the next token.
     * @throw a string message if an error occurred.
     */
    Token *extract_token() throw (string);

private:
    /**
     * Skip whitespace characters by consuming them.  A comment is whitespace.
     * @throw a string message if an error occurred.
     */
    void skip_white_space() throw (string);
};

}}} // namespace wci::frontend::Cpp

#endif /* WCI_FRONTEND_Cpp_CppSCANNER_H_ */
