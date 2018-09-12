/**
 * <h1>CppParserTD</h1>
 *
 * <p>The top-down Cpp parser.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_Cpp_CppPARSERTD_H_
#define WCI_FRONTEND_Cpp_CppPARSERTD_H_

#include "../Parser.h"
#include "../cpp/CppErrorHandler.h"
#include "../Scanner.h"

namespace wci { namespace frontend { namespace cpp {

using namespace std;
using namespace wci::frontend;

class CppParserTD : public Parser
{
public:
    /**
     * Constructor.
     * @param scanner the scanner to be used with this parser.
     */
    CppParserTD(Scanner *scanner);

    /**
     * Constructor for subclasses.
     * @param parent the parent parser.
     */
    CppParserTD(CppParserTD *parent);

    /**
     * Parse a Cpp source program and generate the symbol table
     * and the intermediate code.
     * Implementation of wci::frontend::Parser.
     * @throw a string message if an error occurred.
     */
    void parse() throw (string);

    /**
     * Return the number of syntax errors found by the parser.
     * Implementation of wci::frontend::Parser.
     * @return the error count.
     */
    int get_error_count() const;

protected:
    static CppErrorHandler error_handler;
};

}}} // namespace wci::frontend::Cpp


#endif /* WCI_FRONTEND_Cpp_CppPARSERTD_H_ */
