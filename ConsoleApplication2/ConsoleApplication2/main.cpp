#include "header.h"
#include "headerInput.h"
#include "headerFile.h"
#include "headerMenu.h"
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <exception>


using namespace std;

person employee[10];
int employee_counter = 0;
int flags;
char c;
int menu_choice = 0;
const string TYPE = "Type employee's ";
const string FIRST_NAME = "first name ";
const string SECOND_NAME = "second name ";
const string SURNAME = "surname ";
const string NUMBER = "number ";
const string _FILE = "data.txt";
//int printErrorMessage(MenuException& e){
//	printf("%s\n", e.what());
//	return 0;
//}
void checkName(const char* name){
	for (int i = 0; i < strlen(name); i++)
		if (!isalpha(name[i]))
		{
		throw NameException();
		}
}


int menu(){
	try{
		cout << endl << endl << "Menu:" << endl;
		cout << "1) Input" << endl;
		cout << "2) Output" << endl;
		cout << "3) Exit" << endl;
		cout << "Your choice: " << endl;
		cin >> menu_choice;
		flags = cin.rdstate(); 
		if (flags & ios::failbit) {
			cin.clear(0);
			cin >> c;
			throw MenuException();
		}
		else if (menu_choice != 1 && menu_choice != 2 && menu_choice != 3)
			throw MenuException();
		else
		return menu_choice;
	}
	catch (MenuException& e) {
		printf("%s\n", e.what());
		return 0;
	
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (menu_choice != 3){
		switch (menu()) {
		case 1: {
			try {
				ofstream fout(_FILE, ios_base::trunc); //режим открытия (с удалением содержимого, если существует) арр
				if (!fout.is_open()){
					throw CreateFileException();
				}
				else{
					int var;
					do {

						char lastName[40];
						char firstName[40];
						char secondName[40];
						int no;
						person empl;

						try {
								cout << TYPE << NUMBER;
								cin >> no;
								flags = cin.rdstate(); //чтение состояния потока cin
								if (flags & ios::failbit) {
									cin.clear(0);//сброс всех состояний потока
									cin >> c;//удаление не int значения из потока
									throw NumberException(); 
								}
							} 
						catch(InputException& e) {
							printf("%s\n", e.what());
							return 0;
						}
					
						try{
							cout << TYPE << SURNAME;
							cin >> lastName;
							checkName(lastName);
						}
						catch (InputException& e) {
							printf("%s\n", e.what());
							return 0;
						}
						try{
							cout << TYPE << FIRST_NAME;
							cin >> firstName;
							checkName(firstName);
						}
						catch (InputException& e) {
							printf("%s\n", e.what());
							return 0;
						}
						try{
							cout << TYPE << SECOND_NAME;
							cin >> secondName;
							checkName(secondName);
						}
						catch (InputException& e) {
							printf("%s\n", e.what());
							return 0;
						}
					
						empl.set(lastName, firstName, secondName, no);
						employee[employee_counter] = empl;
						employee_counter++;
						cout << "Do you want to continue?" << endl << "1 >> yep" << endl << "2 >> no" << endl << "Your choice: ";
						cin >> var;
					} while (var == 1);

					for (int i = 0; i < employee_counter; i++)
						fout << employee[i].getNO() << " " //непосредственно запись
						<< employee[i].getSN() << " "
						<< employee[i].getFN() << " "
						<< employee[i].getSU() << " "
						<< endl;

					fout.close();
				}
				cout << "Successful input";
				break;
			}
			catch (FileException& e) {
				printf("%s\n", e.what());
				return 0;
			}
		}
		case 2: {
			char lastName[40];
			char firstName[40];
			char secondName[40];
			int no;
			try{
				ifstream fin(_FILE, ios_base::in);
				if (!fin.is_open()){ // если файл не открыт
					throw OpenFileException();
				}
				else {
					while (employee_counter != 0) {
						fin >> no;
						cout << "Employee's number: " << no << endl;
						fin >> lastName;
						cout << SURNAME << lastName << endl;
						fin >> firstName;
						cout << FIRST_NAME << firstName << endl;
						fin >> secondName;
						cout << SECOND_NAME << secondName << endl << endl;
						employee_counter--;
					}

					fin.close();
				}

				break;
			}
			catch (FileException& e) {
				printf("%s\n", e.what());
				return 0;
			}
		}

		}
	}
}