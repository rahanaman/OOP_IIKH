#pragma once
#include<iostream>
#include<iomanip>

#include"txtReader.h";
#include"Database.h"

class Program {
private:
	//file path
	std::string filepath;
	//StudentDB
	StudentDB db;
	//txtReader
	txtReader txtReader;

	//Const Value
	const int NAME_LEN = 15;
	const int ID_LEN = 10;
	const int DEPT_LEN = 25;
	const int BIRTH_LEN = 10;
	const int TEL_LEN = 11;
	///Output format data


	//Initialize Program
	void Init();

	//Quit Program - save data in txt before quit Program
	void EndProgram() { save(); exit(0); }

	//Save Data - when quit Program
	void save() { txtReader.save(db.GetDB()); }

	//Get Input on Menu
	int GetInput() {
		int inputNum;
		std::cin >> inputNum;
		return inputNum;
		system("CLS");
	}
	///Menu
	void MainMenu();
	void InsertMenu();
	void SearchMenu();
	void SortingOptionMenu();

	/// Search Method
	void Search_Name();
	void Search_ID();
	void Search_BirthYear();
	void Search_DeptName();
	void Search_ListAll();

	///Student Output Format
	void ListStudent(Student& s);
	///Attribute Output
	void Outputformat();
	

public:
	//constructor - Initialize Program
	Program(std::string s) :filepath(s), db(), txtReader(s) { Init(); }

	//Program Execute
	void Execute() {
		while (true) {
			MainMenu();
			system("Pause");
		}
	}
};

