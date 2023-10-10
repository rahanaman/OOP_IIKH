#include "Database.h"


void StudentDB::Sort() {
	switch (sortingOption) {
	case 0:
		SortByName(); break;
	case 1:
		SortByID();	break;
	case 2:
		SortByBirthYear(); break;
	case 3:
		SortByDeptName(); break;
	}
}

void StudentDB::CheckValidity(Student& s) {
	CheckName(s.GetName());
	CheckID(s.GetID());
	CheckBirthYear(s.GetBirthYear());
	CheckTel(s.GetTel());
}

void StudentDB::CheckName(std::string s) {
	CheckCharString(s);
	CheckStringLen(s, NAME_LEN, 1);
}

void StudentDB::CheckID(std::string s) {
	CheckDigitString(s);
	CheckStringLen(s, 10);
	CheckIDExist(s);
}

bool StudentDB::SortingOption_ID::operator() (const size_t& i1, const size_t& i2){
	return DB.studentDB[i1].GetID() < DB.studentDB[i2].GetID();
}

bool StudentDB::SortingOption_Name::operator()(const size_t& i1, const size_t& i2) {
	return DB.studentDB[i1].GetName() < DB.studentDB[i2].GetName();
}

bool StudentDB::SortingOption_BirthYear::operator()(const size_t& i1, const size_t& i2) {
	return DB.studentDB[i1].GetBirthYear() < DB.studentDB[i2].GetBirthYear();
}

bool StudentDB::SortingOption_DeptName::operator()(const size_t& i1, const size_t& i2) {
	return DB.studentDB[i1].GetDeptName() < DB.studentDB[i2].GetDeptName();
}

