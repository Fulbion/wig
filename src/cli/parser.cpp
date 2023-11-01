#include "parser.hpp"

#include <iostream>

CLI::Command CLI::Parser::parse(int argc, char** argv)
{
	Command cmd;

	cmd.commandName = argv[0];

	// For each argument in argv (except the first one), split it by '=' and add it to the command.
	// If the argument doesn't contain '=', return CLI error.
	// If the argument doesn't start with '--' or '-', return CLI error.
	// If the argument doesn't have a value, return CLI error.
	// If the argument doesn't exist, return CLI error.

	for (int i = 1; i < argc; i++)
	{
		char* arg = argv[i];

		// Ignore first argument (the command name).
		if (i == 0)
			continue;

		// If the argument doesn't start with '--' or '-', return CLI error.
		if (arg[0] != '-' && arg[1] != '-')
		{
			std::cerr << "CLI error: Argument '" << arg << "' doesn't start with '--' or '-'" << std::endl;
			exit(1);
		}

		// If the argument doesn't contain '=', return CLI error.
		if (strchr(arg, '=') == NULL)
		{
			std::cerr << "CLI error: Argument '" << arg << "' doesn't contain '='." << std::endl;
			exit(1);
		}

		// Split the argument by '='.
		char* argName = strtok(arg, "=");
		char* argValue = strtok(NULL, "=");

		// If the argument doesn't have a value, return CLI error.
		if (argValue == NULL)
		{
			std::cerr << "CLI error: Argument '" << arg << "' doesn't have a value." << std::endl;
			exit(1);
		}

		// If/Else/ElseIf the argument exists, add it to the command.
		if (strcmp(argName, "--input") == 0 || strcmp(argName, "-i") == 0)
		{
			cmd.input = argValue;
		}
		else if (strcmp(argName, "--output") == 0 || strcmp(argName, "-o") == 0)
		{
			cmd.output = argValue;
		}
		else
		{
			std::cerr << "CLI error: Argument '" << arg << "' doesn't exist." << std::endl;
			exit(1);
		}
	}

	return cmd;
}