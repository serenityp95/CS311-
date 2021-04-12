//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Serenity Port
// File type: client hw7client.cpp 
//==========================================

// ** Be sure to include dgraph, slist and stack
#include <iostream>
#include "dgraph.h"
#include "stack.h"
using namespace std;

// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{
  // ** copy here the algorithm (read carefully) in the HW7
  // assignment sheet and use that has the comments. 
  char vertex;
  int visitNumber = 1;
  dgraph graph;
  stack vertices;
  slist adjacents;

  graph.fillTable(); // fills the table with values from table.txt 
  graph.displayGraph(); // displays graph before DFS
  
  vertices.push('A'); // push A onto stack to start
  
  while(!vertices.isEmpty()) // while the stack is not empty
    {
      vertices.pop(vertex); // remove a vertex from the stack
      cout << "Removed " << vertex << " from stack" << endl; // display vertex name
      
      if (!graph.isMarked(vertex)) // if vertex is not marked yet (visit number is 0)
	{ 
	  graph.visit(visitNumber, vertex); // visit it and inform the user
	  cout << "Visit " << vertex << " as " << visitNumber << endl;
	  visitNumber++; // increase visit number
	  adjacents = graph.findAdjacency(vertex); //grab adjacency list

	  if (adjacents.isEmpty()) // if adjacency list is empty (there's no adjacents) inform the user
	    {
	      cout << "Deadend reached - backup" << endl;
	    }
	  else
	    {
	      while (!adjacents.isEmpty()) // while adjacency list isn't empty
		{
		  //put adjacent ones on the stack (delete from rear and push) informing the user
		  adjacents.deleteRear(vertex); 
		  vertices.push(vertex);
		  cout << "Pushing " << vertex << " onto stack" << endl;
		}
	    }
	}
      else 
	{
	  // inform the user vertex has been visited already
	  cout << vertex << " has been visited already - backup" << endl;
	}
      // display the stack
      vertices.displayAll(); 
    } // end while

  // display the graph with updated visit numbers
  graph.displayGraph();
}
