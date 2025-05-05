#include <conio.h>
#include <iostream>
#include <cctype>
#include <algorithm>
#include "UserInterface.h"
#include "Command.h"
#include "ListExceptions.h"



Student UserInterface::getStudent(int id) {
   system("cls");
   Student s;
   s.id = id;
   std::cout << "Insert the student name: ";
   std::cin.ignore();
   std::cin.getline(s.name,50);
   std::cout << "Insert the student age: ";
   std::cin >> s.age;
   std::cin.ignore();
   std::cout << "Insert the course: ";
   std::cin.getline(s.course,50);
   return s;
}

void UserInterface::showMenu() {
   system("cls");
   std::cout << "___________MENU____________\n";
   std::cout << "1- Add Student\n";
   std::cout << "2- List Students\n";
   std::cout << "3- Update Student\n";
   std::cout << "4- Delete Student\n";
   std::cout << "5- Clear all\n";
   std::cout << "6- Exit\n";
   std::cout << "___________________________" << std::endl;
}

int UserInterface::getOptions()
{
   int options;
   std::cout << "\nEnter your choice: ";
   std::cin >> options;
   return options;
}

void UserInterface::addStudentOp() {
   int newId = Command::getNextId();
   Student s = UserInterface::getStudent(newId);
   Command::addStudent(s);
   std::cout << "\nStudent successfully added.\n";
   UserInterface::keyContinue();
}


void UserInterface::listStudentsOp()
{
   system("cls");
   std::cout << "Listing students: \n";
   Command::listStudents();
}

void UserInterface::updateStudentOp()
{
   system("cls");
   int id;
   std::cout << "Student ID to update: ";
   std::cin >> id;
   Student s = UserInterface::getStudent(id);
   if (Command::updateStudent(id,s))
      std::cout << "\nStudent successfully updated.\n";
   UserInterface::keyContinue();
}

void UserInterface::deleteStudentOp()
{
   int id;
   std::cout << "Student ID to delete: ";
   std::cin >> id;
   Command::deleteStudent(id);
   std::cout << "The student ID " << id << " was successfully deleted.\n";
   UserInterface::keyContinue();
}

void UserInterface::clearOp()
{
  Command::clearDataBase();
  std::cout << "Successfully cleaned.";
  UserInterface::keyContinue();
}

void UserInterface::exitOp(bool& running)
{
   std::cout << "Finishing...\n";
   running= false;
}

void UserInterface::displayStudent(const Student& s) {
   std::cout << "ID: " << s.id << "\n";
   std::cout << "Name: " << s.name << "\n";
   std::cout << "Age: " << s.age << "\n";
   std::cout << "Course: " << s.course << "\n";
   std::cout << "-------------------------\n";
 }

 void UserInterface::keyContinue()
 {
    std::cout << "\npress any key to continue...";
    _getch();
 }
