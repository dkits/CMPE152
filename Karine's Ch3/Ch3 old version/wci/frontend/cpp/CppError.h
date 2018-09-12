/**
 * <h1>CppError</h1>
 *
 * <p>Cpp translation errors.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_Cpp_CppERROR_H_
#define WCI_FRONTEND_Cpp_CppERROR_H_

#include <string>
#include <map>

namespace wci { namespace frontend { namespace cpp {

using namespace std;

/**
 * Cpp error codes.
 */
enum class CppErrorCode
{
    ALREADY_FORWARDED,
    CASE_CONSTANT_REUSED,
    IDENTIFIER_REDEFINED,
    IDENTIFIER_UNDEFINED,
    INCOMPATIBLE_ASSIGNMENT,
    INCOMPATIBLE_TYPES,
    INVALID_ASSIGNMENT,
    INVALID_CHARACTER,
    INVALID_CONSTANT,
    INVALID_EXPONENT,
    INVALID_EXPRESSION,
    INVALID_FIELD,
    INVALID_FRACTION,
    INVALID_IDENTIFIER_USAGE,
    INVALID_INDEX_TYPE,
    INVALID_NUMBER,
    INVALID_STATEMENT,
    INVALID_SUBRANGE_TYPE,
    INVALID_TARGET,
    INVALID_TYPE,
    INVALID_VAR_PARM,
    MIN_GT_MAX,
    MISSING_BEGIN,
    MISSING_COLON,
    MISSING_COLON_EQUALS,
    MISSING_COMMA,
    MISSING_CONSTANT,
    MISSING_DO,
    MISSING_DOT_DOT,
    MISSING_END,
    MISSING_EQUALS,
    MISSING_FOR_CONTROL,
    MISSING_IDENTIFIER,
    MISSING_LEFT_BRACKET,
    MISSING_OF,
    MISSING_PERIOD,
    MISSING_PROGRAM,
    MISSING_RIGHT_BRACKET,
    MISSING_RIGHT_PAREN,
    MISSING_SEMICOLON,
    MISSING_THEN,
    MISSING_TO_DOWNTO,
    MISSING_UNTIL,
    MISSING_VARIABLE,
    NOT_CONSTANT_IDENTIFIER,
    NOT_RECORD_VARIABLE,
    NOT_TYPE_IDENTIFIER,
    RANGE_INTEGER,
    RANGE_REAL,
    STACK_OVERFLOW,
    TOO_MANY_LEVELS,
    TOO_MANY_SUBSCRIPTS,
    UNEXPECTED_EOF,
    UNEXPECTED_TOKEN,
    UNIMPLEMENTED,
    UNRECOGNIZABLE,
    WRONG_NUMBER_OF_PARMS,

    // Fatal errors.
    IO_ERROR,
    TOO_MANY_ERRORS
};

constexpr CppErrorCode ALREADY_FORWARDED = CppErrorCode::ALREADY_FORWARDED;
constexpr CppErrorCode CASE_CONSTANT_REUSED = CppErrorCode::CASE_CONSTANT_REUSED;
constexpr CppErrorCode IDENTIFIER_REDEFINED = CppErrorCode::IDENTIFIER_REDEFINED;
constexpr CppErrorCode IDENTIFIER_UNDEFINED = CppErrorCode::IDENTIFIER_UNDEFINED;
constexpr CppErrorCode INCOMPATIBLE_ASSIGNMENT = CppErrorCode::INCOMPATIBLE_ASSIGNMENT;
constexpr CppErrorCode INCOMPATIBLE_TYPES = CppErrorCode::INCOMPATIBLE_TYPES;
constexpr CppErrorCode INVALID_ASSIGNMENT = CppErrorCode::INVALID_ASSIGNMENT;
constexpr CppErrorCode INVALID_CHARACTER = CppErrorCode::INVALID_CHARACTER;
constexpr CppErrorCode INVALID_CONSTANT = CppErrorCode::INVALID_CONSTANT;
constexpr CppErrorCode INVALID_EXPONENT = CppErrorCode::INVALID_EXPONENT;
constexpr CppErrorCode INVALID_EXPRESSION = CppErrorCode::INVALID_EXPRESSION;
constexpr CppErrorCode INVALID_FIELD = CppErrorCode::INVALID_FIELD;
constexpr CppErrorCode INVALID_FRACTION = CppErrorCode::INVALID_FRACTION;
constexpr CppErrorCode INVALID_IDENTIFIER_USAGE = CppErrorCode::INVALID_IDENTIFIER_USAGE;
constexpr CppErrorCode INVALID_INDEX_TYPE = CppErrorCode::INVALID_INDEX_TYPE;
constexpr CppErrorCode INVALID_NUMBER = CppErrorCode::INVALID_NUMBER;
constexpr CppErrorCode INVALID_STATEMENT = CppErrorCode::INVALID_STATEMENT;
constexpr CppErrorCode INVALID_SUBRANGE_TYPE = CppErrorCode::INVALID_SUBRANGE_TYPE;
constexpr CppErrorCode INVALID_TARGET = CppErrorCode::INVALID_TARGET;
constexpr CppErrorCode INVALID_TYPE = CppErrorCode::INVALID_TYPE;
constexpr CppErrorCode INVALID_VAR_PARM = CppErrorCode::INVALID_VAR_PARM;
constexpr CppErrorCode MIN_GT_MAX = CppErrorCode::MIN_GT_MAX;
constexpr CppErrorCode MISSING_BEGIN = CppErrorCode::MISSING_BEGIN;
constexpr CppErrorCode MISSING_COLON = CppErrorCode::MISSING_COLON;
constexpr CppErrorCode MISSING_COMMA = CppErrorCode::MISSING_COMMA;
constexpr CppErrorCode MISSING_CONSTANT = CppErrorCode::MISSING_CONSTANT;
constexpr CppErrorCode MISSING_DO = CppErrorCode::MISSING_DO;
constexpr CppErrorCode MISSING_DOT_DOT = CppErrorCode::MISSING_DOT_DOT;
constexpr CppErrorCode MISSING_END = CppErrorCode::MISSING_END;
constexpr CppErrorCode MISSING_EQUALS = CppErrorCode::MISSING_EQUALS;
constexpr CppErrorCode MISSING_COLON_EQUALS = CppErrorCode::MISSING_COLON_EQUALS;
constexpr CppErrorCode MISSING_FOR_CONTROL = CppErrorCode::MISSING_FOR_CONTROL;
constexpr CppErrorCode MISSING_IDENTIFIER = CppErrorCode::MISSING_IDENTIFIER;
constexpr CppErrorCode MISSING_LEFT_BRACKET = CppErrorCode::MISSING_LEFT_BRACKET;
constexpr CppErrorCode MISSING_OF = CppErrorCode::MISSING_OF;
constexpr CppErrorCode MISSING_PERIOD = CppErrorCode::MISSING_PERIOD;
constexpr CppErrorCode MISSING_PROGRAM = CppErrorCode::MISSING_PROGRAM;
constexpr CppErrorCode MISSING_RIGHT_BRACKET = CppErrorCode::MISSING_RIGHT_BRACKET;
constexpr CppErrorCode MISSING_RIGHT_PAREN = CppErrorCode::MISSING_RIGHT_PAREN;
constexpr CppErrorCode MISSING_SEMICOLON = CppErrorCode::MISSING_SEMICOLON;
constexpr CppErrorCode MISSING_THEN = CppErrorCode::MISSING_THEN;
constexpr CppErrorCode MISSING_TO_DOWNTO = CppErrorCode::MISSING_TO_DOWNTO;
constexpr CppErrorCode MISSING_UNTIL = CppErrorCode::MISSING_UNTIL;
constexpr CppErrorCode MISSING_VARIABLE = CppErrorCode::MISSING_VARIABLE;
constexpr CppErrorCode NOT_CONSTANT_IDENTIFIER = CppErrorCode::NOT_CONSTANT_IDENTIFIER;
constexpr CppErrorCode NOT_RECORD_VARIABLE = CppErrorCode::NOT_RECORD_VARIABLE;
constexpr CppErrorCode NOT_TYPE_IDENTIFIER = CppErrorCode::NOT_TYPE_IDENTIFIER;
constexpr CppErrorCode RANGE_INTEGER = CppErrorCode::RANGE_INTEGER;
constexpr CppErrorCode RANGE_REAL = CppErrorCode::RANGE_REAL;
constexpr CppErrorCode STACK_OVERFLOW = CppErrorCode::STACK_OVERFLOW;
constexpr CppErrorCode TOO_MANY_LEVELS = CppErrorCode::TOO_MANY_LEVELS;
constexpr CppErrorCode TOO_MANY_SUBSCRIPTS = CppErrorCode::TOO_MANY_SUBSCRIPTS;
constexpr CppErrorCode UNEXPECTED_EOF = CppErrorCode::UNEXPECTED_EOF;
constexpr CppErrorCode UNEXPECTED_TOKEN = CppErrorCode::UNEXPECTED_TOKEN;
constexpr CppErrorCode UNIMPLEMENTED = CppErrorCode::UNIMPLEMENTED;
constexpr CppErrorCode UNRECOGNIZABLE = CppErrorCode::UNRECOGNIZABLE;
constexpr CppErrorCode WRONG_NUMBER_OF_PARMS = CppErrorCode::WRONG_NUMBER_OF_PARMS;

constexpr CppErrorCode IO_ERROR = CppErrorCode::IO_ERROR;
constexpr CppErrorCode TOO_MANY_ERRORS = CppErrorCode::TOO_MANY_ERRORS;

class CppError
{
public:
    static map<CppErrorCode, string> SYNTAX_ERROR_MESSAGES;

    /**
     * Initialize the static map.
     */
    static void initialize();

private:
    static bool INITIALIZED;
};

}}}  // namespace wci::frontend::Cpp

#endif /* WCI_FRONTEND_Cpp_CppERROR_H_ */
