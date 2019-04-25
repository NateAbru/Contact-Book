// Address.cpp
/*
 * Definition of class Address. It is used to store and retrieve 
 * information on Address such as home number, street, apt#, city,
 * state, and zip.
 *
 * Author: Nathaniel Abreu
*/

#include "Address.h"
#include <string>
#include <iostream>

// Default Constructor. Initializes instance
// variables to an empty string
Address::Address() : home("N/A"),
                     street("N/A"),
                     apt("none"),
                     city("N/A"),
                     state("N/A"),
                     zip("N/A")
{
   // empty
}

// Mutator functions for instance variables.

void Address::setHome(std::string s)
{
   home = s;
}
void Address::setStreet(std::string s)
{
   street = s;
}
void Address::setApt(std::string s)
{
   apt = s;
}
void Address::setCity(std::string s)
{
   city = s;
}
void Address::setState(std::string s)
{
   state = s;
}
void Address::setZip(std::string s)
{
   zip = s;
}

// Accessor Functions for instance variables

std::string Address::getHome() const
{
   return home;
}

std::string Address::getStreet() const
{
   return street;
}

std::string Address::getApt() const
{
   return apt;
}

std::string Address::getCity() const
{
   return city;
}

std::string Address::getState() const
{
   return state;
}

std::string Address::getZip() const
{
   return zip;
}

// Function that outputs address to console

void Address::output() const
{
   std::cout << home << " " << street;
   if (apt != "none") std::cout << ", Apt# " << apt;
   std::cout << std::endl;
   std::cout << city << ", " << state << " " << zip << std::endl;
}

// Function that asks for information for address

void Address::input()
{
   char choice;
   std::cout << "Apartment(a) or House(h) (a/h):> ";
   std::cin >> choice;
   std::cout << std::endl;

   std::cin.ignore(10, '\n');
   std::cout << "Enter home number (Ex: 127-75)___: ";
   std::getline(std::cin, home);
   std::cout << "Enter street number (Ex: 70th RD): ";
   std::getline(std::cin, street);
 
   if (choice == 'a')
   {
      std::cout << "Enter Apartment Number: (Ex: 1A)_: ";
      std::getline(std::cin, apt);
   }
   else
      apt = "none";

   std::cout << "Enter city (Ex: Flushing)________: ";
   std::getline(std::cin, city);

   std::cout << "Enter state (Ex: NY)_____________: ";  
   std::getline(std::cin, state);

   std::cout << "Enter zip code (Ex: 11367)_______: ";
   std::getline(std::cin, zip);
}
