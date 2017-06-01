#pragma once
#include <iostream>
#include <string>

using namespace std;

class InputException : public exception {
public:
	virtual const char* what() const throw() {
		return "Wrong Input";
	}
};

class NameException : public InputException {
public:
	const char* what() const throw() {
		return "Wrong symbols";
	}
};

class NumberException : public InputException {
public:
	const char* what() const throw() {
		return "Only numbers allowed";
	}
};