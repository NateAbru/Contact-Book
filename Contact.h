// Contact.h
/*
 * Declaration of the class Contact. It is used to
 * store and retrieve information on a contact person
 * such as their last/first name, phone number, email address
 * and complete address and output such information
 * as well as compare contacts
 *
 * Author: Nathaniel Abreu
*/

#ifndef CONTACT_H
#define CONTACT_H
#include "Address.h"
#include <string>
using namespace std;

class Contact
{
   private:
      std::string lastName, firstName, phone, email;
      Address address;

   public:
      // Default Constructor. Sets empty values to
      // the instance variables
      Contact();
        
      // Second Contructor. Sets values to the instance
      // variables according to user input
      Contact(std::string x, std::string y, Address z, std::string 
      a, std::string b);
        
      // Accessor Functions
      std::string getLastName();
      std::string getFirstName();
      std::string getPhone();
      std::string getEmail();
      std::string getAddress();

      // Mutator Functions
      void setLastName(std::string x);
      void setFirstName(std::string y);
      void setPhone(std::string a);
      void setEmail(std::string b);
      void setAddress(Address z);
	
      // Comparison overloaders Member Functions
      bool operator < (Contact c);
      bool operator > (Contact c);
      bool operator==(Contact c);
      bool operator!=(Contact c);

      // Insertion and Exertion overloaders
      friend istream &operator>>(istream &input1, Contact &c);
      friend ostream &operator<<(ostream &output1, const Contact &c);

      // Mutator Functions for Address Components
      void setHome2(std::string s);
      void setStreet2(std::string s);
      void setApt2(std::string s);
      void setCity2(std::string s); 
      void setState2(std::string s);
      void setZip2(std::string s);

      // Accessor Functions for Address Components
      std::string getHome2();
      std::string getStreet2();
      std::string getApt2();
      std::string getCity2();
      std::string getState2();	
      std::string getZip2();
};
#endif
