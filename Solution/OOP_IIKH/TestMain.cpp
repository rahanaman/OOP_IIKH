#include <iostream>
#include<string>
#include "Student.h"
#include "DataBase.h"
#include "txtReader.h"
#include "Program.h"
#include "Error.h"





int main(int argc, char* argv[]) {
    
    Program program("a.txt");
    program.Execute();

    //Program program(argv[1]);
    
    /*
    StudentDB studentDB;

    Student a = Student("sam safdhnkj");
    Student c = Student("sam safdhasdasdasdasdasdnkj");
    Student b = Student("sam safd1dhnkj");

    studentDB.Insert(a);
    studentDB.Insert(b);
    studentDB.Insert(c);
    */
    //End();



}


