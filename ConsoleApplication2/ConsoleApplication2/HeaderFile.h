#pragma once
#include <iostream>
#include <string>

using namespace std;

class FileException : public exception {
public:
	virtual const char* what() const throw() {
		return "file error";
	}
};

class CreateFileException : public FileException {
public:
	const char* what() const throw() {
		return "file creation error";
	}
};

class OpenFileException : public FileException {
public:
	const char* what() const throw() {
		return "file opening error";
	}
};