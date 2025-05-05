#include <iostream>
#include <fstream>
#include "Student.h"
#include "Command.h"
#include "UserInterface.h"
#include "Apllication.h"

int main() {
   Application app;
   app.run();
   Command::needPurge();
   return 0;
}
