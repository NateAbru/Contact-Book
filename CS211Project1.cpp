/*
 *Driver file for Address, Contact, ContactBook classes
 *
 *Author: Nathaniel Abreu
 */

#include "Address.h"
#include "Contact.h"
#include "ContactBook.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
void displayBooks(ContactBook* c, int size);
int bookIndex(ContactBook* c, std::string firstName, std::string 
lastName, int size);
int addContactBook(ContactBook* c, int size);
int removeContactBook(ContactBook* c, int size, int cap);
int main()
{
   ContactBook* cBArray;
   ifstream iFile;
   iFile.open("contactbooks.txt");
   int booksAmount = 0, capacity = 5;
   std::string line, line2, line3, line4, line5, oFN, oLN; 
   std::string cFirstName, cLastName, phone, email, menuLastName, 
   menuFirstName;
	
   std::string line6, line7, line8, line9, home, street, apt, city; 
   std::string menuOption, firstName, lastName, line10, state, zip;
   std::string mergeFN, mergeLN; 
   while(!iFile.eof())
   {
      iFile >> line;
      if(line == "endofbook|") booksAmount++;
   } 
   cBArray = new ContactBook[capacity];
   int cBSize = booksAmount - 1;
   iFile.close();
   iFile.open("contactbooks.txt"); 
   iFile >> line;
   for(int r = 0; r < cBSize; r++)
   {
      int breakPosition = line.find("|");
      oFN = line.substr(0, breakPosition);
      cBArray[r].setOwnerFN(oFN);
      oLN = line.substr(breakPosition + 1);
      cBArray[r].setOwnerLN(oLN);
      iFile >> line;
      int counter = 0;
      int contactSize = 0;
      while(line != "endofbook|" )
      {
         contactSize++;
	 cBArray[r].setSize(contactSize);
         breakPosition = line.find("|");
         cFirstName = line.substr(0, breakPosition);
	 cBArray[r].addFNInfo(cFirstName, counter);	
	
	 int startPosition = breakPosition + 1;
         line2 = line.substr(startPosition);
         breakPosition = line2.find("|");
         cLastName = line.substr(startPosition, breakPosition);
         cBArray[r].addLNInfo(cLastName, counter);

         startPosition = breakPosition + 1;
         line3 = line2.substr(startPosition);
	 breakPosition = line3.find("|");
	 phone = line2.substr(startPosition, breakPosition);
	 cBArray[r].addPhoneInfo(phone, counter);

         startPosition = breakPosition + 1;
	 line4 = line3.substr(startPosition);
	 breakPosition = line4.find("|");
         email = line3.substr(startPosition, breakPosition);
	 cBArray[r].addEmailInfo(email, counter);

	 startPosition = breakPosition + 1;
         line5 = line4.substr(startPosition);
	 breakPosition = line5.find("|");
	 home = line4.substr(startPosition, breakPosition);
	 cBArray[r].addHomeInfo(home, counter);
		   
	 startPosition = breakPosition + 1;
	 line6 = line5.substr(startPosition);
	 breakPosition = line6.find("|");
         street = line5.substr(startPosition, breakPosition);
         cBArray[r].addStreetInfo(street, counter);

	 startPosition = breakPosition + 1;
	 line7 = line6.substr(startPosition);
	 breakPosition = line7.find("|");
	 apt = line6.substr(startPosition, breakPosition);
	 cBArray[r].addAptInfo(apt, counter);

	 startPosition = breakPosition + 1;
	 line8 = line7.substr(startPosition);
	 breakPosition = line8.find("|");
         city = line7.substr(startPosition, breakPosition);
         cBArray[r].addCityInfo(city, counter);

	 startPosition = breakPosition + 1;
	 line9 = line8.substr(startPosition);
	 breakPosition = line9.find("|");
	 state = line8.substr(startPosition, breakPosition);
         cBArray[r].addStateInfo(state, counter);	

	 startPosition = breakPosition + 1;
	 line10 = line9.substr(startPosition);	
	 breakPosition = line10.find("|");
	 zip = line9.substr(startPosition, breakPosition);
         cBArray[r].addZipInfo(zip, counter);

	 iFile >> line;
         counter++;
      } 
      iFile >> line;
   }
   iFile.close();
	
   std::cout << "(Create New ContactBook(1))(Remove ContactBook(2))" 
	     << "(Display All ContactBooks(3))" << std::endl;
   std::cout << "(Merge ContactBooks(4))(Select ContactBook(5))" 
             << "(Exit(6))" << std::endl;
   std::getline(std::cin, menuOption);
	
   while(menuOption != "Exit" && menuOption != "6")
   {
      if(menuOption == "Create New ContactBook" || menuOption =="1")
      {
         cBSize = addContactBook(cBArray, cBSize);
	 std::cin.ignore(); 
      }
      else if(menuOption == "Remove ContactBook" || 
	      menuOption == "2")
      {
         cBSize = removeContactBook(cBArray, cBSize, capacity);
	 std::cin.ignore();
      }
      else if(menuOption == "Display All ContactBooks" || 
	      menuOption == "3")
      {
         displayBooks(cBArray, cBSize);
      }
      else if(menuOption == "Merge ContactBooks" || 
	      menuOption == "4")
      {
         std::cout << "Enter the first and last name of the"
		   << " contactbook you are merging into: " 
		   << std::endl;
	 std::cin >> menuFirstName >> menuLastName;
	 std::cout << "Now enter the first and last name of the"
		   << " contactbook you are merging: "
		   << std::endl;
	 std::cin >> mergeFN >> mergeLN;
	 int tempIndex, tempIndex2, tempCount = 0;
	 for(int m = 0; m < cBSize; m++)
         {
	    if(cBArray[m].getOwnerFN() == menuFirstName &&
	       cBArray[m].getOwnerLN() == menuLastName)
            {
	       tempIndex = m;
	       tempCount++;
	    }
	    if(cBArray[m].getOwnerFN() == mergeFN &&
	       cBArray[m].getOwnerLN() == mergeLN)
            {
	       tempIndex2 = m;
	       tempCount++;
	    }
         }
	 if(tempCount < 2)
         { 
	    std::cout << "No contactBook by that"
		      << " name found!" << std::endl;
	 }
	 else if(tempIndex == tempIndex2)
         {
	    std::cout << "Cannot Merge the same contactbook!"
		      << std::endl;
	 }
	 else
         {
	    cBArray[tempIndex].merge(cBArray[tempIndex2]);
	    if(tempIndex < tempIndex2)
            {
	       for(int m2 = tempIndex + 1; m2 < cBSize - 1; m2++)
               {
		  cBArray[m2] = cBArray[m2 + 1];
	       }
	    }
	    if(tempIndex > tempIndex2)
            {
	       for(int m3 = tempIndex2; m3 < cBSize - 1; m3++)
               {
		  cBArray[m3] = cBArray[m3 + 1];
	       }
	    }
	    cBSize--;
	 }
	 std::cin.ignore();
      }
      else if(menuOption == "Select ContactBook" || 
	      menuOption == "5")
      {
         std::cout <<"Enter first name and last name of contact book: "
		   << std::endl;
         std::cin >> menuFirstName >> menuLastName;
	 int index = bookIndex(cBArray, menuFirstName, 
			       menuLastName, cBSize);
	 if(index == -1)
         {
	    std::cout << "No Name Found!" << std::endl;
	    std::cin.ignore();
	 }
	 else
         {
	    std::cout << "Choose:(Add New Contact(1))"
		      <<"(Delete old Contact(2))"
                      << "(Search Contact Info(3))" << endl;
            std::cout << "        (Update Contact Info(4))"
                      << " (Display Entire Contact List(5)) (Exit(6))"
                      << endl;
	    std::cin.ignore();
            std::getline(std::cin, menuOption);
	    while(menuOption != "Exit" && menuOption != "6")
            {
               if(menuOption == "Add New Contact" || menuOption == "1")
               {
                  cBArray[index].addContact();
                  std::cin.ignore();
               }
               else if(menuOption == "Delete old Contact" || 
		       menuOption == "2")
               {
                  std::cout << "Please enter last name and first name"
                            << " of the contact you wish to delete: ";
                  std::cin >> lastName >> firstName;
                  cBArray[index].deleteContact(lastName, firstName);
                  std::cin.ignore();  
               }
               else if(menuOption == "Search Contact Info" || 
		       menuOption == "3")
               {
                  std::cout << "Please enter last name and first name"
                            << " of the contact you want to search: ";
                  std::cin >> lastName >> firstName;
		  cBArray[index].searchContact(lastName, firstName);
                  std::cin.ignore();
               }
               else if(menuOption == "Update Contact Info" || 
		       menuOption == "4")
               {
                  std::cout << "Please enter last name and first name"
                            << " of the contact you wish to update: ";
                  std::cin >> lastName >> firstName;
                  cBArray[index].updateContact(lastName, firstName);
                  std::cin.ignore();
               }
	       else if (menuOption == "Display Entire Contact List" || 
			menuOption == "5")
               {
                  cBArray[index].display();
               }
               std::cout << "Choose:(Add New Contact(1))"
			 <<"(Delete old Contact(2))"
                         << "(Search Contact Info(3))" << endl;
               std::cout << "        (Update Contact Info(4))" 
                         << "(Display Entire Contact List(5)) (Exit(6))"
                         << endl;
               std::getline(std::cin, menuOption);
            }
         }
      }
      std::cout << "(Create New ContactBook(1))" 
                << "(Remove ContactBook(2))" 
		<<"(Display All ContactBooks(3))" << std::endl;
      std::cout << "(Merge ContactBooks(4))(Select ContactBook(5))" 
		<<"(Exit(6))" << std::endl;
      std::getline(std::cin, menuOption);
   }
   ofstream oFile;
   oFile.open("contactbooks.txt");
   for (int p = 0; p < cBSize; p++)
   {
      oFile << cBArray[p].getOwnerFN() << "|" 
	    << cBArray[p].getOwnerLN() << std::endl;
      for(int q = 0; q < cBArray[p].getSize(); q++)
      {
         oFile << cBArray[p].getFNInfo(q) << "|"
	       << cBArray[p].getLNInfo(q) << "|"
	       << cBArray[p].getPhoneInfo(q) <<"|"
	       << cBArray[p].getEmailInfo(q) <<"|"
	       << cBArray[p].getHomeInfo(q) <<"|"
	       << cBArray[p].getStreetInfo(q) <<"|"
	       << cBArray[p].getAptInfo(q) <<"|"
	       << cBArray[p].getCityInfo(q) <<"|"
	       << cBArray[p].getStateInfo(q) <<"|"
	       << cBArray[p].getZipInfo(q)  << std::endl;
      }
      oFile << "endofbook|" << std::endl;
   }
   oFile.close();
   delete[] cBArray;
}

//displays all contact books
void displayBooks(ContactBook* c, int size)
{
   for(int i = 0; i < size; i++)
   {
      std::cout << "ContactBook# " << i + 1 << ":" << std::endl;
      std::cout << c[i].getOwnerFN() << " " <<
      c[i].getOwnerLN() << std::endl;
   }
}

//returns the index of a specific contact book
int bookIndex(ContactBook* c, std::string firstName, std::string 
              lastName, int size)
{
   int index = -1;
   for(int i = 0; i < size; i++)
   {  
      if(c[i].getOwnerFN() == firstName &&
         c[i].getOwnerLN() == lastName)
      {
         index = i;
      }
   }
   return index;
}

//adds another contact book
int addContactBook(ContactBook* c, int size)
{ 
   if(size == 5)
   {
      std::cout << "Maximum Size reached! You "
	        << "Cannot add another ContactBook!" << std::endl;
   }
   else
   { 
      size++;
      std::string fName, LName;
      std::cout << "Enter first and last name of the "
                << "owner of the new ContactBook: "
                << std::endl;
      std::cin >> fName >> LName;
      c[size - 1].setOwnerFN(fName);
      c[size - 1].setOwnerLN(LName);
   }
   return size;
}

//deletes a specified contact book
int removeContactBook(ContactBook* c, int size, int cap)
{
   int count = 0;
   std::string fName, LName;
   std::cout << "Enter the first name and last name of the owner"
	     << " of the ContactBook you wish to delete: " 
	     << std::endl;
   std::cin >> fName >> LName;
   for(int i = 0; i < cap; i++)
   {
      if((c[i].getOwnerFN() == fName) && 
	 (c[i].getOwnerLN() == LName))
      {
         count++;
	 for(int r = i; r < size - 1; r++)
         {
            c[r] = c[(r + 1)];
	 }
	 size--;
      }
   }
   if(count == 0) std::cout << "No ContactBook Found!" << std::endl;
      return size;
}
