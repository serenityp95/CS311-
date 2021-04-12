//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program (Use control-S)
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack application (post-fix evaluation)
//Your name: Serenity Port
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: Implementing a stack to read in postfix expressions;
//                        evaluating them
//Algorithm: The user will enter a post-fix expression of the form:
//           34+
//           345+*
//           722+- as a string. Operators are +, =, and *. Single digit numbers
//           only. No blanks. No expression will be longer than 12 characters.
//           Since each element of the string is a character, character needs 
//           to be converted to an integer to perform arithmetic operations.
//           Program will display evaluated result (a number) and/or an error
//           message describing what is wrong.
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  int temp;  // temporarily holds value of digit to push onto stack
  
  while (expression[i] != '\0')
    {
     try
       {
	 item = expression[i];  // current char
	 
	 if (item >= '0' && item <= '9')
	   {
	     temp = (int)(item)-48; // changes item char to integer
	     postfixstack.push(temp);
	     postfixstack.displayAll();
	   }// pushes item onto stack if it is number
	 else if (item == '+') // evaluates addition
	   {
	     postfixstack.pop(box1); // pops top element in stack
	     postfixstack.pop(box2); // pops second top element in stack
	     postfixstack.push(box1 + box2); // adds them and pushes onto stack
	     postfixstack.displayAll(); // display stack
	   }
	 else if (item == '-') // evaluates subtraction
	   {
	     postfixstack.pop(box1);
	     postfixstack.pop(box2);
	     postfixstack.push(box2 - box1);
	     postfixstack.displayAll();
	   }
	 else if (item == '*') // evaluates multiplication
	   {
	     postfixstack.pop(box1);
	     postfixstack.pop(box2);
	     postfixstack.push(box1 * box2);
	     postfixstack.displayAll();
	   }
	 else // invalid argument, exception thrown
	   {
	     throw "Error"; 
	   }
	   
	 
       } // this closes try
      // Catch exceptions and report problems and quit the program now (exit(1)). 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{
	  cout << "Too many operands/operators: Overflow" << endl;  exit(1);
	}
      catch (stack::Underflow)
	{
	  cout << "Too few operands/operators: Underflow" << endl; exit(1);
	}
      catch (char const* errormsg ) // for invalid item case
	{
	  cerr << "Invalid item " << errormsg << endl; exit(1);
        }

      // go back to the loop after incrementing i
     i++;
    }// end of while
  
 // After the loop successfully completes: 
 // Pop the result and show it.
  postfixstack.pop(i);
  cout << "Result: " << i << endl;
 // If anything is left on the stack, an incomplete expression 
 // was found so inform the user.
  if (!postfixstack.isEmpty())
    {
      cout << "Incomplete expression." << endl ;
    }

}// end of the program
