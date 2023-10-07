

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

    for (auto i : db.DBindex) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    for (auto i : db.studentDB) {
        std::cout << i.GetID() << " ";
    }
    std::cout << std::endl;

    db.SortByID();

    db.array();
    for (auto i : db.DBindex) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
    
}