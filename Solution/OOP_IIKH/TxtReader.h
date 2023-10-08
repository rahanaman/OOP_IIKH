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

	void Read() {
		std::string student;
		while (!file.eof()) {
			std::getline(file, student);
			std::sregex_token_iterator it(student.begin(), student.end(), SPLIT_ATT, -1), end;
			std::vector<std::string> atts = std::vector<std::string>(it, end);


			for (int i = 0; i < atts.size(); ++i) {
				std::cout << atts[i] << "///";
			}
			std::cout << std::endl << student;
		}
		file.close();
	}

	

	void Write() {

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