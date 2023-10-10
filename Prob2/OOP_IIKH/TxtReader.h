#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<regex>
#include<vector>

#include "Student.h"

class txtReader {
private:
	///Const Value
	//Split Data by Regex
	const std::regex SPLIT_ATT = std::regex(",(?=(?:[^\"]*\"[^\"]*\")*(?![^\"]*\"))");

	//file IO object
	std::fstream file;
	std::string filepath;

	///Read Method
	std::vector<Student*> Read();
	//Parse String into attributes vector
	std::vector<std::string> ParseString(std::string& s);

	//convert Student Data into string
	std::string IntoString(const Student& s);

	

	

	


public:
	//constructor
	txtReader(std::string filepath) :filepath(filepath) {}

	//Initialize txtReader - check existing DB
	std::vector<Student*> Init();

	//Save DB into txt
	void save(const std::vector<Student>& list);

	
};