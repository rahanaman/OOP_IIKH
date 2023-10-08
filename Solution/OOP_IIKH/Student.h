#pragma once
#include<iostream>

class Student {
private:
	std::string name;
	std::string id;
	std::string admYear;
	std::string deptName;
	std::string tel;

	std::string RefineString(std::string string) {
		for (int i = 0; i < string.size(); ++i) {
			if (string.at(i) == '\"') {
				string.insert(i++, "\"");
			}
		}
		return string;
	}

public: 
	///Getter Method

	std::string GetName()const { return name; }
	std::string GetID()const { return id; }
	std::string GetAdmYear()const { return admYear; }
	std::string GetDeptName()const { return deptName; }
	std::string GetTel()const { return tel; }

	//constructor

	Student(std::string ID) :id(ID) {}

	Student(std::string name, std::string is, std::string admYear, std::string deptName, std::string tel)
		:name(name),id(id), admYear(admYear), deptName(deptName),tel(tel){ }

	std::string IntoString() {
		std::string str;
		str += "\"" + RefineString(GetName()) + "\"";
		str += "\"" + RefineString(GetID()) + "\"";
		str += "\"" + RefineString(GetAdmYear()) + "\"";
		str += "\"" + RefineString(GetDeptName()) + "\"";
		str += "\"" + RefineString(GetTel()) + "\"";
		str += "\n";

		return str;
	}

	//destructor;
	//~Student();

};

