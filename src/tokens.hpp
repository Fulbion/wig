#ifndef TOKENS_HPP
#define TOKENS_HPP

enum TokenKind {
	// Keywords
	TOKEN_BREAK, // break
	TOKEN_CASE, // case
	TOKEN_CHAR, // char
	TOKEN_CLASS, // class
	TOKEN_CONST, // const
	TOKEN_CONTINUE, // continue
	TOKEN_DEFAULT, // default
	TOKEN_DO, // do
	TOKEN_ELSE, // else
	TOKEN_ENUM, // enum
	TOKEN_FALSE, // false
	TOKEN_FLOAT, // float
	TOKEN_FOR, // for
	TOKEN_IF, // if
	TOKEN_INT, // int
	TOKEN_MUT, // mut
	TOKEN_RETURN, // return
	TOKEN_SIZEOF, // sizeof
	TOKEN_STRUCT, // struct
	TOKEN_SWITCH, // switch
	TOKEN_TRUE, // true
	TOKEN_TYPEOF, // typeof
	TOKEN_VOID, // void
	TOKEN_WHILE, // while

	// Operators

	TOKEN_LPAREN, // (
	TOKEN_RPAREN, // )
	TOKEN_LBRACKET, // [
	TOKEN_RBRACKET, // ]
	TOKEN_LBRACE, // {
	TOKEN_RBRACE, // }

	TOKEN_LESS, // <
	TOKEN_LESS_EQUAL, // <=
	TOKEN_GREATER, // >
	TOKEN_GREATER_EQUAL, // >=
	TOKEN_LSHIFT, // <<
	TOKEN_RSHIFT, // >>

	TOKEN_PLUS, // +
	TOKEN_PLUS_PLUS, // ++
	TOKEN_MINUS, // -
	TOKEN_MINUS_MINUS, // --
	TOKEN_MIN, // *
	TOKEN_DIV, // /
	TOKEN_MOD, // %

	TOKEN_AND, // &
	TOKEN_OR, // |
	TOKEN_AND_AND, // &&
	TOKEN_OR_OR, // ||
	TOKEN_CARET, // ^
	TOKEN_NOT, // !
	TOKEN_TILDE, // ~

	TOKEN_QUESTION, // ?
	TOKEN_COLON, // :
	TOKEN_SEMI, // ;
	TOKEN_COMMA, // ,

	TOKEN_ASSIGN, // ::
	TOKEN_STAR_ASSIGN, // *::
	TOKEN_DIV_ASSIGN, // /::
	TOKEN_MOD_ASSIGN, // %::
	TOKEN_PLUS_ASSIGN, // +::
	TOKEN_MINUS_ASSIGN, // -::
	TOKEN_LSHIFT_ASSIGN, // <<::
	TOKEN_RSHIFT_ASSIGN, // >>::
	TOKEN_AND_ASSIGN, // &::
	TOKEN_OR_ASSIGN, // |::
	TOKEN_CARET_ASSIGN, // ^::
	
	TOKEN_EQUAL, // ==
	TOKEN_NOT_EQUAL, // !=

	TOKEN_ARROW, // ->
	TOKEN_DOT, // .
	TOKEN_ELLIPSIS, // ...


	// Identifiers
	TOKEN_IDENTIFIER, // [a-zA-Z_][a-zA-Z0-9_]*

	// Literals
	TOKEN_INTEGER_LITERAL, // [0-9]+
	TOKEN_DECIMAL_LITERAL, // [0-9]+.[0-9]+
	TOKEN_HEXADECIMAL_LITERAL, // 0x[0-9a-fA-F]+
	TOKEN_CHARACTER_LITERAL, // '[^']'
	TOKEN_STRING_LITERAL, // "[^"]*"
};

typedef struct
{
	TokenKind kind;
	char* value;
	int start_line;
	int start_column;
	int end_line;
	int end_column;
} Token;

#endif // !TOKENS_HPP
