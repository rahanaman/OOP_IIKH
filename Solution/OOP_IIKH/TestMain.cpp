

#include <iostream>
#include<string>
#include "Student.h"
#include "DataBase.h"
#include "txtReader.h"
#include "Program.h"
#include "Error.h"





int main(int argc, char* argv[]) {

    Program program("a.txt");

    //Program program(argv[1]);
    program.Execute();
    
    

    
    //End();


}


