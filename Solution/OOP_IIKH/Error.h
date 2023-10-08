#pragma once

#include<iostream>


class Error{
protected:
	int errorID;
public:
	Error(int e) :errorID(e) {}
	virtual void ErrorMessage() {}
};