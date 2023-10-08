#pragma once
#include<iostream>

class Student {
private:
	std::string name;
	std::string id;
	std::string admYear;
	std::string deptName;
	std::string tel;


public: 
	///Getter Method

	std::string GetName()const {return name; }
	std::string GetID()const { return id; };
	std::string GetAdmYear()const { return admYear; }
	std::string GetDeptName()const { return deptName; }
	std::string GetTel()const { return tel; }

	//constructor

	Student(std::string ID) :id(ID) {}

	Student(std::string name, std::string is, std::string admYear, std::string deptName, std::string tel)
		:name(name),id(id), admYear(admYear), deptName(deptName),tel(tel){ }

	//destructor;
	//~Student();

};

