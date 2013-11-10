// Song.h
#include <cstdlib>
#include <ostream>
#include <cstring>
#include "List.h"

/* SONG
Song.h
Nick Giampietro | jnickg
giampiet@pdx.edu
Created 10 Nov 2013

This class contains information for a song, including:
	Artist that made the song
	Title of song
	Playlists it is in
	Length (seconds)
	Album
*/
class Song
{
public:
	// Default constructor
	Song(void);
	// Adds starter values; no playlists
	Song(char* t, char* ar, char* al, int l);
	// Default destructor
	~Song(void);

	// Adds song to a new playlist
	int addToPlaylist(char* pl);
	// Copies all data to this, from that
	int copySong(const Song& that);
	// Spits out a string representation of the instance
	char* toStr(void) const;
	
	// Prints all data
	std::ostream& print(std::ostream & out) const;
	// Calls copySong
	Song& operator=(const Song & right);
private:
	char* title; // The title of the song
	char* artist; // The artist who made the song
	char* album; // The album the song is in
	jnickg::adt::List<char*> playlists; // The playlists in which the song appears
	int length; // The length (in seconds) of the song
};
