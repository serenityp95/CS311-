// CS311 Yoshii
// HW6 Client file 
//INSTRUCTION: Complete this file and comment using How to Comment file.
//---------------------------------------------

// ================================================
// HW#: HW6 dgraph client 
// Name: Serenity Port
// File type: Client file  (tester)
// ================================================

#include "dgraph.h"
using namespace std;

int main()
{ 
  // 0.Declare table object
  dgraph G;
  char vertex = ' '; // declare char to hold vertex user specifies

  // 1.fillTable()
  G.fillTable();

  // 2.displayGraph()
  G.displayGraph();

  // while (the user does not want to stop)
  while (vertex != '0')
    {
      try // try-catch block
	{
	  cout << "Specify vertex or enter 0 to quit: "; // prompts user to enter vertex name or quit 
	  cin >> vertex; //a.the user will specify which vertex     
	  cout << "Degree: " << G.findOutDegree(vertex) << endl;//b.findOutDegree of the vertex and display the result
	  cout << "Adjacency: " << endl; //b.findAdjacency of the vertex and display the result (see Hint)
	  (G.findAdjacency(vertex)).displayAll(); // use slist function to display all adjacents
	}
      catch (dgraph::BadVertex)
	{
	  cout << "Error: Bad Vertex" << endl;
	}// c.catch exception to display error mesg but do not exit
    }
}

/*
Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.

*/
