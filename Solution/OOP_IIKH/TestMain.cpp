

#include <iostream>
#include<string>
#include "Student.h"
#include "DataBase.h"
#include "txtReader.h"
#include "Program.h"
#include "Error.h"






void aa() {
    
    
}

int main(int argc, char* argv[]) {

    //Program program(argv[1]);
    //program.Execute();
    

    std::string s = "\"adafdaf\"aksjhfkjadsh\"kfjh\"";
    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) == '\"') {
            s.insert(i++, "\"");
        }
    }

    std::cout << s;

    txtReader t("a.txt");



    //End();


}


