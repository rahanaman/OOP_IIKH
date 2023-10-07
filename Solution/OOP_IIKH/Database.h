#pragma once

#include <vector>
#include<iostream>
#include<algorithm>

#include "Student.h"

class StudentDB {
private:
	

	
	
	class SortOption_ID {
	public:
		const StudentDB& DB;

		SortOption_ID(const StudentDB& db) :DB(db) {}

		bool operator()(const size_t& i1, const size_t& i2) {
			return DB.studentDB[i1].GetID() < DB.studentDB[i2].GetID();
		}

	};


public:

	//studentDB
	std::vector<Student> studentDB;

	//DB index
	std::vector<size_t> DBindex;

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