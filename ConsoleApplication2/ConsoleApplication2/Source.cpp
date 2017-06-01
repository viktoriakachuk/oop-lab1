#include "header.h"
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <exception>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

person::person() {
	second_name = nullptr;
	first_name = nullptr;
	surname = nullptr;
	number_person = NULL;
}

person::~person() {
	delete[] second_name;
	delete[] first_name;
	delete[] surname;
	number_person = NULL;
}

void person::set(char* sn, char* fn, char* su, int np) {
	second_name = new char[strlen(sn) + 1];//separate by methods
	strcpy(second_name, sn);
	///////////////////////////
	first_name = new char[strlen(fn) + 1];
	strcpy(first_name, fn);
	surname = new char[strlen(su) + 1];
	strcpy(surname, su);
	number_person = np;
}

person& person::operator=(const person &per) { //перегрузка оператора = первым способом
	if (this != &per) { //проверка на самоприсваивание
		delete second_name;
		delete first_name;
		delete surname;

		second_name = new char[strlen(per.second_name) + 1];
		strcpy(second_name, per.second_name);
		first_name = new char[strlen(per.first_name) + 1];
		strcpy(first_name, per.first_name);
		surname = new char[strlen(per.surname) + 1];
		strcpy(surname, per.surname);
		number_person = per.number_person;
	}
	return *this; //возвращает содержимое объекта на который указывает this
}