#ifndef INCLUDED_COMMAND_H
#define INCLUDED_COMMAND_H

#include "Student.h"
#include "Info.h"
#include <string>


class Command {
private:
   static const std::string dataFile;
   static const std::string infoFile;

   static bool wasDeleted;
   static Info readInfo();
   static void writeInfo(const Info& info);

public:
   static void initialize();

   static void addStudent(const Student& s);
   static void listStudents();
   static bool updateStudent(int id,const Student& s);
   static bool deleteStudent(int id);
   static void clearDataBase();
   static bool needPurge();
   static bool purge();

   static int getNextId();
};

#endif
