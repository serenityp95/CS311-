// CS311 Yoshii Complete all functions with their comments

// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Serenity Port
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 


// do not change this one
slist::slist()
{}; // constructor


//PURPOSE: Search through the list to see if any node contains key. If so, return its position (>=1). Otherwise, return 0.
//PARAMETER: Key to search for
int slist::search(el_t key)
{
  Node *P = Front; // sets pointer to front node
  int position = 1; // position in list
  
  // traverses the whole list until P falls off list
  while (P != NULL)
    {
      if (P->Elem == key) // If the element P points to is equal to the key
	{
	  return position; // return position it was found in
	}
      P = P->Next; // Moves P to next node
      position++; // increases position
    } // end of while

  return 0; // if key was not found, return 0
}

//PURPOSE: Search through the list to see if any node contains key. If so, return the found element. Otherwise, return a blank object.
//PARAMETERS: key to search for
el_t slist::search2(el_t key)
{
  Node *P = Front; // pointer points to front node
  el_t blank; // blank object

  //traverses the whole list until P falls off the list
  while (P != NULL)
    {
      if (P->Elem == key)//if the element matches the key
	{
	  return P->Elem; // return the element
	}
      P = P->Next; // moves pointer to next node
    }

  return blank; // if key was not found, return blank object
}


//PURPOSE: Go to the pos node (pos is between 1 and Count) and replace the element there with element. If pos was an illegal value, throw an exception (OutOfRange)
//PARAMETERS: element to replace with, pos for position of node in linked list to replace element. 
void slist::replace(el_t element, int pos)
{
  Node *P = Front; // pointer points to front node
  
  if (pos > Count || pos < 1)
    {
      throw OutOfRange();
    } // if pos is illegal, throw exception

  moveTo(pos, P); // moves pointer to position of node  
  P->Elem = element; // sets that pointers element to element given
}

//PURPOSE: Compare two slist objects to see if they look the same
//         If this->Count and OtherOne.Count are not the same, false
//         Else go through the lists Count times comparing ->Elem's, and as soo           n as they are different, return false
//         If the loop completes, return true.
//PARAMETERS: Other slist object to compare to
bool slist::operator==(const slist& OtherOne)
{
  // if not the same length, return false
  if (this->Count != OtherOne.Count)
    {
      return false;
    } 
  else
    {
      Node *P = OtherOne.Front; // pointer points to other lists front
      Node *Q = Front; // pointer points to Front
      
      //Loop to go through lists Count times
      for (int i = 0; i < Count; i++)
	{
	  if (P->Elem != Q->Elem)
	    {
	      return false; // if elements don't match up, return false
	    }
	  
	  P = P->Next; // moves pointer to next node in list
	  Q = Q->Next; // moves pointer to next node in list
	} // end of loop

      return true; // if loop completes, objects are the same, return true 
    }
}
