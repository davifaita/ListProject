#ifndef _LISTEXCEPTIONN_H_
#define _LISTEXCEPTIONN_H_
#include <exception>

class ageException : public std::exception
{
public:
   ageException() {};
   ~ageException() {};
   const char* what() const override { return "Invalid Age Exception"; }
};

class courseException : public std::exception
{
public:
   courseException() {};
   ~courseException() {};
   const char* what() const override { return "Invalid Course Exception"; }
};

class idException : public std::exception
{
public:
   idException() {};
   ~idException() {};
   const char* what() const override { return "Invalid ID Exception"; }
};

class nameException : public std::exception
{
public:
   nameException() {};
   ~nameException() {};
   const char* what() const override { return "Invalid Name Exception"; }
};


class listException : public std::exception
{
public:
   listException() {};
   ~listException() {};
   virtual const char* what() const { return "Invalid input - Please enter 1 or 2."; }
};


#endif

