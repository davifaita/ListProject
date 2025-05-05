#ifndef INCLUDED_APP_COMMAND_H_ 
#define INCLUDED_APP_COMMAND_H_


class AppCommand {
public:
   virtual void execute()= 0;
   virtual ~AppCommand()= default;
};

#endif