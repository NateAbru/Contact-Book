// Contact.cpp
/*
 * Definition of class Contact.  It is used to
 * store and retrieve information on a contact person
 * such as their last/first name, phone number, email address
 * and complete address and output such information
 * as well as compare contacts
 *
 * Author: Nathaniel Abreu
*/

#include "Contact.h"
#include "Address.h"
#include <string>
#include <cstdlib>
#include <iostream>

// Default Constructor

Contact::Contact() : lastName("None"),
		     firstName("None"),
	             phone("9999999999"),
                     email("doe@nowhere.com")
{
   //empty
}

// Second Constructor

Contact::Contact(std::string x, std::string y, Address z, std::string
a, std::string b)
{
   setLastName(x);  
   setFirstName(y);
   setAddress(z);
   setPhone(a); 
   setEmail(b);
}

// Mutator Functions for the instance variables

void Contact::setLastName(std::string x)
{
   lastName = x;
}
void Contact::setFirstName(std::string y)
{
   firstName = y;
}
void Contact::setPhone(std::string a)
{
   if(a.length() != 10)
      {
         std::cout << "Invalid! Phone Number" 
		<< " must be 10 digits!" << std::endl;
	 exit(1);
      }
   phone = a;
}
void Contact::setEmail(std::string b)
{
   if (b.find("@") == (int) -1) 
      {
         std::cout << "Invalid email!\n";
	 exit(1);
      }
   email = b;
}
void Contact::setAddress(Address z)
{
   z.input();
}

// Accessor Functions for instance variables

std::string Contact::getLastName()
{
   return lastName;
}
std::string Contact::getFirstName()
{
   return firstName;
}
std::string Contact::getAddress()
{
   return getHome2() + " " + getStreet2() + " "
   + getApt2() + "\n" + getCity2() + ", "
   + getState2() + " " + getZip2();
}
std::string Contact::getPhone()
{
   return phone;
}
std::string Contact::getEmail()
{
   return email;
}

// Insertion and Exertion Overloaders

istream &operator>>(istream &input1, Contact &c)
{    
   std::cout << "Last Name: ";
   std::string m;
   input1 >> m;
   c.setLastName(m);
   std::cout << "First Name: ";
   std::string n;
   input1 >> n;
   c.setFirstName(n);
   c.address.input();
   std::cout << "Phone #: ";
   std::string o;
   input1  >> o;
   c.setPhone(o);
   std::cout << "Email: ";
   std::string p;
   input1 >> p;
   c.setEmail(p);
   return input1;
}
ostream &operator<<(ostream &output1, const Contact &c)
{
   output1 << c.firstName << " " << c.lastName
   << std::endl;
   c.address.output();
   output1 << c.phone << std::endl << c.email;
   return output1;
}

// Comparison Overloaders Member Functions

bool Contact::operator < (Contact c)
{
   if (this->lastName.compare(c.lastName) < 0)
   {
      if(this->firstName.compare(c.firstName) < 0)
      {
         return true;
      }
   }
   return false;
} 		  
bool Contact::operator > (Contact c)
{
   if (this->lastName.compare(c.lastName) > 0)
   {
      if(this->firstName.compare(c.firstName) > 0)
      {
         return false;
      }
   }
   return true;
}
bool Contact:: operator==(Contact c)
{
   if (this->lastName.compare(c.lastName) == 0)
      {
         if(this->firstName.compare(c.firstName) == 0)
	    {
               return true;
            }
      }
   return false;
}
bool Contact:: operator!=(Contact c)
{
   if (this->lastName.compare(c.lastName) != 0)
      {
         return true;
      }
      else if(this->firstName.compare(c.firstName) != 0)
      {
         return true;
      }
   return false;
}	 

// Mutator Functions for Address Components

void Contact::setHome2(string s)
{
   address.setHome(s);
}
void Contact::setStreet2(string s)
{
   address.setStreet(s);
}
void Contact::setApt2(string s)
{
   address.setApt(s);
}
void Contact::setCity2(string s)
{
   address.setCity(s);
}
void Contact::setState2(string s)
{
   address.setState(s);
}
void Contact::setZip2(string s)
{
   address.setZip(s);
}

// Accessor Functions for Address Components

string Contact::getHome2()
{
   return address.getHome();
}
string Contact::getCity2()
{
   return address.getCity();
}
string Contact::getState2()
{
   return address.getState();
}
string Contact::getZip2()
{
   return address.getZip();
}
string Contact::getApt2()
{
   return address.getApt();
}
string Contact::getStreet2()
{
   return address.getStreet();
}
