#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class person {
private:
	char* second_name;
	char* first_name;
	char* surname;
	int number_person;
public:
	void set(char*, char*, char*, int);
	person();
	~person();

	person& person::operator=(const person &);

	char* getSN() { return second_name; }
	char* getFN() { return first_name; }
	char* getSU() { return surname; }
	int getNO() { return number_person; }
};

