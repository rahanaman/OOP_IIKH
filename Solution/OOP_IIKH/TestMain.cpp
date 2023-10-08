

#include <iostream>
#include<string>
#include "Student.h"
#include "DataBase.h"

int main() {
    StudentDB db;


    db.Add("2");
    db.Add("4");
    db.Add("5");
    db.Add("1");
    db.Add("3");

    db.array();


    db.SortByID();

    db.array();
   

    std::cout << std::endl;
    
}