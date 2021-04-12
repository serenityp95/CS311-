//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 

//=========================================================
//HW#: HW1P2 queue application (generate all strings)
//Your name: Serenity Port
//Complier:  g++ compiler
//File type: client program client2.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: To write a program that generates all strings using
//                        A, B, and C as the letters
//Algorithm: We can start with "A", "B" and "C" in the queue/
//           Loop - Do the following repeatedly:
//                   1. Remove a string and display it
//                   2. Add the string + "A"
//                   3. Add the string + "B"
//                   4. Add the string + "C"
int main()
{ // "A", "B", "C" in the queue
  queue stringqueue; // string queue
  stringqueue.add("A"); // add "A" to queue
  stringqueue.add("B"); // add "B" to queue
  stringqueue.add("C"); // add "C" to queue

  string abc; // string to hold removed element, and to concatenate with letter

  // while loop -- indefinitely
  while (true)
    {
      try
	{ 
	  stringqueue.remove(abc); // remove element from the front
	  cout << abc  << endl; // display it
	  stringqueue.add(abc + "A"); // add to removed element "A"
	  stringqueue.add(abc + "B"); // add to removed element "B"
	  stringqueue.add(abc + "C"); // add to removed element "C"
	}
      catch (queue::Underflow) // catches exception for Underflow
	{
	  cout << "Cannot remove" << endl; exit(1);
	}
      catch (queue::Overflow) // catches exception for Overflow
	{
	  cout << "Cannot add" << endl; exit(1);
	}
    }// end of loop

}

