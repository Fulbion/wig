#ifndef PARSER_HPP
#define PARSER_HPP

/**
* @file parser.hpp
* @brief Contains the CLI parser class.
* @see src/cli/parser.cpp
*/

#include <string>
/// #include <optional>

namespace CLI
{

	typedef struct
	{
		std::string commandName;
		std::string input;
		std::string output;
	} Command;

	/*
	*
	* The Parser parse command line arguments. into a struct.
	* Ex: ./wigc --output=myapp --input=main.wig --libdir=lib/ -> {
	* 	output: "myapp",
	* 	input: "main.wig",
	* 	libdir: "lib/"
	* }
	*
	* Ex: ./wigc -o=myapp -i=main.wig -l=lib/ -> {
	* 	output: "myapp",
	* 	input: "main.wig",
	* 	libdir: "lib/"
	* }
	*
	* The code may be modular and easy to add new options.
	*/
	class Parser
	{
		public:
			/**
			* @brief Parse the command line arguments.
			* @param argc The number of arguments.
			* @param argv The arguments.
			* @return The parsed command.
			*/
			static Command parse(int argc, char** argv);
	};
}

#endif // !PARSER_HPP
