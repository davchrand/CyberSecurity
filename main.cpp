/*
	Author: Jonathan Pham
	File: main.cpp
	Key Encryption
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "encryptionGenerator.h"

int main(int argc, char* argv[])
{
        bool generatorHolder;
        generatorHolder = generator::generate_key();
	std::string fileName = "";

	// Command Line Arguments are 2: ./a.out <insert string here>
	if (argc == 2) {
		std::string cmdline(argv[1]);

		std::cout << "You entered:\n";
		std::cout << cmdline << std::endl;

		// Encrypt String cmdline here
	} else {
		// Read File to encrypt contents of file
		std::cout << "Hello, enter the file to be encrypted: ";
		std::cin >> fileName;

		std::ifstream file(fileName.c_str());
		std::stringstream buffer;
		buffer << file.rdbuf();

		// buffer.str() has contents of the file as a string
		std::cout << buffer.str() << std::endl;

		// Encrypt buffer.str() here
	}
}
