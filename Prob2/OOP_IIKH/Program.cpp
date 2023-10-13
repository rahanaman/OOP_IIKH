#include "Program.h"
void Program::Init() {
	std::vector<Student*> list = txtReader.Init();
	for (auto s : list) {
		db.Insert(s);
	}
}

int Program::GetInput() {
	int inputNum;
	std::cin >> inputNum;
	return inputNum;
	system("CLS");
}


void Program::MainMenu() {
	//print Menu
	system("CLS");
	std::cout << "1. Insertion" << std::endl;
	std::cout << "2. Search" << std::endl;
	std::cout << "3. Sorting Option" << std::endl;
	std::cout << "4. Exit" << std::endl;
	std::cout << "> ";


	//Get User Input
	int inputNum = GetInput();

	switch (inputNum) {
	case 1:
		InsertMenu();break;
	case 2:
		SearchMenu();break;
	case 3:
		SortingOptionMenu();break;
	case 4:
		EndProgram();break;
	default:break;
	}
	return;
}

void Program::InsertMenu() {
	system("CLS");
	std::string Name, ID, DeptName, BirthYear, Tel;
	std::cout << "Name (up to 15 characters) ? ";
	std::cin >> Name;
	std::cout << "Student ID (10 digits) ? ";
	std::cin >> ID;
	std::cout << "Birth Year (4 digits) ? ";
	std::cin >> BirthYear;
	std::cout << "Department ? ";
	std::cin >> DeptName;
	std::cout << "Tel ? ";
	std::cin >> Tel;

	Student* student = new Student(Name, ID, BirthYear, DeptName, Tel);

	db.Insert(student);
}

void Program::SearchMenu() {
	system("CLS");
	std::cout << "- Search -" << std::endl;
	std::cout << "1. Search by name" << std::endl;
	std::cout << "2. Search by student ID (10 numbers)" << std::endl;
	std::cout << "3. Search by birth year (4 numbers)" << std::endl;
	std::cout << "4. Search by department name" << std::endl;
	std::cout << "5. List All" << std::endl;
	std::cout << "> ";

	int inputNum = GetInput();

	switch (inputNum) {
	case 1:
		Search_Name(); break;
	case 2:
		Search_ID(); break;
	case 3:
		Search_BirthYear(); break;
	case 4:
		Search_DeptName(); break;
	case 5:
		Search_ListAll();
		break;
	default:
		break;
	}
}


void Program::SortingOptionMenu() {
	system("CLS");
	std::cout << "- Sorting Option" << std::endl;
	std::cout << "1. Sort by Name" << std::endl;
	std::cout << "2. Sort by Student ID" << std::endl;
	std::cout << "3. Sort by Birth Year" << std::endl;
	std::cout << "4. Sort by Department name" << std::endl;
	std::cout << "> ";

	int inputNum = GetInput();

	switch (inputNum) {
	case 1:
		db.SortByName(); break;
	case 2:
		db.SortByID(); break;
	case 3:
		db.SortByBirthYear(); break;
	case 4:
		db.SortByDeptName(); break;
	default: break;
	}
}


void Program::Search_Name() {
	system("CLS");
	std::cout << "Name keyword? ";
	std::string name; std::cin >> name;

	std::cout << std::endl;
	std::vector<Student> list = db.SearchByName(name);
	Outputformat();
	for (auto s : list) {
		ListStudent(s);
	}
}
void Program::Search_ID() {
	system("CLS");
	std::cout << "Student ID keyword? ";
	std::string id; std::cin >> id;

	std::cout << std::endl;
	std::vector<Student> list = db.SearchByID(id);
	Outputformat();
	for (auto s : list) {
		ListStudent(s);
	}
}
void Program::Search_BirthYear() {
	system("CLS");
	std::cout << "Birth Year keyword? ";
	std::string year; std::cin >> year;

	std::cout << std::endl;
	std::vector<Student> list = db.SearchByBirthYear(year);
	Outputformat();
	for (auto s : list) {
		ListStudent(s);
	}
}

void Program::Search_DeptName() {
	system("CLS");
	std::cout << "Dept Name keyword? ";
	std::string name; std::cin >> name;
	std::cout << std::endl;
	std::vector<Student> list = db.SearchByDeptName(name);
	if (list.size() == 0) {
		std::cout << "No Data"; return;
	}
	Outputformat();
	for (auto s : list) {
		ListStudent(s);
	}
}
void Program::Search_ListAll() {
	system("CLS");
	std::vector<Student> list = db.GetSortedDB();
	Outputformat();
	for (auto s : list) {
		ListStudent(s);
	}
}

void Program::ListStudent(Student& s) {
	std::cout << s.GetName() << " ";
	for (int i = 0; i < NAME_LEN - s.GetName().length(); ++i)std::cout << " ";
	std::cout << std::setw(ID_LEN) << s.GetID() << " ";
	std::cout << s.GetDeptName() << " ";
	for (int i = 0; i < DEPT_LEN - s.GetDeptName().length(); ++i)std::cout << " ";
	std::cout << std::setw(BIRTH_LEN) << s.GetBirthYear() << " ";
	std::cout << std::setw(TEL_LEN) << s.GetTel() << std::endl;
}

void Program::Outputformat() {
	std::cout << "Name            " << "studentID  " << " Dept                     " << "Birth Year " << "Tel        " << std::endl;
}
