#pragma once
#include <iostream>
#include <string>

using namespace std;

class MenuException : public exception {
public:
	virtual const char* what() const throw() {//virtual
		return "Wrong menu choice";
	}
};