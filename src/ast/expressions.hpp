#ifndef EXPRESSIONS_AST_HPP
#define EXPRESSIONS_AST_HPP

/*
* Expression: AssignmentExpression;

AssignmentExpression: ConditionalExpression (Assign AssignmentExpression)?;

ConditionalExpression: LogicalOrExpression (Question Expression Colon ConditionalExpression)?;

LogicalOrExpression: LogicalAndExpression (OrOr LogicalAndExpression)*;

LogicalAndExpression: InclusiveOrExpression (AndAnd InclusiveOrExpression)*;

InclusiveOrExpression: ExclusiveOrExpression (Or ExclusiveOrExpression)*;

ExclusiveOrExpression: AndExpression (Caret AndExpression)*;

AndExpression: EqualityExpression (And EqualityExpression)*;

EqualityExpression: RelationalExpression ((Equal | NotEqual) RelationalExpression)*;

RelationalExpression: ShiftExpression ((Less | Greater | LessEqual | GreaterEqual) ShiftExpression)*;

ShiftExpression: AdditiveExpression ((LeftShift | RightShift) AdditiveExpression)*;

AdditiveExpression: MultiplicativeExpression ((Plus | Minus) MultiplicativeExpression)*;

MultiplicativeExpression: CastExpression ((Star | Div | Mod) CastExpression)*;

CastExpression: UnaryExpression | '(' Type ')' CastExpression;

UnaryExpression: PostfixExpression | (Plus | Minus | Not | Tilde) UnaryExpression;

PostfixExpression: PrimaryExpression (PostfixOperator)*;

PostfixOperator: LeftParen (Expression (',' Expression)*)? RightParen | LeftBracket Expression RightBracket | Dot Identifier | Arrow Identifier | PlusPlus | MinusMinus;

PrimaryExpression: Identifier | IntegerLiteral | DecimalLiteral | HexadecimalLiteral | CharacterLiteral | StringLiteral | LeftParen Expression RightParen;
*/

#include "../tokens.hpp"

#include <optional>

struct Expression 
{
	AssignmentExpression assignment_expression;
};

struct AssignmentExpression
{
	ConditionalExpression conditional_expression;
	std::optional<std::tuple<TokenKind, AssignmentExpression>> assignment_expression;
};

struct ConditionalExpression
{
	LogicalOrExpression logical_or_expression;
	std::optional<std::tuple<TokenKind, Expression, TokenKind, ConditionalExpression>> conditional_expression;
};

struct LogicalOrExpression
{
	LogicalAndExpression logical_and_expression;
	std::vector<std::tuple<TokenKind, LogicalAndExpression>> logical_or_expressions;
};

struct LogicalAndExpression
{
	InclusiveOrExpression inclusive_or_expression;
	std::vector<std::tuple<TokenKind, InclusiveOrExpression>> logical_and_expressions;
};

struct InclusiveOrExpression
{
	ExclusiveOrExpression exclusive_or_expression;
	std::vector<std::tuple<TokenKind, ExclusiveOrExpression>> inclusive_or_expressions;
};

struct ExclusiveOrExpression
{
	AndExpression and_expression;
	std::vector<std::tuple<TokenKind, AndExpression>> exclusive_or_expressions;
};

struct AndExpression
{
	EqualityExpression equality_expression;
	std::vector<std::tuple<TokenKind, EqualityExpression>> and_expressions;
};

struct EqualityExpression
{
	RelationalExpression relational_expression;
	std::vector<std::tuple<TokenKind, RelationalExpression>> equality_expressions;
};

struct RelationalExpression
{
	ShiftExpression shift_expression;
	std::vector<std::tuple<TokenKind, ShiftExpression>> relational_expressions;
};

struct ShiftExpression
{
	AdditiveExpression additive_expression;
	std::vector<std::tuple<TokenKind, AdditiveExpression>> shift_expressions;
};

struct AdditiveExpression
{
	MultiplicativeExpression multiplicative_expression;
	std::vector<std::tuple<TokenKind, MultiplicativeExpression>> additive_expressions;
};

struct MultiplicativeExpression 
{
	CastExpression cast_expression;
	std::vector<std::tuple<TokenKind, CastExpression>> multiplicative_expressions;
};

struct CastExpression
{
	std::optional<Type> type;
	std::optional<CastExpression> cast_expression;
};

struct UnaryExpression
{
	std::optional<TokenKind> unary_operator;
	std::optional<UnaryExpression> unary_expression;
};

struct PostfixExpression
{
	PrimaryExpression primary_expression;
	std::vector<std::tuple<TokenKind, std::optional<Expression>>> postfix_operators;
};

struct PrimaryExpression 
{
	std::optional<TokenKind> identifier;
	std::optional<TokenKind> integer_literal;
	std::optional<TokenKind> decimal_literal;
	std::optional<TokenKind> hexadecimal_literal;
	std::optional<TokenKind> character_literal;
	std::optional<TokenKind> string_literal;
	std::optional<std::tuple<TokenKind, Expression, TokenKind>> paren_expression;
};

#endif // !EXPRESSIONS_AST_HPP
