#ifndef DECLARATIONS_AST_HPP
#define DECLARATIONS_AST_HPP

/*
* Declaration: VariableDeclaration | ConstantDeclaration | FunctionDeclaration | ClassDeclaration | EnumDeclaration | StructDeclaration;

VariableDeclaration: Mutable? Type Identifier (Assign Expression)? ';';
ConstantDeclaration: Const Type Identifier (Assign Expression)? ';';

FunctionDeclaration: Type Identifier '(' (Type Identifier (',' Type Identifier)*)? ')' Block;
ClassDeclaration: Class Identifier (':' Identifier)? Block;

EnumDeclaration: Enum Identifier Block;
StructDeclaration: Struct Identifier Block;
*/

#include "../tokens.hpp"

#include <optional>

struct Declaration
{
	std::variant<VariableDeclaration, ConstantDeclaration, FunctionDeclaration, ClassDeclaration, EnumDeclaration, StructDeclaration> declaration;
};

struct VariableDeclaration
{
	std::optional<TokenKind> mutable_;
	Type type;
	TokenKind identifier;
	std::optional<std::tuple<TokenKind, Expression>> expression;
};

struct ConstantDeclaration
{
	TokenKind const_;
	Type type;
	TokenKind identifier;
	std::optional<std::tuple<TokenKind, Expression>> expression;
};

struct FunctionDeclaration
{
	Type type;
	TokenKind identifier;
	std::vector<std::tuple<Type, TokenKind>> parameters;
	Block block;
};

struct ClassDeclaration
{
	TokenKind class_;
	TokenKind identifier;
	std::optional<TokenKind> colon;
	std::optional<TokenKind> identifier2;
	Block block;
};

struct EnumDeclaration
{
	TokenKind enum_;
	TokenKind identifier;
	Block block;
};

struct StructDeclaration
{
	TokenKind struct_;
	TokenKind identifier;
	Block block;
};

#endif // !DECLARATIONS_AST_HPP
