/**
 * <h1>CppToken</h1>
 *
 * <p>Base class for Cpp token classes.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */

#ifndef WCI_FRONTEND_CPP_CppTOKEN_H_
#define WCI_FRONTEND_CPP_CppTOKEN_H_

#include <string>
#include <map>
#include "../Token.h"
#include "../Source.h"

namespace wci { namespace frontend { namespace cpp {

using namespace std;
using namespace wci::frontend;

/**
 * Cpp token types.
 */
enum class CppTokenType
{
    // Reserved words.
  /*  AND, ARRAY, BEGIN, CASE, CONST, DIV, DO, DOWNTO, ELSE, END,
    FILE, FOR, FUNCTION, GOTO, IF, IN, LABEL, MOD, NIL, NOT,
    OF, OR, PACKED, PROCEDURE, PROGRAM, RECORD, REPEAT, SET,
    THEN, TO, TYPE, UNTIL, VAR, WHILE, WITH,
	AND,*/
	AUTO, DOUBLE, INT, STRUCT, BREAK, ELSE, LONG, SWITCH,
	CASE, ENUM, NAMESPACE, TEMPLATE, CHAR, EXTERN, OPERATOR, THIS,
	CLASS, FLOAT, PROTECTED, THROW, CONST, FOR, PUBLIC, UNION,
	CONTINUE, GOTO, RETURN, VOID, DO, IF, STATIC, WHILE,

    // Special symbols.
	TILDE, EXCLAMATION, AT, PERCENT, CARET, AMPERSAND, VERTICAL_BAR,
	INCREMENT,
	DECREMENT, LEFT_SHIFT, RIGHT_SHIFT, ADDITION, SUBTRACTION,
	MULTIPLICATION, DIVISION, EQUAL, OR, REMAINDER,
	AND, CARET_EQUAL, NOT_EQUAL,SHIFT_LEFT, SHIFT_RIGHT, OR_EQUAL, AND_EQUAL,

    PLUS, MINUS, STAR, SLASH, COLON_EQUALS,
    DOT, COMMA, SEMICOLON, COLON,
    EQUALS, NOT_EQUALS, LESS_THAN, LESS_EQUALS,
    GREATER_EQUALS, GREATER_THAN, LEFT_PAREN, RIGHT_PAREN,
    LEFT_BRACKET, RIGHT_BRACKET, LEFT_BRACE, RIGHT_BRACE,
    UP_ARROW, DOT_DOT, QUESTION_MARK, BACKSLASH, APOSTROPHE, DOUBLE_QUOTE, BACKSLASH_APOSTROPHE,



    RESERVED_WORDS,IDENTIFIER, INTEGER, REAL, STRING,
    ERROR, END_OF_FILE,
};

//For renaming
/*auto, double, int, struct, break, else, long, switch,
    		        case, enum, namespace, template, char, extern, operator, this,
    		        class, float, protected, throw, const, for, public, union,
    		        continue, goto, return, void, do, if, static,
    		        while */

		constexpr CppTokenType PT_tilde = CppTokenType::TILDE;
		constexpr CppTokenType PT_exclamation = CppTokenType::EXCLAMATION;
		constexpr CppTokenType PT_at = CppTokenType::AT;
		constexpr CppTokenType PT_percent = CppTokenType::PERCENT;
		constexpr CppTokenType PT_caret = CppTokenType::CARET;
		constexpr CppTokenType PT_ampersand = CppTokenType::AMPERSAND;
		constexpr CppTokenType PT_vertical_bar = CppTokenType::VERTICAL_BAR;
        constexpr CppTokenType PT_increment = CppTokenType::INCREMENT;
		constexpr CppTokenType PT_decrement = CppTokenType::DECREMENT;
		constexpr CppTokenType PT_left_shift = CppTokenType::LEFT_SHIFT;
		constexpr CppTokenType PT_right_shift = CppTokenType::RIGHT_SHIFT;
		constexpr CppTokenType PT_addition = CppTokenType::ADDITION;
		constexpr CppTokenType PT_subtraction = CppTokenType::SUBTRACTION;
		constexpr CppTokenType PT_multiplication = CppTokenType::MULTIPLICATION;
		constexpr CppTokenType PT_division = CppTokenType::DIVISION;
		constexpr CppTokenType PT_equal = CppTokenType::EQUAL;
		constexpr CppTokenType PT_or = CppTokenType::OR;
		constexpr CppTokenType PT_remainder = CppTokenType::REMAINDER;
		constexpr CppTokenType PT_and = CppTokenType::AND;
		constexpr CppTokenType PT_caret_equal = CppTokenType::CARET_EQUAL;
		constexpr CppTokenType PT_not_equal = CppTokenType::NOT_EQUAL;
		constexpr CppTokenType PT_shift_left = CppTokenType::SHIFT_LEFT;
		constexpr CppTokenType PT_shift_right = CppTokenType::SHIFT_RIGHT;
		constexpr CppTokenType PT_or_equal = CppTokenType::OR_EQUAL;
		constexpr CppTokenType PT_and_equal = CppTokenType::AND_EQUAL;

constexpr CppTokenType PT_auto = CppTokenType::AUTO;
constexpr CppTokenType PT_double = CppTokenType::DOUBLE;
constexpr CppTokenType PT_int = CppTokenType::INT;
constexpr CppTokenType PT_struct = CppTokenType::STRUCT;
constexpr CppTokenType PT_break = CppTokenType::BREAK;
constexpr CppTokenType PT_else = CppTokenType::ELSE;
constexpr CppTokenType PT_long = CppTokenType::LONG;
constexpr CppTokenType PT_switch = CppTokenType::SWITCH;

constexpr CppTokenType PT_case = CppTokenType::CASE;
constexpr CppTokenType PT_enum = CppTokenType::ENUM;
constexpr CppTokenType PT_namespace = CppTokenType::NAMESPACE;
constexpr CppTokenType PT_template = CppTokenType::TEMPLATE;
constexpr CppTokenType PT_char = CppTokenType::CHAR;
constexpr CppTokenType PT_extern = CppTokenType::EXTERN;
constexpr CppTokenType PT_operator = CppTokenType::OPERATOR;
constexpr CppTokenType PT_this = CppTokenType::THIS;

constexpr CppTokenType PT_class = CppTokenType::CLASS;
constexpr CppTokenType PT_float = CppTokenType::FLOAT;
constexpr CppTokenType PT_protected = CppTokenType::PROTECTED;
constexpr CppTokenType PT_throw = CppTokenType::THROW;
constexpr CppTokenType PT_const = CppTokenType::CONST;
constexpr CppTokenType PT_for = CppTokenType::FOR;
constexpr CppTokenType PT_public = CppTokenType::PUBLIC;
constexpr CppTokenType PT_PROCEDURE = CppTokenType::UNION;

constexpr CppTokenType PT_PROGRAM = CppTokenType::CONTINUE;
constexpr CppTokenType PT_RECORD = CppTokenType::GOTO;
constexpr CppTokenType PT_REPEAT = CppTokenType::PROTECTED;
constexpr CppTokenType PT_SET = CppTokenType::THROW;
constexpr CppTokenType PT_THEN = CppTokenType::CONST;
constexpr CppTokenType PT_TO = CppTokenType::FOR;
constexpr CppTokenType PT_TYPE = CppTokenType::PUBLIC;

constexpr CppTokenType PT_UNTIL = CppTokenType::UNION;
constexpr CppTokenType PT_VAR = CppTokenType::CONTINUE;
constexpr CppTokenType PT_WHILE = CppTokenType::GOTO;
constexpr CppTokenType PT_WITH = CppTokenType::VOID;






constexpr CppTokenType PT_PLUS = CppTokenType::PLUS;
constexpr CppTokenType PT_MINUS = CppTokenType::MINUS;
constexpr CppTokenType PT_STAR = CppTokenType::STAR;
constexpr CppTokenType PT_SLASH = CppTokenType::SLASH;
constexpr CppTokenType PT_COLON_EQUALS = CppTokenType::COLON_EQUALS;
constexpr CppTokenType PT_DOT = CppTokenType::DOT;
constexpr CppTokenType PT_COMMA = CppTokenType::COMMA;
constexpr CppTokenType PT_SEMICOLON = CppTokenType::SEMICOLON;
constexpr CppTokenType PT_COLON = CppTokenType::COLON;

constexpr CppTokenType PT_EQUALS = CppTokenType::EQUALS;
constexpr CppTokenType PT_NOT_EQUALS = CppTokenType::NOT_EQUALS;

constexpr CppTokenType PT_LESS_THAN = CppTokenType::LESS_THAN;
constexpr CppTokenType PT_LESS_EQUALS = CppTokenType::LESS_EQUALS;
constexpr CppTokenType PT_GREATER_EQUALS = CppTokenType::GREATER_EQUALS;
constexpr CppTokenType PT_GREATER_THAN = CppTokenType::GREATER_THAN;
constexpr CppTokenType PT_LEFT_PAREN = CppTokenType::LEFT_PAREN;
constexpr CppTokenType PT_RIGHT_PAREN = CppTokenType::RIGHT_PAREN;
constexpr CppTokenType PT_LEFT_BRACKET = CppTokenType::LEFT_BRACKET;
constexpr CppTokenType PT_RIGHT_BRACKET = CppTokenType::RIGHT_BRACKET;
constexpr CppTokenType PT_LEFT_BRACE = CppTokenType::LEFT_BRACE;
constexpr CppTokenType PT_RIGHT_BRACE = CppTokenType::RIGHT_BRACE;
constexpr CppTokenType PT_UP_ARROW = CppTokenType::UP_ARROW;
constexpr CppTokenType PT_DOT_DOT = CppTokenType::DOT_DOT;
constexpr CppTokenType PT_QUESTION_MARK = CppTokenType::QUESTION_MARK;
constexpr CppTokenType PT_BACKSLASH = CppTokenType::BACKSLASH;
constexpr CppTokenType PT_APOSTROPHE = CppTokenType::APOSTROPHE;
constexpr CppTokenType PT_DOUBLE_QUOTE = CppTokenType::DOUBLE_QUOTE;
constexpr CppTokenType PT_BACKSLASH_APOSTROPHE = CppTokenType::BACKSLASH_APOSTROPHE;
constexpr CppTokenType PT_IDENTIFIER = CppTokenType::IDENTIFIER;
constexpr CppTokenType PT_RESERVED_WORDS = CppTokenType::RESERVED_WORDS;
constexpr CppTokenType PT_INTEGER = CppTokenType::INTEGER;
constexpr CppTokenType PT_REAL = CppTokenType::REAL;
constexpr CppTokenType PT_STRING = CppTokenType::STRING;
constexpr CppTokenType PT_ERROR = CppTokenType::ERROR;
constexpr CppTokenType PT_END_OF_FILE = CppTokenType::END_OF_FILE;

class CppToken : public Token
{
public:
    static map<string, CppTokenType> RESERVED_WORDS;
    static map<string, CppTokenType> SPECIAL_SYMBOLS;
    static map<CppTokenType, string> SPECIAL_SYMBOL_NAMES;

protected:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    CppToken(Source *source) throw (string);

private:
    static bool INITIALIZED;

    /**
     * Initialize the static maps.
     */
    static void initialize();
};

}}}  // namespace wci::frontend::Cpp

#endif /* WCI_FRONTEND_CPP_CppTOKEN_H_ */
