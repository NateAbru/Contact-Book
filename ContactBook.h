/*
 *Declaration of class ContactBook.
 *It declares various functions to manipulate
 *and retrieve information of a contact
 *
 *Author: Nathaniel Abreu
 */

#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H
#include "Address.h"
#include "Contact.h"
#include <string>

class ContactBook
{
   private:        
      Contact* contactArray; 
      int size; // current number of Contacts in the array
      int capacity; // capacity of array
      std::string ownerFN, ownerLN;
      void grow();
      void sort(); //sorted by last name then first name if both are equal
   public:
      // Constructor
      ContactBook();

      //Big three
      ~ContactBook(); //destructor
      ContactBook(const ContactBook& rightSide);  //copy constructor
      ContactBook& operator=(const ContactBook& rightSide);//assignment 

      //member functions
      int addContact();   
      int deleteContact(std::string lastName, std::string firstName);
      void updateContact(std::string lastName, std::string firstName);
      void searchContact(std::string lastName, std::string firstName); 
      void display();
      void setSize(int x);
      int getSize();
      int getCapacity();
      ContactBook& grow(ContactBook &array);
      void setOwnerFN(std::string x);
      void setOwnerLN(std::string y);
      std::string getOwnerFN();
      std::string getOwnerLN();
      void addFNInfo(std::string s, int n);
      std::string getFNInfo(int n);
      void addLNInfo(std::string s, int n);
      std::string getLNInfo(int n);
      void addPhoneInfo(std::string s, int n);
      std::string getPhoneInfo(int n);
      void addEmailInfo(std::string s, int n);
      std::string getEmailInfo(int n);
      void addHomeInfo(std::string s, int n);
      void addStateInfo(std::string s, int n);
      void addZipInfo(std::string s, int n);
      void addAptInfo(std::string s, int n);
      void addCityInfo(std::string s, int n);
      void addStreetInfo(std::string s, int n);
      std::string getHomeInfo(int n);
      std::string getStreetInfo(int n);
      std::string getAptInfo(int n);
      std::string getCityInfo(int n);
      std::string getStateInfo(int n);
      std::string getZipInfo(int n);
      //merges a 2nd contact book to the first
      void merge(ContactBook& other);
};
#endif
