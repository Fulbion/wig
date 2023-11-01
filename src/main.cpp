#include "main.hpp";
#include "cli/parser.hpp"

CLI::Command cmd;

int main(int argc, char** argv)
{
	cmd = CLI::Parser::parse(argc, argv);

	// Print command data.
	std::cout << "Command name: " << cmd.commandName << std::endl;
	std::cout << "Input: " << cmd.input << std::endl;
	std::cout << "Output: " << cmd.output << std::endl;

	return 0;
}

CLI::Command getCommand()
{
	return cmd;
}
