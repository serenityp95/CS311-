// CS311 Yoshii - HW5 Priority Queue Implementation File
// Complete all ** parts and give good comments
// ** Do not delete my comments.

// =================================================
// HW5 Priority Printer Queue 
// YOUR NAME: Serenity Port
// File Type: implementation pqueue.cpp
// =================================================

#include "pqueue.h"

// constructor
pqueue::pqueue()
{  count = 0;  // no jobs yet
}

// destructor does nothing
pqueue::~pqueue() {}

// Purpose: to add a job to a right place in the Pqueue
// Argument: j is the job priority number
// Remember that the current last job is in slot count-1.
void pqueue::insertjob(int j)
{
  cout << "Adding: " << j << endl;
  if (count != MAX)
    {
      Q[count] = j;
      count++;
    }// ** add the job j at the rear (and update count)
  else
    {
      cout << "Error: Queue is full" << endl;
    }// **   if possible else display error message. 
  trickleup(); // moves the job to the right place
}

// Purpose: to print a job and reheapify the Pqueue
void pqueue::printjob()
{
  cout << "Printing: " << Q[0] <<endl;
  reheapify(); 
}

// Purpose: to display all jobs
void pqueue::displayAll()
{ 
  cout << "Jobs: ";
  for (int i = 0; i <= count - 1; i++)
    {
      cout << Q[i] << " ";
    }
  cout << endl;// ** loop to display jobs from slot 0 to slot count-1 horizontally. No need to show a tree format.
} 


// Utility functions follow: ------------------

void pqueue::swap(int loc1, int loc2)
{
  int temp = Q[loc1];
  Q[loc1] = Q[loc2];
  Q[loc2] = temp;// ** swap the values in these locations in Q
}

// Purpose: to make the very last job trickle up to the right location. Never do X--. 
void pqueue::trickleup()
{ 
  int x = count-1;// the very last job's location
  int P; // Parent
  while (x > 0)// ** While x is > 0   
    {
      P = getParent(x); // (*) call getParent to get the location of the parent                       // based on the child's location

      if (Q[x] < Q[P])//    compare Q[x] with the parent (*)
	{
	  swap(x, P);//    and if the parent is bigger swap & update x 
	  x = P;//    to be the parent . Otherwise stop the loop.
	}
      else 
	{
	  return;
	}
    } // end of while
}

// Purpose: find the location of the parent 
// The child location is given.  Need to call even.
int pqueue::getParent(int childloc)
{ 
  int parent; // holds position of parent
  
  if (even(childloc)) // check if child is even or not
    {
      parent = (childloc - 2) / 2; // if child is even, then it is the right ch                                     ild
    }
  else
    {
      parent = (childloc - 1) / 2; // else child is odd meaning it's the left c                                      hild
    }

  return parent;// ** return the parent location based on the child loc
}

// Purpose: is location i even? Important in finding its parent location
bool pqueue::even(int i)
{
  if ((i % 2) ==  0) return true; else return false; }

// Purpose: to reheapify the Pqueue after printing
//  This trickles down.  Never do X++.
void pqueue::reheapify()
{ int X;   // the current location
  Q[0] = Q[count-1];  // move the last job to the front
  count--;
  X = 0;// ** Start X at 0 (the root)
  while (X < count - 1) //    while X is within the array:
    {
      int smaller = getSmallerchild(X);//       Find the location of the smaller child
      
	if ((X > count - 1) || (smaller > count - 1))
	  {
	    return;
	  }// (if the location of both children are off the tree, stop the loop).
	else if (Q[X] > Q[smaller])// If the smaller child is smaller than the parent,
	  {
	    swap(X, smaller);
	    X = smaller;
	  } // swap and X becomes the smaller child's location.
        else
	  {
	    return;
	  }
    }//else no swaps so stop to loop.
}

// Purpose: to find the location of the smaller child
// where children are at locations 2*i+1 and 2*i+2
int pqueue::getSmallerchild(int i)
{
// ** return the location of the smaller child 
//    Be careful because one or both of them may be
//    beyond count-1.  Check boundaries before you 
//    compare Q contents!!!!
  int left, right, smaller;

  left = (2 * i) + 1; // find the left child
  right = (2 * i) + 2; // find the right child

  if (left <= count - 1 && right <= count - 1) // if they're both in bounds
    {
      if (Q[left] > Q[right]) // if left child is bigger than right child
	{
	  smaller = right;  // smaller child is the right
	} 
      else
	{
	  smaller = left; // else smaller child is the left
	}
     }
  else if (left <= count - 1 && right > count - 1)
    {
      smaller = left; // if only the left child exists
    }
  else
    {
      smaller = i; // they're both out of bounds
    }
  
  return smaller; // return smaller child 
}


