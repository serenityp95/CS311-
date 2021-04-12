//CS311 Yoshii dgraph.cpp 
// INSTRUCTION:
//  Complete all the functions you listed in dgraph.h
//  Comment the file completely using How to Comment file.
//  Use HW6-help.docx to finish the functions.
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: Serenity Port
// File Type: Implementation file for dgraph
//========================================================

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"

dgraph::dgraph() // initialize vertexName (blank) and visit numbers (0)    // initialize countUsed to be 0
{
  for (int i = 0; i < SIZE; i++)
    {
      Gtable[i].vertexName = ' '; // initalize vertexName (blank)
      Gtable[i].visit = 0; // initialize visit number (0)
    }

  countUsed = 0;
}

dgraph::~dgraph()   // we don't have to delete all nodes in table. llist destructor will be called automatically.
{
}

void dgraph::fillTable()  // be sure to read from a specified file
{
  string fname;
  cout << "Enter a file name: ";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in); // declare and open fname
  
  char X;

  while (fin >> Gtable[countUsed].vertexName) // while I can read the name in
    {
      fin >> Gtable[countUsed].outDegree;
      
      for (int i = 0; i < Gtable[countUsed].outDegree; i++) //for outDegree times
	{
	  fin >> X; // read in each vertex name
	  
	  (Gtable[countUsed].adjacentOnes).addRear(X); // this calls the slist function
	}
      countUsed++;
	   	
    }
    fin.close(); // closes file
}

void dgraph::displayGraph() // be sure to display
{// in a really nice table format -- all columns but no unused rows and include the number of edges at the top
  cout << "The number of edges is: " << countUsed << endl; // number of edges
  cout << "Vertex  Out  Visit  Adj" <<endl; // column names
  for (int i = 0; i < countUsed; i++)
    {
      cout << Gtable[i].vertexName << "       "; // prints out vertex name
      cout << Gtable[i].outDegree << "    "; // prints out degree on same line
      cout << Gtable[i].visit << "     "; // prints out visit number
      (Gtable[i].adjacentOnes).displayAll(); // calls slist function to display all the adjacent ones
    }
}

int dgraph::findOutDegree(char V)// throws exception
{// does not use a loop
  int vertex = (int) V - 65; // changes char to an int
  
  if (Gtable[vertex].vertexName == V) // if vertex name is found
    {
      return Gtable[vertex].outDegree; // return degree of that vertex
    }
  
  throw BadVertex(); // throw exception if vertex was not found, meaning it's a bad vertex
}

slist dgraph::findAdjacency(char V)// throws exception
{// does not use a loop
  int vertex = (int) V - 65; // changes char to an int
  
  if (Gtable[vertex].vertexName == V) // if vertex name is found
    { 
      return Gtable[vertex].adjacentOnes; // return slist of vertices adjacent to vertex
    }
  
  throw BadVertex(); // throw exception if vertex was not found, meaning it's a bad vertex
}

//PURPOSE: Will enter the given visit number for a given vertex
//PARAMETERS: The given visit number (int), and the given vertex (char)
void dgraph::visit (int visitNumber, char visitName)
{
  int vertex = int(visitName) - 65;
  Gtable[vertex].visit = visitNumber;
}

//PURPOSE: Returns true if a given vertex was already visited
//PARAMETERS: Name of vertex to check if it's been marked (char)
bool dgraph::isMarked(char vertexName)
{
  int checkVertex = int(vertexName) - 65;

  if (Gtable[checkVertex].visit == 0)
    {
      return false;
    }
  else
    {
      return true;
    }
}
