#include "TxtReader.h"



std::vector<Student*> txtReader::Read() {
	std::vector <Student*> list;
	std::string str;
	while (!file.eof()) {
		std::getline(file, str);
		if (str == "") break;
		std::vector<std::string> atts = ParseString(str);

		Student* student = new Student(atts[0], atts[1], atts[2], atts[3], atts[4]);
		list.push_back(student);
	}
	file.close();
	return list;
}

std::vector<std::string> txtReader::ParseString(std::string& s) {
	std::sregex_token_iterator it(s.begin(), s.end(), SPLIT_ATT, -1), end;
	std::vector<std::string> atts = std::vector<std::string>(it, end);
	for (int i = 0; i < atts.size(); ++i) {
		atts[i].erase(remove(atts[i].begin(), atts[i].end(), ' '), atts[i].end());
		atts[i].erase(0, 1);
		atts[i].erase(atts[i].size() - 1, atts[i].size());
	}
	return atts;
}


std::string txtReader::IntoString(const Student& s) {
	std::string str;
	str += "\"" + s.GetName() + "\",";
	str += "\"" + s.GetID() + "\",";
	str += "\"" + s.GetBirthYear() + "\",";
	str += "\"" + s.GetDeptName() + "\",";
	str += "\"" + s.GetTel() + "\"";
	str += "\n";

	return str;
}

std::vector<Student*> txtReader::Init() {
	file.open(filepath, std::ios::in);
	if (file.is_open()) {
		return Read();
	}
}


void txtReader::save(const std::vector<Student>& list) {
	file.open(filepath, std::ios::out | std::ios::trunc);
	for (auto s : list) {
		file << IntoString(s);
	}
	file.close();
}