/**
 * <h1>FrontendFactory</h1>
 *
 * <p>A factory class that creates parsers for specific source languages.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include "FrontendFactory.h"

#include "Parser.h"
#include "cpp/CppParserTD.h"
#include "cpp/CppScanner.h"
#include "Scanner.h"
#include "Source.h"

namespace wci { namespace frontend {

using namespace wci::frontend::cpp;

Parser *FrontendFactory::create_parser(string language, string type,
                                       Source *source)
    throw (string)
{
    if ((language == "Cpp") && (type == "top-down"))
    {
        Scanner *scanner = new CppScanner(source);
        return new CppParserTD(scanner);
    }
    else if (language != "Cpp") {
        throw new string("Parser factory: Invalid language '" +
                         language + "'");
    }
    else {
        throw new string("Parser factory: Invalid type '" +
                         type + "'");
    }
}

}} // namespace wci::cpp
