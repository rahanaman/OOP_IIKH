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

	//Const Value
	const int NAME_LEN = 15;
	const int ID_LEN = 10;
	const int DEPT_LEN = 25;
	const int BIRTH_LEN = 10;
	const int TEL_LEN = 11;
	///


	//Initialize Program
	void Init(){
		std::vector<Student*> list = txtReader.Init(db);
		for (auto s : list) {
			db.Insert(s);
		}
	}

	//Quit Program - save data in txt before quit Program
	void EndProgram() { save(); exit(0); }

	//Save Data - when quit Program
	void save() { txtReader.save(db.GetDB()); }

	

public:

	Program(std::string s) :filepath(s), db(), txtReader(s) { Init(); }

	

	void Execute() {
		while (true) {
			MainMenu();
			system("Pause");
		}
	}



	

	int GetInput() {
		int inputNum;
		std::cin >> inputNum;
		return inputNum;
		system("CLS");
	}

	void MainMenu() {
		system("CLS");
		std::cout << "1. Insertion" << std::endl;
		std::cout << "2. Search" << std::endl;
		std::cout << "3. Sorting Option" << std::endl;
		std::cout << "4. Exit" << std::endl;
		std::cout << "> ";

		int inputNum = GetInput();

		switch (inputNum) {
		case 1:
			InsertMenu();
			break;
		case 2:
			SearchMenu();
			break;
		case 3:
			SortingOptionMenu();
			break;
		case 4:
			EndProgram();
			break;
		default:
			break;
		}

		return;
	}

	void InsertMenu() {
		std::string Name, ID, DeptName, BirthYear, Tel;
		std::cout << "Name (up to 15 characters) ? ";
		std::cin >> Name;
		std::cout << "Student ID (10 digits) ? ";
		std::cin >> ID;
		std::cout << "Birth Year (4 digits) ? ";
		std::cin >> BirthYear;
		std::cout << "Department ? ";
		std::cin >> DeptName;
		std::cout << "Tel ? ";
		std::cin >> Tel;

		Student* student = new Student(Name,ID,BirthYear,DeptName,Tel);

		db.Insert(student);
	}

	

	void SearchMenu() {
		system("CLS");
		std::cout << "- Search -" << std::endl;
		std::cout << "1. Search by name" << std::endl;
		std::cout << "2. Search by student ID (10 numbers)" << std::endl;
		std::cout << "3. Search by admission year (4 numbers)" << std::endl;
		std::cout << "4. Search by department name" << std::endl;
		std::cout << "5. List All" << std::endl;
		std::cout << "> ";

		int inputNum = GetInput();

		switch (inputNum) {
		case 1:
			Search_Name();
			break;
		
		case 5:
			Search_ListAll();
			break;
		default:
			break;
		}
	}

	void Search_Name() {
		system("CLS");
		std::cout << "Name keyword? ";
		std::string name; std::cin >> name;

		std::cout << std::endl;
		std::vector<Student> list = db.SearchByName(name);
		Outputformat();
		for (auto s : list) {
			ListStudent(s);
		}
	}

	void Search_ListAll() {
		system("CLS");
		std::vector<Student> list = db.GetDB();
		std::vector<size_t> index = db.GetIndex();

		
		Outputformat();
		for (auto i : index) {
			ListStudent(list[i]);
		}
		
	}

	void ListStudent(Student& s) {
		std::cout << s.GetName()<<" ";
		for (int i = 0; i < NAME_LEN - s.GetName().length(); ++i)std::cout << " ";
		std::cout << std::setw(ID_LEN) << s.GetID()<<" ";
		std::cout << s.GetDeptName() << " ";
		for (int i = 0; i < DEPT_LEN - s.GetDeptName().length(); ++i)std::cout << " ";
		std::cout << std::setw(BIRTH_LEN) << s.GetBirthYear()<<" ";
		std::cout << std::setw(TEL_LEN) << s.GetTel()<<std::endl;
	}

	void Outputformat() {
		std::cout << "Name            " << "studentID  " << " Dept                     "<<"Birth Year " << "Tel        " << std::endl;
	}

	void SortingOptionMenu(){
		system("CLS");
		std::cout << "- Sorting Option" << std::endl;
		std::cout << "1. Sort by Name" << std::endl;
		std::cout << "2. Sort by Student ID" << std::endl;
		std::cout << "3. Sort by Birth Year" << std::endl;
		std::cout << "4. Sort by Department name" << std::endl;
		std::cout << "> ";

		int inputNum = GetInput();

		switch (inputNum) {
		case 1:
			db.SortByName();
			break;
		case 2:
			db.SortByID();
			break;
		case 3:
			db.SortByBirthYear();
			break;
		case 4:
			db.SortByDeptName();
			break;		
		default:
			break;
		}
	}

};

