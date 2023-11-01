#ifndef BLOCKS_AST_HPP
#define BLOCKS_AST_HPP

#include "statements.hpp"

#include <vector>

struct Block
{
	std::vector<Statement> statements;
};

#endif // !BLOCKS_AST_HPP
