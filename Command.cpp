#include <fstream>
#include <iostream>
#include <conio.h>
#include "Command.h"
#include "UserInterface.h"

const std::string Command::dataFile = "students.dat";
const std::string Command::infoFile = "students.info";

bool Command::wasDeleted= false;

void Command::initialize() {
   std::ifstream file(infoFile,std::ios::binary);
   if (!file) {
      Info info ={0, 1, 0};
      writeInfo(info);
   }
}


Info Command::readInfo() {
   Info info;
   std::ifstream file(infoFile,std::ios::binary);
   if (file.read(reinterpret_cast<char*>(&info),sizeof(Info))) {
      return info;
   }
   return {0, 1, 0}; 
}



void Command::writeInfo(const Info& info) {
   std::ofstream file(infoFile,std::ios::binary | std::ios::trunc);
   file.write(reinterpret_cast<const char*>(&info),sizeof(Info));
}


int Command::getNextId() {
   Info info = readInfo();
   int id = info.nextId;
   info.nextId++;
   writeInfo(info);
   return id;
}



void Command::addStudent(const Student& student) {
   std::ofstream file(dataFile,std::ios::binary | std::ios::app);
   if (file.is_open()) {
      file.write(reinterpret_cast<const char*>(&student),sizeof(Student));

      Info info = readInfo();
      info.totalRecords++;
      writeInfo(info);
   }
   else 
      std::cerr << "Error opening file for reading.\n";
}


void Command::listStudents() {
   std::ifstream file(dataFile,std::ios::binary);
   if (file.is_open()) {
      Student s;
      while (file.read(reinterpret_cast<char*>(&s),sizeof(Student))) {
         if (s.valid) 
            UserInterface::displayStudent(s);
      }
      UserInterface::keyContinue();
   }
   else 
      std::cerr << "Error opening file for reading.\n";
}


bool Command::updateStudent(int id,const Student& updatedStudent) {
   std::fstream file(dataFile,std::ios::binary | std::ios::in | std::ios::out);
   if (!file) {
      std::cerr << "Error opening file for reading.\n";
      return false;
   }

   Student s;
   while (file.read(reinterpret_cast<char*>(&s),sizeof(Student))) {
      if (s.id == id) {
         file.seekp(-static_cast<int>(sizeof(Student)),std::ios::cur);
         file.write(reinterpret_cast<const char*>(&updatedStudent),sizeof(Student));
         return true;
      }
   }
   std::cerr << "Student not found.\n";
   return false;
}


bool Command::deleteStudent(int id) {
   system("cls");
   std::fstream file(dataFile,std::ios::binary | std::ios::in | std::ios::out);
   if (!file) {
      std::cerr << "Error opening file for reading.\n";
      return false;
   }

   Student s;
   while (file.read(reinterpret_cast<char*>(&s),sizeof(Student))) {
      if (s.id == id) {
         s.valid= false; 
         file.seekp(-static_cast<int>(sizeof(Student)),std::ios::cur);
         file.write(reinterpret_cast<const char*>(&s),sizeof(Student));

         Info info = readInfo();
         info.deletedRecords++;
         writeInfo(info);

         wasDeleted= true;
         return true;
      }
   }
   std::cerr << "Student not found.\n";
   return false;
}

void Command::clearDataBase() {
  
   std::ofstream dataFile(dataFile,std::ios::binary | std::ios::trunc);

   if (!dataFile.is_open()) 
      std::cerr << "Error.\n";
   
   Info info = readInfo();
   info.nextId = 1; 
   info.totalRecords = 0; 
   info.deletedRecords = 0;  
   writeInfo(info);
}

bool Command::needPurge()
{
   if (wasDeleted)
      return purge();
   return false;
}

bool Command::purge() {

   const std::string tempFile = "tempStudent.dat";

   std::ifstream inFile(dataFile,std::ios::binary);
   std::ofstream outFile(tempFile,std::ios::binary);

   if (!inFile || !outFile) {
      std::cerr << "Failed to open file(s) during purge.\n";
      return false;
   }

   Student s;
   while (inFile.read(reinterpret_cast<char*>(&s),sizeof(Student))) {
      if (s.valid) {
         outFile.write(reinterpret_cast<const char*>(&s),sizeof(Student));
      }
   }

   inFile.close();
   outFile.close();

  
   if (std::remove(dataFile.c_str()) != 0) {
      std::cerr << "Failed to delete original data file.\n";
      return false;
   }

   if (std::rename(tempFile.c_str(),dataFile.c_str()) != 0) {
      std::cerr << "Failed to rename temp file.\n";
      return false;
   }

   return true;
}
