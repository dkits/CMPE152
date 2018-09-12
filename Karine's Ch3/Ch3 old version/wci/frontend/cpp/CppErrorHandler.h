/**
 * <h1>CppErrorHandler</h1>
 *
 * <p>Error handler Cpp syntax errors.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_Cpp_CppERRORHANDLER_H_
#define WCI_FRONTEND_Cpp_CppERRORHANDLER_H_

#include "../Token.h"
#include "../Parser.h"
#include "../cpp/CppError.h"

namespace wci { namespace frontend { namespace cpp {

using namespace std;
using namespace wci::frontend;

class CppErrorHandler
{
public:
    /**
     * Getter.
     * @return the syntax error count.
     */
    int get_error_count() const;

    /**
     * Flag an error in the source line.
     * @param token the bad token.
     * @param errorCode the error code.
     * @param parser the parser.
     * @return the flagger string.
     */
    void flag(Token *token, CppErrorCode error_code, Parser *parser);

    /**
     * Abort the translation.
     * @param errorCode the error code.
     * @param parser the parser.
     */
    void abort_translation(CppErrorCode error_code, Parser *parser);

private:
    static int error_count;
    static const int MAX_ERRORS;
};

}}}  // namespace wci::frontend::Cpp

#endif /* WCI_FRONTEND_Cpp_CppERRORHANDLER_H_ */
