/**
 * <h1>CppError</h1>
 *
 * <p>Cpp translation errors.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "../cpp/CppError.h"

#include <string>
#include <vector>
#include <map>

namespace wci { namespace frontend { namespace cpp {

using namespace std;

bool CppError::INITIALIZED = false;

map<CppErrorCode, string> CppError::SYNTAX_ERROR_MESSAGES;

void CppError::initialize()
{
    if (INITIALIZED) return;

    vector<CppErrorCode> error_codes =
    {
        CppErrorCode::ALREADY_FORWARDED,
        CppErrorCode::CASE_CONSTANT_REUSED,
        CppErrorCode::IDENTIFIER_REDEFINED,
        CppErrorCode::IDENTIFIER_UNDEFINED,
        CppErrorCode::INCOMPATIBLE_ASSIGNMENT,
        CppErrorCode::INCOMPATIBLE_TYPES,
        CppErrorCode::INVALID_ASSIGNMENT,
        CppErrorCode::INVALID_CHARACTER,
        CppErrorCode::INVALID_CONSTANT,
        CppErrorCode::INVALID_EXPONENT,
        CppErrorCode::INVALID_EXPRESSION,
        CppErrorCode::INVALID_FIELD,
        CppErrorCode::INVALID_FRACTION,
        CppErrorCode::INVALID_IDENTIFIER_USAGE,
        CppErrorCode::INVALID_INDEX_TYPE,
        CppErrorCode::INVALID_NUMBER,
        CppErrorCode::INVALID_STATEMENT,
        CppErrorCode::INVALID_SUBRANGE_TYPE,
        CppErrorCode::INVALID_TARGET,
        CppErrorCode::INVALID_TYPE,
        CppErrorCode::INVALID_VAR_PARM,
        CppErrorCode::MIN_GT_MAX,
        CppErrorCode::MISSING_BEGIN,
        CppErrorCode::MISSING_COLON,
        CppErrorCode::MISSING_COLON_EQUALS,
        CppErrorCode::MISSING_COMMA,
        CppErrorCode::MISSING_CONSTANT,
        CppErrorCode::MISSING_DO,
        CppErrorCode::MISSING_DOT_DOT,
        CppErrorCode::MISSING_END,
        CppErrorCode::MISSING_EQUALS,
        CppErrorCode::MISSING_FOR_CONTROL,
        CppErrorCode::MISSING_IDENTIFIER,
        CppErrorCode::MISSING_LEFT_BRACKET,
        CppErrorCode::MISSING_OF,
        CppErrorCode::MISSING_PERIOD,
        CppErrorCode::MISSING_PROGRAM,
        CppErrorCode::MISSING_RIGHT_BRACKET,
        CppErrorCode::MISSING_RIGHT_PAREN,
        CppErrorCode::MISSING_SEMICOLON,
        CppErrorCode::MISSING_THEN,
        CppErrorCode::MISSING_TO_DOWNTO,
        CppErrorCode::MISSING_UNTIL,
        CppErrorCode::MISSING_VARIABLE,
        CppErrorCode::NOT_CONSTANT_IDENTIFIER,
        CppErrorCode::NOT_RECORD_VARIABLE,
        CppErrorCode::NOT_TYPE_IDENTIFIER,
        CppErrorCode::RANGE_INTEGER,
        CppErrorCode::RANGE_REAL,
        CppErrorCode::STACK_OVERFLOW,
        CppErrorCode::TOO_MANY_LEVELS,
        CppErrorCode::TOO_MANY_SUBSCRIPTS,
        CppErrorCode::UNEXPECTED_EOF,
        CppErrorCode::UNEXPECTED_TOKEN,
        CppErrorCode::UNIMPLEMENTED,
        CppErrorCode::UNRECOGNIZABLE,
        CppErrorCode::WRONG_NUMBER_OF_PARMS,

        // Fatal errors.
        CppErrorCode::IO_ERROR,
        CppErrorCode::TOO_MANY_ERRORS
    };

    vector<string> error_messages =
    {
        "Already specified in FORWARD",
        "CASE constant reused",
        "Redefined identifier",
        "Undefined identifier",
        "Incompatible assignment",
        "Incompatible types",
        "Invalid assignment statement",
        "Invalid character",
        "Invalid constant",
        "Invalid exponent",
        "Invalid expression",
        "Invalid field",
        "Invalid fraction",
        "Invalid identifier usage",
        "Invalid index type",
        "Invalid number",
        "Invalid statement",
        "Invalid subrange type",
        "Invalid assignment target",
        "Invalid type",
        "Invalid VAR parameter",
        "Min limit greater than max limit",
        "Missing BEGIN",
        "Missing :",
        "Missing :=",
        "Missing ,",
        "Missing constant",
        "Missing DO",
        "Missing ..",
        "Missing END",
        "Missing =",
        "Invalid FOR control variable",
        "Missing identifier",
        "Missing [",
        "Missing OF",
        "Missing .",
        "Missing PROGRAM",
        "Missing ]",
        "Missing )",
        "Missing ;",
        "Missing THEN",
        "Missing TO or DOWNTO",
        "Missing UNTIL",
        "Missing variable",
        "Not a constant identifier",
        "Not a record variable",
        "Not a type identifier",
        "Integer literal out of range",
        "Real literal out of range",
        "Stack overflow",
        "Nesting level too deep",
        "Too many subscripts",
        "Unexpected end of file",
        "Unexpected token",
        "Unimplemented feature",
        "Unrecognizable input",
        "Wrong number of actual parameters",

        // Fatal errors.
        "Object I/O error",
        "Too many syntax errors"
    };

    for (int i = 0; i < error_codes.size(); i++)
    {
        SYNTAX_ERROR_MESSAGES[error_codes[i]] = error_messages[i];
    }

    INITIALIZED = true;
}

}}}  // namespace wci::frontend::Cpp
