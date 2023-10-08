#pragma once

#include <vector>
#include<iostream>
#include<algorithm>

#include "Student.h"

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

		SortingOption_Name(const StudentDB& db): DB(db) {}
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





public:

	void Insert(Student& s);

	void SearchByName(std::string& s);
	

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