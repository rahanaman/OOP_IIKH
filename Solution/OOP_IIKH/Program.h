#pragma once
#include<iostream>
#include<iomanip>

#include"txtReader.h";
#include"Database.h"

class Program {
private:
	std::string filepath;
	StudentDB db;
	txtReader txtReader;

	const int NAME_LEN = 15;
	const int ID_LEN = 10;
	const int DEPT_LEN = 25;
	const int BIRTH_LEN = 10; 
	const int TEL_LEN = 11;

public:

	Program(std::string s) :filepath(s), db(),txtReader(s) {
		Init();
	}

	void Init() {
		txtReader.Init(db);
	}

	void Execute() {
		while (true) {
			MainMenu();

			system("Pause");
		}
	}

	void EndProgram() {
		save();

		exit(0);
	}

	void save() {
		txtReader.save(db.GetDB());
	}

	void MainMenu() {
		system("CLS");
		std::cout << "1. Insertion" << std::endl;
		std::cout << "2. Search" << std::endl;
		std::cout << "3. Sorting Option" << std::endl;
		std::cout << "4. Exit" << std::endl;

		int inputNum = GetInput();

		switch (inputNum) {
		case 2:
			SearchMenu();
			break;
		case 4:
			EndProgram();
			break;
		default:
			break;
		}

		return;
	}

	int GetInput() {
		int inputNum;
		std::cin >> inputNum;
		return inputNum;
		system("CLS");
	}

	void SearchMenu() {
		system("CLS");
		std::cout << "- Search -" << std::endl;
		std::cout << "1. Search by name" << std::endl;
		std::cout << "2. Search by student ID (10 numbers)" << std::endl;
		std::cout << "3. Search by admission year (4 numbers)" << std::endl;
		std::cout << "4. Search by department name" << std::endl;
		std::cout << "5. List All" << std::endl;

		int inputNum = GetInput();

		switch (inputNum) {

		
		case 5:
			Search_ListAll();
		default:
			break;
		}
	}

	void Search_ListAll() {
		system("CLS");
		std::vector<Student> list = db.GetDB();
		

		Outputformat();
		for (auto s : list) {
			ListStudent(s);
		}
		
	}

	void ListStudent(Student& s) {
		std::cout << s.GetName()<<" ";
		for (int i = 0; i < NAME_LEN - s.GetName().length(); ++i)std::cout << " ";
		std::cout << std::setw(ID_LEN) << s.GetID()<<" ";
		std::cout <<  s.GetDeptName();
		for (int i = 0; i < DEPT_LEN - s.GetDeptName().length(); ++i)std::cout << " ";
		std::cout << std::setw(BIRTH_LEN) << s.GetBirthYear()<<" ";
		std::cout << std::setw(TEL_LEN) << s.GetTel()<<std::endl;
	}

	void Outputformat() {
		std::cout << "Name            " << "studentID  " << " Dept                     "<<"Birth Year " << "Tel        " << std::endl;
	}
};

