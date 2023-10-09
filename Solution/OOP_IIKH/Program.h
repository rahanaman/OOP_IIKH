#pragma once
#include<iostream>

#include"txtReader.h";
#include"Database.h"

class Program {
private:
	std::string filepath;
	StudentDB db;
	txtReader txtReader;
	
public:

	Program(std::string s):filepath(s),txtReader(s),db(){}

	void Execute() {
		
	}

	void EndProgram() {
		save();

		exit(0);
	}

	void save() {

	}
};