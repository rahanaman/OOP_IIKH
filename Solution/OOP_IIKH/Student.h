#pragma once
#include<iostream>

class Student {
private:
	std::string name;
	std::string id;
	std::string birthYear;
	std::string deptName;
	std::string tel;



public: 
	///Getter Method

	std::string GetName()const { return name; }
	std::string GetID()const { return id; }
	std::string GetBirthYear()const { return birthYear; }
	std::string GetDeptName()const { return deptName; }
	std::string GetTel()const { return tel; }

	//constructor

	Student(std::string name) :name(name) {}

	Student(std::string name, std::string id, std::string deptName, std::string birthYear,  std::string tel)
		:name(name),id(id), birthYear(birthYear), deptName(deptName),tel(tel){ }


	//destructor;
	//~Student();

};

