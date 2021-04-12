//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Serenity Port
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
typedef int el_t;

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //PURPOSE: return true if Front and Read are both pointing to NULL and count   is 0
  //PARAMETERS: none
  bool isEmpty();
    
  //PURPOSE: display each element of the list starting from Front, enclosed in   [] followed by endl
  //PARAMETERS: none
  void displayAll();

  //PURPOSE: add new node at the front and puts element in the elem field
  //PARAMETERS: element to add to new node at front
  void addFront(el_t);
    
  //PURPOSE: add new node at the rear and puts element in the elem field
  //PARAMETERS: element to add to new node at rear
  void addRear(el_t);

  //PURPOSE: deletes node at front, if list is empty, throws an exception
  //PARAMETERS: element to give back front node element through
  void deleteFront(el_t&);
    
  //PURPOSE: deletes node at rear, if list is empty, throws an exception
  //PARAMETERS: element to give back rear element through
  void deleteRear(el_t&);
    
  //PURPOSE: deletes Ith element in list
  //PARAMETERS: int to find the Ith node, and element to give back
  void deleteIth(int, el_t&);  // calls moveTo

  //PURPOSE: inserts Ith element in list
  //PARAMETERS: int to find the Ith node, and element to give back
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
