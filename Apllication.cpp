#include <fstream>
#include <iostream>
#include "Apllication.h"
#include "UserInterface.h"
#include "AppCommands.h"
#include "Command.h"

void Application::run()
{
   bool running = true;

   UserInterface ui;
   AddStudentCommand add(ui);
   ListStudentsCommand list(ui);
   UpdateStudentCommand update(ui);
   DeleteStudentCommand del(ui);
   ClearCommand clear(ui);
   ExitCommand exit(ui,running);

   while (running) {
      ui.showMenu();
      int option= ui.getOptions();

      switch (option) {
      case 1: add.execute();break;
      case 2: list.execute();break;
      case 3: update.execute();break;
      case 4: del.execute();break;
      case 5: clear.execute();break;
      case 6: exit.execute();break;
      }
   } 
}
