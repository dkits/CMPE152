/**
 * <h1>CppToken</h1>
 *
 * <p>Base class for Cpp token classes.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "../cpp/CppToken.h"

#include <string>
#include <vector>
#include <map>

namespace wci { namespace frontend { namespace cpp {

using namespace std;

map<string, CppTokenType> CppToken::RESERVED_WORDS;
map<string, CppTokenType> CppToken::SPECIAL_SYMBOLS;
map<CppTokenType, string> CppToken::SPECIAL_SYMBOL_NAMES;


bool CppToken::INITIALIZED = false;

void CppToken::initialize()
{
    if (INITIALIZED) return;

    vector<string> rw_strings =
    {
       /* "AND", "ARRAY", "BEGIN", "CASE", "CONST", "DIV", "DO", "DOWNTO",
        "ELSE", "END", "FILE", "FOR", "FUNCTION", "GOTO", "IF", "IN",
        "LABEL", "MOD", "NIL", "NOT", "OF", "OR", "PACKED", "PROCEDURE",
        "PROGRAM", "RECORD", "REPEAT", "SET", "THEN", "TO", "TYPE",
        "UNTIL", "VAR", "WHILE", "with",*/
    		"and","auto", "double", "int", "struct", "break", "else", "long", "switch",
			"case", "enum", "namespace", "template", "char", "extern", "operator", "this",
			"class", "float", "protected", "throw", "const", "for", "public", "union",
			"continue", "goto", "return", "void", "do", "if", "static",
			"while",

    };

    vector<CppTokenType> rw_keys =
    {
//uppercase

            CppTokenType::AUTO,
            CppTokenType::DOUBLE,
            CppTokenType::INT,
            CppTokenType::STRUCT,
            CppTokenType::BREAK,
            CppTokenType::ELSE,
            CppTokenType::LONG,
            CppTokenType::SWITCH,
            CppTokenType::CASE,
            CppTokenType::ENUM,
            CppTokenType::NAMESPACE,
            CppTokenType::TEMPLATE,
            CppTokenType::CHAR,
            CppTokenType::EXTERN,
            CppTokenType::OPERATOR,
            CppTokenType::THIS,
            CppTokenType::CLASS,
            CppTokenType::FLOAT,
            CppTokenType::PROTECTED,
            CppTokenType::THROW,
            CppTokenType::CONST,
            CppTokenType::FOR,
            CppTokenType::PUBLIC,
            CppTokenType::UNION,
            CppTokenType::CONTINUE,
            CppTokenType::GOTO,
            CppTokenType::RETURN,
            CppTokenType::VOID,
            CppTokenType::DO,
            CppTokenType::IF,
            CppTokenType::STATIC,
            CppTokenType::WHILE,

        /*
        CppTokenType::AND,
        CppTokenType::ARRAY,
        CppTokenType::BEGIN,
        CppTokenType::CASE,
        CppTokenType::CONST,
        CppTokenType::DIV,
        CppTokenType::DO,
        CppTokenType::DOWNTO,

        CppTokenType::ELSE,
        CppTokenType::END,
        CppTokenType::FILE,
        CppTokenType::FOR,
        CppTokenType::FUNCTION,
        CppTokenType::GOTO,
        CppTokenType::IF,
        CppTokenType::IN,

        CppTokenType::LABEL,
        CppTokenType::MOD,
        CppTokenType::NIL,
        CppTokenType::NOT,
        CppTokenType::OF,
        CppTokenType::OR,
        CppTokenType::PACKED,
        CppTokenType::PROCEDURE,

        CppTokenType::PROGRAM,
        CppTokenType::RECORD,
        CppTokenType::REPEAT,
        CppTokenType::SET,
        CppTokenType::THEN,
        CppTokenType::TO,
        CppTokenType::TYPE,

        CppTokenType::UNTIL,
        CppTokenType::VAR,
        CppTokenType::WHILE,
        CppTokenType::WITH,*/
    };

    for (int i = 0; i < rw_strings.size(); i++)
    {
        RESERVED_WORDS[rw_strings[i]] = rw_keys[i];
    }

    vector<string> ss_strings =


    {   "~", "!", "@", "%", "^", "&", "|",
    	"++", "--", ">>", "<<","+=", "-=", "*=", "/=", "==", "|=",
		"%=", "&=", "^=", "!=", "<<=", ">>=", "||", "&&",


        "+", "-", "*", "/", ":=", ".", ",", ";", ":", "=", "<>",
        "<", "<=", ">=", ">", "(", ")", "[", "]", "{", "}",  "^", "..", "?" , "\\" ,"\'", "\"", "\\\'",
    };

    vector<CppTokenType> ss_keys =
    {
        CppTokenType::TILDE,
		CppTokenType::EXCLAMATION,
		CppTokenType::AT,
		CppTokenType::PERCENT,
		CppTokenType::CARET,
		CppTokenType::AMPERSAND,
		CppTokenType::VERTICAL_BAR,

		CppTokenType::INCREMENT,
		CppTokenType::DECREMENT,
		CppTokenType::LEFT_SHIFT,
		CppTokenType::RIGHT_SHIFT,
		CppTokenType::ADDITION,
		CppTokenType::SUBTRACTION,
		CppTokenType::MULTIPLICATION,
		CppTokenType::DIVISION,
		CppTokenType::EQUAL,
		CppTokenType::OR,
		CppTokenType::REMAINDER,
		CppTokenType::AND,
		CppTokenType::CARET_EQUAL,
		CppTokenType::NOT_EQUAL,
		CppTokenType::SHIFT_LEFT,
		CppTokenType::SHIFT_RIGHT,
		CppTokenType::OR_EQUAL,
		CppTokenType::AND_EQUAL,




        CppTokenType::PLUS,
        CppTokenType::MINUS,
        CppTokenType::STAR,
        CppTokenType::SLASH,
        CppTokenType::COLON_EQUALS,
        CppTokenType::DOT,
        CppTokenType::COMMA,
        CppTokenType::SEMICOLON,
        CppTokenType::COLON,

        CppTokenType::EQUALS,
        CppTokenType::NOT_EQUALS,

        CppTokenType::LESS_THAN,
        CppTokenType::LESS_EQUALS,
        CppTokenType::GREATER_EQUALS,
        CppTokenType::GREATER_THAN,
        CppTokenType::LEFT_PAREN,
        CppTokenType::RIGHT_PAREN,
        CppTokenType::LEFT_BRACKET,
        CppTokenType::RIGHT_BRACKET,
        CppTokenType::LEFT_BRACE,
        CppTokenType::RIGHT_BRACE,
        CppTokenType::UP_ARROW,
        CppTokenType::DOT_DOT,
		CppTokenType::QUESTION_MARK,
		CppTokenType::BACKSLASH,
		CppTokenType::APOSTROPHE,
		CppTokenType::DOUBLE_QUOTE,
		CppTokenType::BACKSLASH_APOSTROPHE,
    };

    for (int i = 0; i < ss_strings.size(); i++)
    {
        SPECIAL_SYMBOLS[ss_strings[i]] = ss_keys[i];
    }

    vector<string> ss_names =
    {
    "TILDE", "EXCLAMATION", "AT", "PERCENT", "CARET", "AMPERSAND",
	"VERTICAL_BAR",
	"INCREMENT", "DECREMENT", "LEFT_SHIFT", "RIGHT_SHIFT", "ADDITION",
	"SUBTRACTION", "MULTIPLICATION", "DIVISION", "EQUAL", "OR",
	"REMAINDER", "AND", "CARET_EQUAL", "NOT_EQUAL", "SHIFT_LEFT", "SHIFT_RIGHT", "OR_EQUAL",
	"AND_EQUAL",




        "PLUS", "MINUS", "STAR", "SLASH", "COLON_EQUALS", "DOT", "COMMA",
        "SEMICOLON", "COLON", "EQUALS", "NOT_EQUALS",

        "LESS_THAN", "LESS_EQUALS", "GREATER_EQUALS", "GREATER_THAN",
        "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET",
        "LEFT_BRACE", "RIGHT_BRACE", "UP_ARROW", "DOT_DOT", "QUESTION_MARK", "BACKSLASH", "APOSTROPHE", "DOUBLE_QUOTE"
		,"BACKSLASH_APOSTROPHE",
    };

    for (int i = 0; i < ss_names.size(); i++)
    {
        SPECIAL_SYMBOL_NAMES[ss_keys[i]] = ss_names[i];
    }

    INITIALIZED = true;
}

CppToken::CppToken(Source *source) throw (string)
    : Token(source)
{
    initialize();
}

}}}  // namespace wci::frontend::Cpp
