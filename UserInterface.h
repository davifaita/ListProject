#ifndef INCLUDED_USER_INTERFACE_H
#define INCLUDED_USER_INTERFACE_H

#include "Student.h"

class UserInterface {
public:
   static Student getStudent(int id);
   static void showMenu();
   static int getOptions();

   static void addStudentOp();
   static void listStudentsOp();
   static void updateStudentOp();
   static void deleteStudentOp();
   static void clearOp();
   static void exitOp(bool& running);
   static void displayStudent(const Student& s);

   static void keyContinue();

};

#endif


