//INSTRUCTION:
//Look for ** using control-S
//Then, fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P2 queue
//Your name: Serenity Port
//Complier:  g++ compiler
//File type: Implementation file for queue.h  queue.cpp
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue()
{  
  // initialize data members
  count = 0; // how many elements are in the queue?
  front = 0; // where the front element of the queue is
  rear = -1; // where the rear element of the queue is
}

//destructor 
queue::~queue()
{ // nothing
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  if (count == 0)
    return true;
  else
    return false;
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
  if (count == MAX_SIZE)
    return true;
  else
    return false;
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
  if (isFull())
    throw Overflow();
  else
    {
      rear = (rear + 1) % MAX_SIZE; // move rear
      el[rear] = newElem; // add element at rear
      count++; // increase number of elements in queue
    }
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
  if (isEmpty())
    throw Underflow();
  else
    {
      removedElem = el[front]; // element at the front is placed into holder
      front = (front + 1) % MAX_SIZE; // move front up by 1
      count--; // decrease number of elements in the queue
    }
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
  if (isEmpty())
    throw Underflow();
  else
    {
      theElem = el[front];
    }
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
  return count;
}

// PURPOSE: display everything in the queue horizontally
// from front to rear enclosed in [   ]
// if empty, displays [ empty ]
void queue::displayAll()
{  if (isEmpty())
    {
      cout << "[ empty ]" << endl;
    }
  else
    {
      int j = front; // local variable to hold front element
      cout << "[";
      for (int i = 1; i <= count; i++)
	{
	  cout << el[j] << " "; // display element at front
	  j = (j + 1) % MAX_SIZE; // increment front and make sure it
	                          // loops around
	}
      cout << "]" << endl;   
    }  
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//calling remove followed by add.
void queue::goToBack()
{
  if (isEmpty())
    throw Underflow();
  else if (count == 1)
    { // nothing
    }
  else
    {
      string temp = el[front]; // string to hold the element at the front
      remove(el[front]); // remove element from front
      add(temp); // place it at the rear of the queue
    }
}

