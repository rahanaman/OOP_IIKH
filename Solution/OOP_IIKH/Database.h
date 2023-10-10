#pragma once

#include <vector>
#include<iostream>
#include<algorithm>

#include "Student.h"
#include "Error.h"

class DataBaseError : public Error {
public:

	DataBaseError(int e) : Error(e) {}
	void ErrorMessage() {

		switch (errorID) {
			//ID repetition Error
		case 0:
			std::cout << "Error : already inserted"<<std::endl;
			break;
			//Invalid Arrtibute Error
		case 1:
			std::cout << "Error : Invalid Attribute"<<std::endl;
		default:
			break;
		}
		
	}
};





class StudentDB {
private:
	//studentDB
	std::vector<Student> studentDB;
	//DB index
	std::vector<size_t> DBindex;
	//SortingOption
	int sortingOption;


	///ConstValue
	const int NAME_LEN = 15;
	const int ID_LEN = 10;

	//Sort By SorttingOption
	void Sort();

	/// Sorting Option

	//Sort By ID
	class SortingOption_ID {
	public:
		const StudentDB& DB;
		//constructor
		SortingOption_ID(const StudentDB& db) :DB(db) {}
		//operator overriding to use function object
		bool operator()(const size_t& i1, const size_t& i2);

	};

	//Sort by Name
	class SortingOption_Name {
	public:
		const StudentDB& DB;
		//constructor
		SortingOption_Name(const StudentDB& db) : DB(db) {}
		//operator overriding to use function object
		bool operator()(const size_t& i1, const size_t& i2);
	};

	//Sort By BirthYear
	class SortingOption_BirthYear {
	public:
		const StudentDB& DB;
		//constructor
		SortingOption_BirthYear(const StudentDB& db) : DB(db) {}
		//operator overriding to use function object
		bool operator()(const size_t& i1, const size_t& i2);
	};

	//Sort By DeptName
	class SortingOption_DeptName {
	public:
		const StudentDB& DB;
		//constructor
		SortingOption_DeptName(const StudentDB& db) : DB(db) {}
		//operator overriding to use function object
		bool operator()(const size_t& i1, const size_t& i2);
	};

	void CheckValidity(Student& s);

	void CheckName(std::string s);

	void CheckID(std::string s);

	void CheckBirthYear(std::string s) {
		CheckDigitString(s);
		CheckStringLen(s, 4);
	}

	void CheckTel(std::string s){
		CheckDigitString(s);
		CheckStringLen(s, 11);
	}

	

	void CheckIDExist(std::string s) {
		for (auto student : studentDB) {
			if (student.GetID() == s) throw DataBaseError(0);
		}
	}

	void CheckDigitString(std::string s) {
		for (auto c : s) {
			if (!isdigit(c)) throw DataBaseError(1);
		}
		return;
	}

	void CheckCharString(std::string s) {
		for (auto c : s) {
			if ((!isalpha(c)) && (c != ' ')) throw DataBaseError(1);
		}
		return;
	}

	void CheckStringLen(std::string s, int len, int type = 0) {

		switch (type) {
		case 0:
			if (s.length() != len) throw DataBaseError(1);
			break;
		case 1:
			if (s.length() > len) throw DataBaseError(1);
			break;
		default:
			break;
		}
	}

public:

	//constructor
	StudentDB():sortingOption(0){}




	/// Getter Method
	
	//Get DB Data
	const std::vector<Student> GetDB() { return studentDB; }
	//Get Index Data
	const std::vector<size_t> GetIndex() { return DBindex; }




	/// setter method

	//Set DB Data
	void SetDB(std::vector<Student> db) { this->studentDB = db; }



	void Insert(Student *s) {
		try{
			CheckValidity(*s);
		}
		catch (DataBaseError& e) {
			e.ErrorMessage();
			delete s;
			return;
		}

		//Insert ½ÇÇà

		DBindex.push_back(studentDB.size());
		studentDB.push_back(*s);

		Sort();
	}

	std::vector<Student> SearchByName(std::string& s) {
		std::vector<Student> list;
		for (auto i : DBindex) {
			if (studentDB[i].GetName() == s) list.push_back(studentDB[i]);
		}
		return list;
	}
	std::vector<Student> SearchByID(std::string& s);
	std::vector<Student> SearchByAdmYear(std::string& s);
	std::vector<Student> SearchByDeptName(std::string& s);

	


	
	

	void SortByName() {
		std::sort(DBindex.begin(), DBindex.end(), SortingOption_Name(*this));
		sortingOption = 0;
	}

	void SortByID() {
		std::sort(DBindex.begin(), DBindex.end(), SortingOption_ID(*this));
		sortingOption = 1;
	}


	void SortByBirthYear() {
		std::sort(DBindex.begin(), DBindex.end(), SortingOption_BirthYear(*this));
		sortingOption = 2;
	}
	void SortByDeptName() {
		std::sort(DBindex.begin(), DBindex.end(), SortingOption_DeptName(*this));
		sortingOption = 3;
	}

};