#include "Database.h"




bool StudentDB::SortOption_ID::operator() (const size_t& i1, const size_t& i2){
	return DB.studentDB[i1].GetID() < DB.studentDB[i2].GetID();
}

bool StudentDB::SortingOption_Name::operator()(const size_t& i1, const size_t& i2) {
	return DB.studentDB[i1].GetName() < DB.studentDB[i2].GetName();
}


