#ifndef TYPES_AST_HPP
#define TYPES_AST_HPP

#include "../tokens.hpp"

#include <optional>


/*
* Type: PrimitiveType (PointerType | ArrayType | FunctionType | TupleType)*; 
*/
struct Type {
	PrimitiveType primitive_type;
	std::vector<PointerType> pointer_types;
	std::vector<ArrayType> array_types;
	std::vector<FunctionType> function_types;
	std::vector<TupleType> tuple_types;
};


enum {
	TYPE_VOID(TOKEN_VOID),
	TYPE_BOOL(TOKEN_BOOL),
	TYPE_CHAR(TOKEN_CHAR),
	TYPE_INT(TOKEN_INT),
	TYPE_FLOAT(TOKEN_FLOAT),
} PrimitiveType(TokenKind);


/*
* Array type is
* 
* '[' PrimitveType ']' | '[' Identifier ']'
*/
struct ArrayType {
	TokenKind lbracket;
	PrimitiveType primitive_type;
	TokenKind rbracket;
};

/*
* Pointer type is
* 
* Star (TOKEN_STAR)
*/
struct PointerType {
	TokenKind star;
};

/*
* Function type is
* '(' ( Type (',' Type)* )? ')'
*
*/
struct FunctionType {
	TokenKind lparen;
	std::optional<std::vector<Type>> arguments;
	TokenKind rparen;
};

#endif // !TYPES_AST_HPP
