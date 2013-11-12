#include "MusicLib.h"

MusicLib::MusicLib(void)
{
	int i;

	// Make default-size table for artists
	artistTable = new jnickg::adt::node<jnickg::adt::List<Song>>*[37];
	for(i=0; i<37; i++) artistTable[i] = NULL;

	// Default-size table for albums
	albumTable = new jnickg::adt::node<Album>*[37];
	for(i=0; i<37; i++) albumTable[i] = NULL;
}

MusicLib::~MusicLib(void)
{

}

// Copies the song's data to a new song and inserts it into the
// music library
int MusicLib::cpyToLib(Song & nSong)
{
	// Make a new Song and copy nSong to it (assumes nSong is an interface temp)

	// Get the artist from nSong & hash it to add to artistTable

	// Make another new Song from nSong, so artistTable and albumTable don't share memory

	// Get the album from nSong & hash it to add to albumTable
}

// Adds nSong to artistTable; chains if needed
int MusicLib::addByArtist(char* artist, Song & nSong)
{
	// If there is a collision, iterate through the LLL of List<Song>s
	// and check if a list of name "artist" exists; if so, add the song
	// when the right one is found or it is realized that a new List of
	// name "artist" is needed
}

// Adds nSong to albumTable; chains if needed
int MusicLib::addByAlbum(char* album, Song & nSong)
{
	// If there is a collision, iterate through the LLL of Albums
	// and check if a list of name "album" exists using retrieve;
	// if so, add the song to retrieved album; if not, make a new album
	// of name "album"
}

// Searches for artist and copies existing albums to result
int MusicLib::getByArtist(char* artist, jnickg::adt::List<Album> & result)
{

}

// Searches for album and copies existing songs to result
int MusicLib::getByAlbum(char* album, Album & result)
{

}

// Hashes the string using a simple hash function
int MusicLib::hash(char* str)
{

}

