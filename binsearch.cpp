using namespace std;
#include <iostream>
#include <math.h>

//--------------------------------------------
// CS311 HW2P1 Binary Search
// Name: Serenity Port
// Compiler: g++
// --------------------------------------------

// x is what we are looking for in L; first and last are slot numbers 
//This returns the slot number in which x was found
//or -1
int binarySearch(int L[], int x, int first, int last) 
{
  int middle = floor((first + last) / 2); // find the middle index by adding the first and last index, dividing by 2 and rounding down.
  
  cout << "comparing against an element in slot " << middle << endl; // display where program is searching for the element in the middle index

  if (x == L[middle]) // found x at location middle so return the location
    {
      return middle;
    }
  else if (first == last) // if first == last, there is only one element left
    {
      return -1;
    }
  else if (x < L[middle]) // go to first half of array if x is smaller than element at the middle
    {
      last = middle - 1;
    }
  else if (x > L[middle]) // got to second half of array if x is larger than element at the middle
    {
      first = middle + 1;
    }

  return binarySearch(L, x, first, last); // recursive call
}


int main()
{ int A[10];
  int e;  // to look for this

  // fixed elements for A
  A[0] = 1; A[1]= 3; A[2]=5; A[3]= 7; A[4]=9; A[5]=11; A[6]=13;
  A[7] =15; A[8]= 17; A[9]= 19;

  cout << "What do you want to look for? ";
  cin >> e;

  // Call binarySearch here to look for e in A
  int respos = binarySearch(A, e, 0, 9);

  if (respos == -1) cout << "Element not found" << endl; 
  else cout << "Found it in position " << respos+1 << endl;

}
