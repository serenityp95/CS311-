//CS311 Yoshii Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes

//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  cntr-K cuts and cntr-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Serenity Port
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist() // constructor: does not create any node and list is empty
{ 
  Front = NULL;
  Rear = NULL;
  Count = 0;
}

llist::~llist() // destructor: deletes all nodes in list
{
  el_t temp;
  while(Count != 0) // while list is not empty 
    {
      deleteFront(temp); // repearedly call deleteFront to delete all nodes
    }
}

//PURPOSE: return true if Front and Rear are both pointing to NULL and Count is  0 
//PARAMETER: none
bool llist::isEmpty() 
{
  if (Front == NULL && Rear == NULL && Count == 0)
    {
      return true;
    }
  else
    {
      return false;
    }
}

//PURPOSE: display each element of the list starting from Front, enclosed in []  followed by endl
//PARAMETER: none
void llist::displayAll(ostream& fout) 
{
  if (isEmpty())// special case: if the list is empty, display [ empty ]
    {
      cout << "[ empty ]" << endl;
    }
  else // regular case: display each element of the list starting from front
    {
      cout << "[ ";
      Node *P = Front; // local pointer points to Front
      while (P != NULL) // loop repeats until end of list
	{
	  fout << P->Elem << ", "; //displays P's element
	  P = P->Next; // Go to the next node
	}
      cout << "]" << endl;
    }
}
  
//PURPOSE: adds a new node at the rear and puts NewNum in the Elem field
//PARAMETER: new element to add to the elem field
void llist::addRear(el_t NewNum) 
{
  if (isEmpty()) // special case: if it's the first node, create a new node and make Front and Rear point to it.
    {
      Front = new Node; // new Front node
      Front->Elem = NewNum; // Front elem points to NewNum
      Rear = Front; // Rear points to new node
      Rear->Next = NULL; // Rear->Next points to NULL
      Count++; // Count is updated
    }
  else // regular case: add new node at the rear, put NewNum in the Elem field
    {
      Rear->Next = new Node; // new Rear node
      Rear = Rear->Next; // Rear points to new node
      Rear->Elem = NewNum; // Rear element points to NewNum
      Rear->Next = NULL; // Rear->Next points to NULL
      Count++; // Count is updated
    }
}

//PURPOSE: adds a new node at the front and puts NewNum in the Elem field
//PARAMETER: Element to put in the elem field
void llist::addFront(el_t NewNum) 
{
  if (isEmpty())// special case: if this is first node of the list, create a new node and make Front and Rear point to it. 
    {
      Front = new Node; // New Node
      Front->Elem = NewNum; // Front element points to NewNum
      Rear = Front; // Rear points to new Front node
      Rear->Next = NULL; // Rear->Next points to NULL
      Count++; // Count is updated
    }
  else // regular case: add a new node at the front and put NewNum in the elem field
    {
      Node *P = new Node; // new Node
      P->Elem = NewNum; // the node's elem field points to NewNum
      P->Next = Front; // node's next points to front
      Front = P; // Front points to new node
      Count++; // Count is updated
    } 
}

//PURPOSE: gives back the front node element through OldNum (pass by reference)  and also removes the front node, throws an exception if list is empty
//PARAMETER: Element to give back front element through
void llist::deleteFront(el_t& OldNum) 
{
  if (isEmpty()) // error case: if list is empty, throw exception
    {
      throw Underflow();
    }
  else if (Count == 1) // special case: if this is going to make list empty, give back the OldNum and remove the Front node.
    {
      OldNum = Front->Elem; // OldNum gets what Front->Elem points to
      delete Front; // delete front node
      Front = NULL; // Front points to NULL
      Rear = NULL; // Rear points to NULL
      Count--; //Count is updated
    }
  else // regular case: give back the front node element through OldNum and remove the front node
    {
      OldNum = Front->Elem; // OldNum gets Front->Elem
      Node *Second = Front->Next; // New second node points to Front->Next
      delete Front; // delete front node
      Front = Second; // Front points to second node
      Count--; // Count is updated
    }
}

//PURPOSE: gives back the rear node element through OldNum (pass by reference)   and also removes the rear node. If list is empty, throw exception
//PARAMETER: OldNum to hold element at rear, and give it back
void llist::deleteRear(el_t& OldNum)
{
  if (isEmpty()) // error case: if list is empty, throw an exception
    {
      throw Underflow();
    }
  else if (Count == 1) // special case: if this is going to make the list empty give back the rear node element through OldNum and remove the rear node
    {
      OldNum = Rear->Elem; // OldNum gets element at rear
      delete Rear; // delete rear node
      Front = NULL; // Front points to NULL
      Rear = NULL; // Rear points to NULL
      Count--; // Count is updated
    }
  else // regular case: give back the rear node through OldNum and remove the rear node
    {
      OldNum = Rear->Elem; // OldNum gets element at rear
      Node *P = Front; // New node that points to Front
      while (P->Next != Rear) // while loop to reach element before rear
	{
	  P = P->Next; // Moves P pointer through list
	}
      delete Rear; // deletes Rear node
      Rear = P; // Rear points to node before rear
      Rear->Next = NULL; // Rear->Next points to NULL
      Count--; // Count is updated
    } 
}


/* harder ones follow */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times to go to the Jth node
  for ( int K = 1; K <= J - 1; K++)
    {
      temp = temp->Next;
    }
}

//PURPOSE: will delete the Ith node
//PARAMETER: int i to know which node to delete, element to give back element in deleted node.
void llist::deleteIth(int I, el_t& OldNum) 
{
  if (I > Count || I < 1) // error case: if I is an illegal value (i.e. > Count or < 1) throw an exception
    {
      throw OutOfRange();
    }
  else if (I == 1) // special case: if I equals 1, that means it's the first node so call deleteFront
    {
      deleteFront(OldNum);
    }
  else if (I == Count) // special case: if I equals Count, that means it's the last node so call deleteRear
    {
      deleteRear(OldNum);
    }
  else // regular case: will delete the Ith node (I starts out at 1)
    {
      Node *P = Front; // New node that points to Front
      Node *Q = Front; // New node that points to Front
      moveTo(I-1, P); // Moves P to point to node right before I
      moveTo(I+1, Q); // Moves Q to points to node right after I to bypass I
      OldNum = P->Next->Elem; // OldNum is the old element in deleted node
      delete P->Next; // delete bypassed node
      P->Next = Q; // P->Next now points to Q, node right after bypassed I
      Count--; // Count is updated
    }      
}  

//PURPOSE: will add the Ith node
//PARAMETER: int I to know which node to add, and newNum to know what to insert in element field.
void llist::insertIth(int I, el_t newNum) 
{
  if (I > Count + 1 || I < 1) // error case: if I is an illegal value (i.e. > Count or < 1) throw an exception
    {
      throw OutOfRange();
    }
  else if (I == 1) // special case: if I equals 1, then it's first node and simply call addFront
    {
      addFront(newNum);
    }
  else if (I == Count + 1) // special case: if I equals Count + 1, then it's the last node, and simply call addRear
    {
      addRear(newNum);
    }
  else // regular case: will add right before the Ith node
    {
      Node *P = Front; // new node points to Front
      Node *Q = Front; // new node points to Front
      Node *temp = new Node; // creates a new node to add
      moveTo(I-1, P); // moves P to node right before I
      moveTo(I, Q); // moves Q to Ith node
      P->Next = temp; // node right before Ith node's next points to new node
      temp->Elem = newNum; // new nodes element field gets newNum
      temp->Next = Q; // new node now points to Q, which is Ith node
      Count++; // Count is updated
    } 
}

//PURPOSE: copy constructor for pass by value and return by value
//PARAMETER: original linked list to copy
llist::llist(const llist& Original) 
{
  //Note that the Original is being passed to the constructor by reference to create a new object this-> as a copy of the Original
  Front = NULL; Rear = NULL; Count = 0; // this->'s data members need to be initialized here first
  // this-> object has to be built up by allocating new cells and copying the values from Original into each cell as we did with operator=.
  Node *P;  // local pointer for Original
  P = Original.Front;
  while (P != NULL) // a loop which repeats until you reach the end of Original
    {
      this->addRear(P->Elem); //P's element is added to this->
      P = P->Next; // Go to the next node in Original
    }
  // Nothing to return because this is a constructor
}

//PURPOSE: allows the client to use = for linked list objects
//PARAMETER: other linked list to compare
llist& llist::operator=(const llist& OtherOne) 
{
  el_t x;
 
  //First make sure this-> and OtherOne are not the same object. To do this, compare the pointers to the objects
  if(&OtherOne != this) // if not the same
    {
      // this-> object has to be emptied first
      while(!this->isEmpty())
	{
	  this->deleteRear(x);
	} 
      // this-> object has be built up by allocating new cells with OtherOne
      Node *P; // local pointer for OtherOne
      P = OtherOne.Front; 
      while(P != NULL) // a loop with repeats until you reach the end of OtherOne
	{
	  this->addRear(P->Elem); // P's element is added to this->
	  P = P->Next; // Go to the next node in OtherOne
	}
    } // end of if
  return *this; // return the result unconditionally. Note that the result is returned by reference
} 

