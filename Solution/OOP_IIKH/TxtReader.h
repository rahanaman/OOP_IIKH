#pragma once
#include<iostream>
#include<fstream>
#include<regex>
#include<vector>

class txtReader {
private:
	const std::regex SPLIT_ATT = std::regex(",(?=(?:[^\"]*\"[^\"]*\")*(?![^\"]*\"))");

	std::fstream file;
	std::string filepath;

	void Init() {
		file.open(filepath, std::ios::in);
		if (file.is_open()) {
			Read();
		}
	}

	std::vector<Student> Read() {
		std::vector<Student> v;
		std::string str;
		while (!file.eof()) {
			std::getline(file, str);
			std::sregex_token_iterator it(str.begin(), str.end(), SPLIT_ATT, -1), end;
			std::vector<std::string> atts = std::vector<std::string>(it, end);

			Student *student = new Student(atts[0], atts[1], atts[2], atts[3], atts[4]);
			v.push_back(*student);
		}
		file.close();
		return v;
	}

	std::vector<std::string> ParseString() {

	}


	

	


public:
	txtReader(std::string filepath) :filepath(filepath) {
		Init();
	}

	void save(std::string str) {
		file.open(filepath, std::ios::out | std::ios::app);
		file << str;
		file.close();
	}
	~txtReader() {
		
	}
	
};