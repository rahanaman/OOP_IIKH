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


	/// Sorting Option

	class SortOption_ID {
	public:
		const StudentDB& DB;

		SortOption_ID(const StudentDB& db) :DB(db) {}
		bool operator()(const size_t& i1, const size_t& i2);

	};

	class SortingOption_Name {
		const StudentDB& DB;

		SortingOption_Name(const StudentDB& db) : DB(db) {}
		bool operator()(const size_t& i1, const size_t& i2);
	};

	class SortingOption_AdmYear {
		const StudentDB& DB;

		SortingOption_AdmYear(const StudentDB& db) : DB(db) {}
		bool operator()(const size_t& i1, const size_t& i2);
	};

	class SortingOption_DeptName {
		const StudentDB& DB;
		SortingOption_DeptName(const StudentDB& db) : DB(db) {}
		bool operator()(const size_t& i1, const size_t& i2);
	};

	void CheckName(std::string s) {
		IsCharString(s);

		if (s.size() > 15) throw DataBaseError(1);

	}
	void CheckValidity(Student& s) {
		CheckName(s.GetName());


	}



public:

	StudentDB() {

	}





	const std::vector<Student> GetDB() {
		return studentDB;
	}



	

	void IsCharString(std::string s) {
		for (auto c : s) {
			if ((!isalpha(c))&&(c!=' ')) throw DataBaseError(1);
		}
		return;
	}

	/// setter method
	void SetDB(std::vector<Student> db) {
		this->studentDB = db;
	}

	void Insert(Student& s) {
		try{
			CheckValidity(s);
		}
		catch (DataBaseError& e) {
			e.ErrorMessage();
			return;
		}

		//Insert ½ÇÇà

		DBindex.push_back(studentDB.size());
		studentDB.push_back(s);

		
	}

	void SearchByName(std::string& s);
	void SearchByID(std::string& s);
	void SearchByAdmYear(std::string& s);
	void SearchByDeptName(std::string& s);
	
	void Save();

	

	void Add(std::string s) {
		Student *db = new Student(s);
		
		DBindex.push_back(studentDB.size());
		studentDB.push_back(*db);
	}

	void array() {
		for(auto i : DBindex){
			std::cout << studentDB[i].GetID() << " ";
		}
	}
	
	void SortByID() {
		std::sort(DBindex.begin(), DBindex.end(), SortOption_ID(*this));
	}
};