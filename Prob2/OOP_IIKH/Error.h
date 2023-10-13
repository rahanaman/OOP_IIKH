#pragma once

#include<iostream>

//Base Error Class
class Error{
protected:
	int errorID;
public:
	Error(int e) :errorID(e) {}
	virtual void ErrorMessage() {}
};