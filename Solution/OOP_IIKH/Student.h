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

	std::string GetName();
	std::string GetID()const { return id; };
	std::string GetAdmYear();
	std::string GetDeptName();
	std::string GetTel();

	//constructor

	Student(std::string ID) :id(ID) {}

	Student(std::string name, std::string is, std::string admYear, std::string deptName, std::string tel)
		:name(name),id(id), admYear(admYear), deptName(deptName),tel(tel){ }

	//destructor;
	//~Student();

};

