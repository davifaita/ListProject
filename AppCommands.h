#pragma once
#include "AppCommand.h"
#include "UserInterface.h"

class AddStudentCommand : public AppCommand {
private:
   UserInterface& ui;

public:
   AddStudentCommand(UserInterface& ui) : ui(ui) {}
   void execute() override {
      ui.addStudentOp();
   }
};

class ListStudentsCommand : public AppCommand {
private:
   UserInterface& ui;

public:
   ListStudentsCommand(UserInterface& ui) : ui(ui) {}
   void execute() override {
      ui.listStudentsOp();
   }
};

class UpdateStudentCommand : public AppCommand {
private:
   UserInterface& ui;

public:
   UpdateStudentCommand(UserInterface& ui) : ui(ui) {}
   void execute() override {
      ui.updateStudentOp();
   }
};

class DeleteStudentCommand : public AppCommand {
private:
   UserInterface& ui;

public:
   DeleteStudentCommand(UserInterface& ui) : ui(ui) {}
   void execute() override {
      ui.deleteStudentOp();
   }
};

class ClearCommand : public AppCommand {
private:
   UserInterface& ui;

public:
   ClearCommand(UserInterface& ui) : ui(ui) {}
   void execute() override {
      ui.clearOp();
   }
};

class ExitCommand : public AppCommand {
private:
   UserInterface& ui;
   bool& running;

public:
   ExitCommand(UserInterface& ui,bool& running) : ui(ui),running(running) {}
   void execute() override {
      ui.exitOp(running);
   }
};

