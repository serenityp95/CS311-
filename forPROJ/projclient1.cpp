// Project Client using a generic hash table
// Loading the data file has to happen here because
// generic htable should not know about the file
// format.
// Change everywhere it says **
// Must write / change @@ functions in htable.
// Must improve the user interface!

#include "htable.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// An easy lookup of songs to practice on guitar. Gives useful information like the year the song came out, the name of the song, the artist name, the key in which it should be played, and the difficulty of the song. 

int main()
{
  htable T;  // generic hash table

  // All declarations happen outside switch
  int year; // release year
  string name; // song name
  string artist; // artist
  string key; // key to play in
  string difficulty; // difficulty of song
  string blank; // empty string
  el_t E;     // blank element

  // File info declared outside switch
  string fname;
  cout << "What is the input file?";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in);
  ofstream fout ("newout", ios::out);


  int ans = 0;
  while (ans != 7)
    {
      // *** change menu items to be descriptive
      cout << "MENU------------------ :"<<endl;
      cout << "1. Load data from a file" << endl;
      cout << "2. Display the table" << endl;
      cout << "3. Search using year" << endl;
      cout << "4. Add a new song" << endl;
      cout << "5. Delete a song" << endl;
      cout << "6. Save data to a file" << endl;
      cout << "7. Exit" << endl;
      cout << "==>";
      cin >> ans;

      switch (ans)
	{

	case 1: // ** change element parts to yours
	  while (fin.good()) // while the end of file isn't reached
	    {
	      if (getline(fin, name, ',')) // get up to first comma which is the name
		{ 
		  if (getline(fin, artist, ',')) // get up to second comma which should be the artist
		    {
		      if (getline(fin, key, ',')) // get up to the third comma which should be the key
			{
			  if (getline(fin, difficulty, ',')) // get up to the fourth comma which should be the difficulty
			    {
			      if (fin >> year) // get the year
				{
				  T.add(el_t(name, artist, key, difficulty, year)); // use all element parts to create new element in table
				}
			    }
			}
		    }
		}
	    } 
	  cout << "loaded data..." << endl;
	  break;

	case 2:
	  T.displayTable(cout); //@@
          break;

	case 3: // ** change key to yours
	  cout << "Enter year to look for: ";
	  cin >> year; // year to search for
	  E = T.find(year);
	  if (E == el_t()) /// blank
	    cout << "Not found" << endl;
          else cout << "Found " << E << endl;
	  break;

	case 4: // ** change element parts to yours
          cout << "Enter a name: "; getline(cin, name, ','); // get up to the comma which should be the name
	  cout << "Enter an artist: "; getline(cin, artist, ','); // get up to the comma which should be the artist
	  cout << "Enter a key: "; cin >> key; // get the key
	  cout << "Enter a Difficulty: "; cin >> difficulty; // get the difficulty
	  cout << "Enter a release year: "; cin >> year; // get the year
	  cout << "In Slot: " << T.add(el_t(name, artist, key, difficulty, year)); // use element parts to add new element to table
          cout << " added." << endl;
	  break;
       
	case 5: // ** change key to yours
          try // try block to try deleting element
	    {
	      cout << "Enter a year: "; cin >> year;
	      cout << "In Slot: " << T.deleteIt(el_t("", "", "", "", year)); //@@
	      cout << " deleted." << endl;
	    } 
	  catch (llist::OutOfRange) // catches if element is not found/out of range
	    {
	      cout << "Not Found" << endl;
	    }
          // ** what happens if the item was not found?
	  break;
        
	case 6:
	  T.displayTable(fout);
	  cout << "Sent data to newout" << endl;
	  cout << "Remember to rename newout to input file" << endl;
	  break;

        default:
	  cout << "No action" << endl;
	  break;
	}
    }// end of loop
  fin.close();
  fout.close();
}

