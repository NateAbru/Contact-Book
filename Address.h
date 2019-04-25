// Address.h
/*
 * Declaration of class Address. It is used to store and retrieve 
 * information on Address such as home number, street, apt#, city,
 * state, and zip.
 *
 * Author: Nathaniel Abreu
*/

#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>

class Address
{
   private:
      // instance variables
      std::string home;
      std::string street;
      std::string apt;
      std::string city;
      std::string state;
      std::string zip;

   public:
      // Default constructor
      // Initializes all variable to empty string
      Address();

      // Accessor functions for instance variables
      std::string getHome() const;
      std::string getStreet() const;
      std::string getApt() const;
      std::string getCity() const;
      std::string getState() const;
      std::string getZip() const;

      // Mutator functions for instance variables
      void setHome(std::string s);
      void setStreet(std::string s);
      void setApt(std::string s);
      void setCity(std::string s);
      void setState(std::string s);
      void setZip(std::string s);

      // Function that prints Address to console
      void output() const;

      // Function that asks the information for the
      // instance variables 
      void input();
};
#endif
