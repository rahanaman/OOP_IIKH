#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<regex>
#include<vector>

class txtReader {
private:
	const std::regex SPLIT_ATT = std::regex(",(?=(?:[^\"]*\"[^\"]*\")*(?![^\"]*\"))");
	const std::string TRIM_CHAR = "\"";
	const std::string REPLACE_CHAR = "\"\"";

	std::fstream file;
	std::string filepath;

	
	std::vector<Student*> Read(StudentDB& DB) {
		std::vector <Student*> list;
		std::string str;
		while (!file.eof()) {
			std::getline(file, str);
			if (str == "") break;
			std::vector<std::string> atts = ParseString(str);
			
			Student* student = new Student(atts[0], atts[1], atts[2], atts[3], atts[4]);
			list.push_back(student);
		}
		file.close();

		return list;
		//DB.SortByName();

	}
	

	std::string IntoString(Student& s) {
		std::string str;
		str += "\"" + s.GetName() + "\",";
		str += "\"" + s.GetID() + "\",";
		str += "\"" + s.GetBirthYear() + "\",";
		str += "\"" + s.GetDeptName() + "\",";
		str += "\"" + s.GetTel() + "\"";
		str += "\n";

		return str;
	}
	/*
	std::string RefineString(std::string string) {
		for (int i = 0; i < string.size(); ++i) {
			if (string.at(i) == '\"') {
				string.insert(i++, "\"");
			}
		}
		return string;
	}
	*/

	std::vector<std::string> ParseString(std::string& s) {
		std::sregex_token_iterator it(s.begin(), s.end(), SPLIT_ATT, -1), end;
		std::vector<std::string> atts = std::vector<std::string>(it, end);
		for (int i = 0; i < atts.size(); ++i) {
			atts[i].erase(remove(atts[i].begin(), atts[i].end(), ' '), atts[i].end());
			atts[i].erase(0, 1);
			atts[i].erase(atts[i].size() - 1, atts[i].size());
		}
		return atts;
	}


	

	


public:

	std::vector<Student*> Init(StudentDB& DB) {
		file.open(filepath, std::ios::in);
		if (file.is_open()) {
			return Read(DB);
		}
	}

	txtReader(std::string filepath) :filepath(filepath) {
		
	}

	void save(const std::vector<Student>& DB) {
		file.open(filepath, std::ios::out | std::ios::trunc);
		for (auto s : DB) {
			file << IntoString(s);
		}


		file.close();
	}
	~txtReader() {
		
	}
	
};