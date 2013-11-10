#include "Song.h"

/* ALBUM
Album.h
Nick Giampietro | jnickg
giampiet@pdx.edu
Created 10 Nov 2013

This class contains information for a music album:
	The name of the album
	A list of the songs in the playlist
*/

class Album
{
public:
	Album(void);
	~Album(void);

	char* toStr(void) const;
	std::ostream& print(std::ostream & out) const;
private:

};
