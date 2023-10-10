#pragma once
#include<iostream>

class Student {
private:
	/// Student Data
	std::string name;
	std::string id;
	std::string birthYear;
	std::string deptName;
	std::string tel;

public: 
	///Getter Method
	const std::string GetName()const { return name; }
	const std::string GetID()const { return id; }
	const std::string GetBirthYear()const { return birthYear; }
	const std::string GetDeptName()const { return deptName; }
	const std::string GetTel()const { return tel; }

	//constructor
	Student(std::string name, std::string id,  std::string birthYear, std::string deptName, std::string tel)
		:name(name),id(id), deptName(deptName), birthYear(birthYear), tel(tel){ }
};

