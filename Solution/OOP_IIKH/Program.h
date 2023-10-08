#pragma once
#include<iostream>
class Program {
private:
	std::string filepath;
public:
	Program(char* filepath):filepath(filepath) {
		std::cout << filepath;
	}

	void Execute() {

	}

	void EndProgram() {
		save();

		exit(0);
	}

	void save() {

	}
};