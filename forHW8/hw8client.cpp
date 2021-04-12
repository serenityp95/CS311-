// CS311 Yoshii - complete ** for HW8 client
// Note that the client knows about elem.h functions.
// It can create el_t objects.
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: Serenity Port
// File type: client hw8client.cpp (tester)
//===========================================

using namespace std;
#include "htable.h"

// This tester gets input data interactively but
// for a useful client, input should come from a file.
// Note that el_t X; will create a blank element X using the regular constructor.  
// Note that the second constructor of el_t can be used to
// create key+name to add to the table. e.g. el_t X(30, "mary");
int main()
{
  htable table; // hash table
  el_t blank; // blank element object
  int key; // to hold the key
  string name; // to hold the name

  //Loop:  
  // Interactively add about 20 keys and names to the table,
  // making sure some of them  collide. (function add)
  // You can create el_t containing a key and name using a constructor.
  for (int i = 0; i < 20; i++)
    {
      cout << "Enter Key: ";
      cin >> key; //have user enter key
      cout << "Enter Name: ";
      cin >> name; //have user enter name

      el_t element(key, name); //create new element containing a key and name using constructor
      table.add(element); //add element to hash table
    }

  //DisplayTable.
  table.displayTable();

  // Loop:
  //Interactively look up names using keys. (function find)
  //Cout the key + name if found else (blank element was returned i.e. key part is -1)
  //an error message.
  while (key != -1)
    {
      cout << "Look for? (-1 to quit) " << endl;
      cin >> key; //user types in key their looking for

      el_t found = table.find(key); //finds key, blank object if key was not found
      
      if (key != -1) //if user doesn't want to quit
	{
	  if(found == blank) // if found is a blank object
	    {
	      cout << "Error: Element Not Found" << endl;
	    }
	  else //if key was found
	    {
	      cout << "Found: " << found << endl;
	    }
	}
    }
}
