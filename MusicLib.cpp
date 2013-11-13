#include "MusicLib.h"

MusicLib::MusicLib(void)
{
	// Starting size is 37 for posterity and great success.
	artS = 37;
	albS = 37;

	int i;

	// Make default-size table for artists
	artistTable = new jnickg::adt::node<jnickg::adt::List<Song>>*[37];
	for(i=0; i<artS; i++) artistTable[i] = NULL;

	// Default-size table for albums
	albumTable = new jnickg::adt::node<Album>*[37];
	for(i=0; i<albS; i++) albumTable[i] = NULL;
}

MusicLib::~MusicLib(void)
{
	// Delete everything
}

// Copies the song's data to a new song and inserts it into the
// music library
int MusicLib::cpyToLib(Song & nSong)
{
	int worked = 0;
	Song cpy1, cpy2;
	// Get artist and album from nSong
	char* art;
	char* alb;
	nSong.getArtist(art);
	nSong.getAlbum(alb);

	// Make a new Song and copy nSong to it (assumes nSong is an interface temp)
	cpy1 = nSong;

	// Get the artist from nSong & hash it to add to artistTable
	worked += addByArtist(art, cpy1);

	// Make another new Song from nSong, so artistTable and albumTable don't share memory
	cpy2 = nSong;

	// Get the album from nSong & hash it to add to albumTable
	worked += addByAlbum(alb, cpy2);

	return worked;
}

// Adds nSong to artistTable; chains if needed
// If there is a collision, iterate through the LLL of List<Song>s
// and check if a list of name "artist" exists; if so, add the song
// when the right one is found or it is realized that a new List of
// name "artist" is needed
int MusicLib::addByArtist(char* artist, Song & nSong)
{
	int h = hash(artist);
	
	// Case 1: Nothing there yet
	if(NULL == artistTable[h%artS])
	{
		artistTable[h%artS] = new jnickg::adt::node<jnickg::adt::List<Song>>;
		artistTable[h%artS]->data.setName(artist);
		artistTable[h%artS]->data.add_to_end(nSong);
		artistTable[h%artS]->next = NULL;
		return 0;
	}
	// Case 2: Solve collision with chaining even though linear probing would be better
	else
	{
		// First check if an artist of this name exists by running getByArtist()

		// If it doesn't, add to head of chain by holding onto the head and adding one before it
		jnickg::adt::node<jnickg::adt::List<Song>>* tmp = artistTable[h%artS];
		artistTable[h%artS] = new jnickg::adt::node<jnickg::adt::List<Song>>;
		artistTable[h%artS]->data.setName(artist);
		artistTable[h%artS]->data.add_to_end(nSong);
		artistTable[h%artS]->next = tmp;
		return 1;
	}
}

// Adds nSong to albumTable; chains if needed
// If there is a collision, iterate through the LLL of Albums
// and check if a list of name "album" exists using retrieve;
// if so, add the song to retrieved album; if not, make a new album
// of name "album"
int MusicLib::addByAlbum(char* album, Song & nSong)
{
	int h = hash(album);

	// Case 1: Nothing there yet
	if(NULL == albumTable[h%artS])
	{
		albumTable[h%artS] = new jnickg::adt::node<Album>;
		albumTable[h%artS]->data.setTitle(album);
		albumTable[h%artS]->data.addSong(nSong);
		albumTable[h%artS]->next = NULL;
		return 0;
	}
	// Case 2: Solve collision with chaining even though linear probing would be better
	else
	{
		// First check if an album of this name exists by running getByAlbum()

		// If it doesn't, add to head of chain by holding onto the head and adding one before it
		jnickg::adt::node<Album>* tmp = albumTable[h%artS];
		albumTable[h%artS] = new jnickg::adt::node<Album>;
		albumTable[h%artS]->data.setTitle(album);
		albumTable[h%artS]->data.addSong(nSong);
		albumTable[h%artS]->next = tmp;
		return 1;
	}
}

// Searches for artist and copies existing albums to result
int MusicLib::getByArtist(char* artist, jnickg::adt::List<Album> & result)
{
	int h = hash(artist);
}

// Searches for album and copies existing songs to result
int MusicLib::getByAlbum(char* album, Album & result)
{
	int h = hash(album);
}

// Hashes the string using a simple hash function
int MusicLib::hash(char* str)
{
	return 1337;
}

