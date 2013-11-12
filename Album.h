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
	// Default constructor
	Album(void);
	// Gives the album a title
	Album(char* t);
	// Default destructor
	~Album(void);

	// Used by MusicLib to test if an element in albumTable's
	// chain matches the one being requested--if so, copies to
	// found and returns 1; if not, returns 0.
	int retrieve(char* name, Album & found);

	// Adds a song to the album
	int addSong(const Song & song);
	// Spits out a string representation of the album
	char* toStr(void) const;
	// Iterates through songs and prints each
	std::ostream& print(std::ostream & out) const;
private:
	char* title;
	jnickg::adt::List<Song> songs; // The songs in the album

	// Invokes the album's print function
	friend std::ostream& operator<<(std::ostream& out, const Album* const album);
};
