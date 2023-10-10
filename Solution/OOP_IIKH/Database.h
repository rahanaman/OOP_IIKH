#pragma once

#include <vector>
#include<iostream>
#include<algorithm>

#include "Student.h"
#include "Error.h"

//ErrorClass - Invalid Data Error
class DataBaseError : public Error {
public:
	DataBaseError(int e) : Error(e) {}
	void ErrorMessage() {

		switch (errorID) {
		case 0://ID repetition Error
			std::cout << "Error : already inserted"<<std::endl; break;
		case 1://Invalid Arrtibute Error
			std::cout << "Error : Invalid Attribute" << std::endl; break;
		default://Unknown Error
			std::cout << "Error : Unknown Error" << std::endl; break;
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
	const int DEPT_LEN = 25;
	const int BIRTHYEAR_LEN = 4;
	const int TEL_LEN = 11;

	//Sort By SorttingOption - call when new Student Data inserted
	void Sort() {
		switch (sortingOption) {
		case 0:	SortByName(); break;
		case 1:	SortByID();	break;
		case 2:	SortByBirthYear(); break;
		case 3:	SortByDeptName(); break;
		}
	}

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

	///Sorting Option END


	///Data Validity Check

	//Check Validity
	void CheckValidity(Student& s);
	//Check Name Validity
	void CheckName(std::string s);
	//Check ID Validity
	void CheckID(std::string s);
	//Check BirthYear Validity
	void CheckBirthYear(std::string s);
	//Check Tel Validity
	void CheckTel(std::string s);
	//Check ID repetition
	void CheckIDExist(std::string s);

	///Method to check Validity

	//Check digit string 
	void CheckDigitString(std::string s);
	//Check char string 
	void CheckCharString(std::string s);
	//Check string length
	void CheckStringLen(std::string s, int len, int type = 0);

public:

	//constructor
	StudentDB():sortingOption(0){}

	/// Getter Method

	//Get DB Data
	const std::vector<Student> GetDB() { return studentDB; }
	//Get Index Data
	const std::vector<size_t> GetIndex() { return DBindex; }

	///Search Method - Get Searched Student Data
	const std::vector<Student> GetSortedDB();
	const std::vector<Student> SearchByName(std::string& s);
	const std::vector<Student> SearchByID(std::string& s);
	const std::vector<Student> SearchByBirthYear(std::string& s);
	const std::vector<Student> SearchByDeptName(std::string& s);

	//Insert new Student Data - Check Validity and Send Error
	void Insert(Student* s);

	/// Sorting Method - Sort Index and Set Sorting Option
	void SortByName();
	void SortByID();
	void SortByBirthYear();
	void SortByDeptName();

};