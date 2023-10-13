#include "Database.h"




///Sorting Option Function Object
///Sort Index by Sorting Option - list student data in order of sorted index

//SortByID
bool StudentDB::SortingOption_ID::operator() (const size_t& i1, const size_t& i2) {
	return DB.studentDB[i1].GetID() < DB.studentDB[i2].GetID();
}
//SortByName
bool StudentDB::SortingOption_Name::operator()(const size_t& i1, const size_t& i2) {
	return DB.studentDB[i1].GetName() < DB.studentDB[i2].GetName();
}
//SortByBirthYear
bool StudentDB::SortingOption_BirthYear::operator()(const size_t& i1, const size_t& i2) {
	return DB.studentDB[i1].GetBirthYear() < DB.studentDB[i2].GetBirthYear();
}
//SortByDeptName
bool StudentDB::SortingOption_DeptName::operator()(const size_t& i1, const size_t& i2) {
	return DB.studentDB[i1].GetDeptName() < DB.studentDB[i2].GetDeptName();
}

/// Validity Check

//Check Validity of every Attribute
void StudentDB::CheckValidity(Student& s) {
	CheckName(s.GetName());
	CheckID(s.GetID());
	CheckBirthYear(s.GetBirthYear());
	CheckTel(s.GetTel());
}
//Check Name
void StudentDB::CheckName(std::string s) {
	CheckCharString(s); //string of character
	CheckStringLen(s, NAME_LEN, 1); //len is up to NAME_LEN
}

void StudentDB::CheckID(std::string s) {
	CheckDigitString(s);
	CheckStringLen(s, ID_LEN);
	CheckIDExist(s);
}

void StudentDB::CheckBirthYear(std::string s) {
	CheckDigitString(s);
	CheckStringLen(s, BIRTHYEAR_LEN);
}

void StudentDB::CheckTel(std::string s) {
	CheckDigitString(s);
	CheckStringLen(s, TEL_LEN);
}

void StudentDB::CheckIDExist(std::string s) {
	for (auto student : studentDB) {
		if (student.GetID() == s) throw DataBaseError(0);
	}
}

void StudentDB::CheckDigitString(std::string s) {
	for (auto c : s) {
		if (!isdigit(c)) throw DataBaseError(1);
	}
	return;
}


void StudentDB::CheckCharString(std::string s) {
	for (auto c : s) {
		if ((!isalpha(c)) && (c != ' ')) throw DataBaseError(1);
	}
	return;
}

void StudentDB::CheckStringLen(std::string s, int len, int type) {
	switch (type) {
	case 0: // check string length is up to len
		if (s.length() != len) throw DataBaseError(1); break;
	case 1: // check string length is exactly len
		if (s.length() > len) throw DataBaseError(1); break;
	default: break;
	}
}

void StudentDB::Insert(Student* s) {
	try { // check Validity of Student Data
		CheckValidity(*s);
	}
	catch (DataBaseError& e) { // if there is error, delete Student Object and print ErrorMessage
		e.ErrorMessage(); //print Error Message - Message vary on Error Type
		delete s; // delete Invalid bject
		return;
	}

	//Insert Student into DB
	DBindex.push_back(studentDB.size());
	studentDB.push_back(*s);

	//Sort by Sorting Option
	Sort();
}


const std::vector<Student> StudentDB::GetSortedDB() {
	std::vector<Student> list;
	for (auto i : DBindex) {
		list.push_back(studentDB[i]);
	}
	return list;
}

const std::vector<Student> StudentDB::SearchByName(std::string& s) {
	std::vector<Student> list;
	for (auto i : DBindex) {
		if (studentDB[i].GetName() == s) list.push_back(studentDB[i]);
	}
	return list;
}

const std::vector<Student> StudentDB::SearchByID(std::string& s) {
	std::vector<Student> list;
	for (auto i : DBindex) {
		if (studentDB[i].GetID() == s) list.push_back(studentDB[i]);
	}
	return list;
}

const std::vector<Student> StudentDB::SearchByBirthYear(std::string& s) {
	std::vector<Student> list;
	for (auto i : DBindex) {
		if (studentDB[i].GetBirthYear() == s) list.push_back(studentDB[i]);
	}
	return list;
}

const std::vector<Student> StudentDB::SearchByDeptName(std::string& s) {
	std::vector<Student> list;
	for (auto i : DBindex) {
		if (studentDB[i].GetDeptName() == s) list.push_back(studentDB[i]);
	}
	return list;
}

void StudentDB::SortByName() {
	std::sort(DBindex.begin(), DBindex.end(), SortingOption_Name(*this));
	sortingOption = 0;
}
void StudentDB::SortByID() {
	std::sort(DBindex.begin(), DBindex.end(), SortingOption_ID(*this));
	sortingOption = 1;
}


void StudentDB::SortByBirthYear() {
	std::sort(DBindex.begin(), DBindex.end(), SortingOption_BirthYear(*this));
	sortingOption = 2;
}
void StudentDB::SortByDeptName() {
	std::sort(DBindex.begin(), DBindex.end(), SortingOption_DeptName(*this));
	sortingOption = 3;
}