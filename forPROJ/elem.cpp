// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//----------------------------------------------------

#include "elem.h"

// blank element
el_t::el_t()
{
  year = -1;  // cannot be 0 because 0 is a valid key
  name = ""; //Name initialized to nothing
  artist = ""; //Artist initialized to nothing
  key = ""; //key initialized to nothing
  difficulty = ""; //difficulty initialized to nothing
}

// initializing constructor to create an el_t object 
el_t::el_t(string aname, string anartist, string akey, string adifficulty, int ayear)
{
  name = aname; // name initalized to aname
  artist = anartist; // artist initialized to anartist
  key = akey; // key initialized to akey
  difficulty = adifficulty; // difficulty initialized to adifficulty
  year = ayear; // year initialized to ayear
}

int el_t::getkey() // returns key
{
  return year;
}
 
void el_t::setkey(int ayear) //sets key
{
  year = ayear;
}
  
// overload == for search based on the key part only
bool el_t::operator==(el_t OtherOne)
{
  if (year == OtherOne.year) return true; else return false;
}

// overload != for search based on the key part only
bool el_t::operator!=(el_t OtherOne)
{
  if (year != OtherOne.year) return true; else return false;
}

// overload cout 
ostream& operator<<(ostream& os, const el_t& E)  
{  
  os << E.name << ", " << E.artist << ", " << E.key << ", " << E.difficulty << ", " << E.year;
  return os;  
}  
