using namespace std;
#include <iostream>
#include <vector>

// Must use the algorithm that is in the notes! 

//--------------------------------------------
//CS311 HW2P2 Combine 
//Name: Serenity Port
//Compiler: g++
//--------------------------------------------

// combine two sorted lists A and B into R
// displays comparison every time it is done
void combine( vector<int> A, vector<int> B, vector<int> &R )
{
 int  ia = 0;
 int  ib = 0;

 while (ia != A.size() && ib != B.size())
   { // main while loop for comparing elements in each list
     if (A[ia] < B[ib])
       {
	 R.push_back(A[ia]);
	 ia++;
       } // if element in vector A is less than element in vector B, add A at index ia to third empty vector
     else
       {
	 R.push_back(B[ib]);
	 ib++;
       } // else if element in vector B is less than element in vector A, add B at index ib to empty vector
     cout << "comparison" << endl;
   } // end of while
 if (ia !=  A.size())
       {
	 while (ia < A.size())
	   {
	     R.push_back(A[ia]);
	     ia++;
	   } // end of while
       } // while there are still items in vector A, add them to vector R
 else if (ib < B.size())
   {
     while (ib < B.size())
       {
	 R.push_back(B[ib]);
	 ib++;
       }//end of while
     // while there are still items in vector B, add them to vector R.
   }
}


int main()
{  
  vector<int> L1;
  vector<int> L2;
  vector<int> L3;
  int N;  // how many elements in each of L1 and L2
  int e;  // for each element

  cout << "How many elements in each list?" << endl;
  cin >> N;

  cout << "List1"  << endl;
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L1.push_back(e);} 

  cout << "List2"  << endl; 
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L2.push_back(e);} 
  

  // call combine here to combine L1 and L2 into L3
  combine(L1, L2, L3);
  
  cout << "The result is: ";
  for (int i = 0; i < N*2; i++)
    { cout << L3[i]; } cout << endl;

}// end of main
