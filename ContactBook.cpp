/*
 *Defintion of class ContactBook
 *It defines the set of functions
 *that are used to manipute and retrieve information
 *on contacts
 *
 *Author: Nathaniel Abreu
 */

#include "ContactBook.h"
#include <string>
#include <iostream>

//Default constructor
ContactBook::ContactBook():size(0), 
			   capacity(10), 
			   ownerFN("none"), 
			   ownerLN("none")
{
   contactArray = new Contact[capacity];	
}
//Destructor
ContactBook::~ContactBook()
{
   if(contactArray != NULL)
   {
      delete[] contactArray;
   }
}
//Copy Constructor
ContactBook::ContactBook(const ContactBook& rightSide)
{
   size = rightSide.size;
   capacity = rightSide.capacity;
   ownerFN = rightSide.ownerFN;
   ownerLN = rightSide.ownerLN;
   if(size > 0)
   {	
      contactArray = new Contact[size];
      for(int i = 0; i < size; i++)
      {
         contactArray[i] = rightSide.contactArray[i];
      }
   }
} 				
//Assignment Operator
ContactBook& ContactBook::operator=(const ContactBook& rightSide)
{
   if(this == &rightSide)
   {
      return *this;
   }
   if(contactArray != NULL)
   {	
      delete[] contactArray;
   }	
   size = rightSide.size;
   capacity = rightSide.capacity;
   ownerFN = rightSide.ownerFN;
   ownerLN = rightSide.ownerLN;
   if(size > 0)
   {
      contactArray = new Contact[size];
      for (int i = 0; i < size; i++)
      {
         contactArray[i] = rightSide.contactArray[i];
      }
   }
   return *this;
}

//function to add another contact	
int ContactBook::addContact()
{
   if (size == capacity) grow();
   std::cout << "Please Enter Last Name, First Name, " 
   << "Address, Phone number and Email Address: " 
   << std::endl;
   std::cin >> contactArray[size];
   size++;
   sort();
   return size;
}

//function to delete an existing contact
int ContactBook::deleteContact(std::string lastName, std::string 
firstName)
{
   int count = 0;
   for(int i = 0; i < capacity; i++)
   {
      if((contactArray[i].getLastName() == lastName) && 
      (contactArray[i].getFirstName() == firstName))
      {
         size--;
	 count++;
	 for(int j = i; j < size + 1; j++)
         {
	    contactArray[j] = contactArray[j + 1];
	 }
      }
   }
   sort();
   if(count == 0) std::cout << "No Contact Found!" << std::endl;
      return size;
}

//function to change attributes of an existing contact	
void ContactBook::updateContact(std::string lastName, std::string firstName)
{
   int count = 0;
   for(int i = 0; i < capacity; i++)
   {
      if(contactArray[i].getLastName() == lastName && 
      contactArray[i].getFirstName()== firstName)
      {
         std::cin >> contactArray[i];
	 count++;
      }
   }
   sort();
   if(count == 0) std::cout << "No contact found!" << std::endl;
}	

//function to search for a contact that a user specifies	
void ContactBook::searchContact(std::string lastName, std::string 
firstName)
{
   sort();
   int count = 0;
   std::cout << "Contact found at index('s): ";
   for(int i = 0; i < size; i++)
   {
      if(contactArray[i].getLastName() == lastName && 
      contactArray[i].getFirstName() == firstName)
      {
         std::cout << i + 1 << " ";
	 count++;
      }
   }
   if(count == 0) std::cout << "No contact found!" << std::endl;
   else std::cout << std::endl;	
}			

//displays all contacts	
void ContactBook::display()
{
   sort();
   if(size > 0)
   {
      for(int i = 0; i < size; i++)
      {
         std::cout << "Index " << i + 1 << ":" << endl;
	 std::cout << contactArray[i] << std::endl;
      }
   }
   else std::cout << "No Contacts Found!" << std::endl;	
}

//mutator function for size
void ContactBook::setSize(int x)
{
   size = x;
}

//get functions for size and capacity
int ContactBook::getSize()
{
   return size;
}
int ContactBook::getCapacity()
{
   return capacity;
}

//function to double the capacity of contactArray once capacity is reached
void ContactBook::grow()
{		
   capacity = capacity * 2;
   Contact* temp = new Contact[capacity];
   for(int i = 0; i < size; i++)
   {
      temp[i] = contactArray[i];
   }
   delete[] contactArray;
   contactArray = temp;
}

//sorts contacts by comparing values lexicograhically
void ContactBook::sort()
{
   if(size > 1)
   {
      for(int i = 0; i < size; i++)
      {
         std::string smallest = contactArray[i].getLastName();
	 std::string smallest2 = contactArray[i].getFirstName();
	 int smallestIndex = i;
         for(int p = i + 1; p < size; p++)
         {
	    if(smallest.compare(contactArray[p].getLastName()) 
            > 0)
            {
	       smallestIndex = p;
	    }
	    if(smallest.compare(contactArray[p].getLastName()) 
	    == 0)
            {
	       if(smallest2.compare(contactArray[p].getFirstName())
	       > 0)
               {
	          smallestIndex = p;
	       }
	    }
         }
         Contact temp = contactArray[i];
         contactArray[i] = contactArray[smallestIndex]; 
         contactArray[smallestIndex] = temp;
      }
   }
}

//Mutator functions for owner name
void ContactBook::setOwnerFN(std::string x)
{
   ownerFN = x;
}
void ContactBook::setOwnerLN(std::string y)
{
   ownerLN = y;
}

//Get functions for owner name
std::string ContactBook::getOwnerFN()
{
   return ownerFN; 
} 
std::string ContactBook::getOwnerLN()
{
   return ownerLN;
}

//merges two contactBooks
void ContactBook::merge(ContactBook& other)
{
   int otherSize = other.getSize(); 
   for (int i = 0; i < otherSize; i++)
   {
      contactArray[size] = other.contactArray[i];
      size++;
      other.size--;
      if(size == capacity) grow();
   }
   sort();
}

//set of mutator and getter functions to alter and retrieve
//the private variables values from address and contact classes
void ContactBook::addFNInfo(std::string s, int n)
{
   contactArray[n].setFirstName(s);
}
std::string ContactBook::getFNInfo(int n)
{
   return contactArray[n].getFirstName();
}
void ContactBook::addLNInfo(std::string s, int n)
{
   contactArray[n].setLastName(s);
}
std::string ContactBook::getLNInfo(int n)
{
   return contactArray[n].getLastName();
}
void ContactBook::addPhoneInfo(std::string s, int n)
{
   contactArray[n].setPhone(s);
}
std::string ContactBook::getPhoneInfo(int n)
{
   return contactArray[n].getPhone();
}
void ContactBook::addEmailInfo(std::string s, int n)
{
   contactArray[n].setEmail(s);
}
std::string ContactBook::getEmailInfo(int n)
{
   return contactArray[n].getEmail();
}
void ContactBook::addHomeInfo(std::string s, int n)
{
   contactArray[n].setHome2(s);
}
void ContactBook::addStreetInfo(std::string s, int n)
{
   contactArray[n].setStreet2(s);
}
void ContactBook::addCityInfo(std::string s, int n)
{
   contactArray[n].setCity2(s);
}
void ContactBook::addZipInfo(std::string s, int n)
{
   contactArray[n].setZip2(s);
}
void ContactBook::addStateInfo(std::string s, int n)
{
   contactArray[n].setState2(s);
}
void ContactBook::addAptInfo(std::string s, int n)
{
   contactArray[n].setApt2(s);
}
std::string ContactBook::getHomeInfo(int n)
{
   return contactArray[n].getHome2();
}
std::string ContactBook::getStreetInfo(int n)
{
   return contactArray[n].getStreet2();
}
std::string ContactBook::getAptInfo(int n)
{
   return contactArray[n].getApt2();
}
std::string ContactBook::getCityInfo(int n)
{
   return contactArray[n].getCity2();
}
std::string ContactBook::getStateInfo(int n)
{
   return contactArray[n].getState2();
}
std::string ContactBook::getZipInfo(int n)
{
   return contactArray[n].getZip2();
}	


