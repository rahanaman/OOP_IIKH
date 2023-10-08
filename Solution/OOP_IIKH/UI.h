#pragma once

#include<iostream>

#include "TxtReader.h"
class UI {
public:
	txtReader t;
	UI(std::string s): t(s){
		t.save("id1");
	}

	~UI() {
		t.save("id2");
	}
};