#ifndef STATEMENTS_AST_HPP
#define STATEMENTS_AST_HPP

/*
Statement: ExpressionStatement | CompoundStatement | SelectionStatement | IterationStatement | JumpStatement | Declaration;

ExpressionStatement: Expression ';';
CompoundStatement: '{' (Statement)* '}';
SelectionStatement: IfStatement | SwitchStatement;
IterationStatement: WhileStatement | DoStatement | ForStatement;
JumpStatement: BreakStatement | ContinueStatement | ReturnStatement;

IfStatement: If '(' Expression ')' Statement (Else Statement)?;
SwitchStatement: Switch '(' Expression ')' '{' (Case Expression ':' Statement)* (Default ':' Statement)? '}';

WhileStatement: While '(' Expression ')' Statement;
DoStatement: Do Statement While '(' Expression ')' ';';
ForStatement: For '(' (Expression)? ';' (Expression)? ';' (Expression)? ')' Statement;

BreakStatement: Break ';';
ContinueStatement: Continue ';';
ReturnStatement: Return (Expression)? ';';
*/

#include "../tokens.hpp"

#include <optional>

struct Statement
{
	std::variant<ExpressionStatement, CompoundStatement, SelectionStatement, IterationStatement, JumpStatement, Declaration> statement;
};

struct ExpressionStatement
{
	Expression expression;
};

struct CompoundStatement
{
	std::vector<Statement> statements;
};

struct SelectionStatement
{
	std::variant<IfStatement, SwitchStatement> selection_statement;
};

struct IfStatement
{
	Expression expression;
	Statement statement;
	std::optional<Statement> else_statement;
};

struct SwitchStatement
{
	Expression expression;
	std::vector<std::tuple<Expression, Statement>> cases;
	std::optional<Statement> default_case;
};

struct IterationStatement
{
	std::variant<WhileStatement, DoStatement, ForStatement> iteration_statement;
};

struct WhileStatement
{
	Expression expression;
	Statement statement;
};

struct DoStatement
{
	Statement statement;
	Expression expression;
};

struct ForStatement
{
	std::optional<Expression> init_expression;
	std::optional<Expression> condition_expression;
	std::optional<Expression> iteration_expression;
	Statement statement;
};

struct JumpStatement
{
	std::variant<BreakStatement, ContinueStatement, ReturnStatement> jump_statement;
};

struct BreakStatement
{
};

struct ContinueStatement
{
};

struct ReturnStatement
{
	std::optional<Expression> expression;
};


#endif // !STATEMENTS_AST_HPP
