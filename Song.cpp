#include "Song.h"

// Default constructor
Song::Song(void)
{
	title = NULL;
	artist = NULL;
	album = NULL;
	length = 0;
}

// Adds starter values; no playlists
Song::Song(char* t, char* ar, char* al, int l)
{
	title = new char[strlen(t) + 1];
	strcpy(title, t);

	artist = new char[strlen(ar) + 1];
	strcpy(artist, ar);

	album = new char[strlen(al) + 1];
	strcpy(album, al);

	length = l;
}

// Default destructor
Song::~Song(void)
{
	delete title;
	title = NULL;
	delete artist;
	artist = NULL;
	delete album;
	album = NULL;
}

// Adds song to a new playlist
int Song::addToPlaylist(char* pl)
{
	return playlists.add_to_end(pl);
}

// Sets all the data to this, from params
int Song::setSongFrom(char* t, char* ar, char* al, int l)
{
	if(title) delete title;
	title = new char[strlen(t) + 1];
	strcpy(title, t);

	if(artist) delete artist;
	artist = new char[strlen(ar) + 1];
	strcpy(artist, ar);

	if(album) delete album;
	album = new char[strlen(al) + 1];
	strcpy(album, al);

	length = l;

	return 1;
}

// Copies all data to this, from that.
// Does not copy playlist data.
int Song::copySongFrom(const Song& that)
{
	*this = that;
	return 1;
}

// Copies all data from this, to that.
// Does not copy playlist data.
int Song::copySongTo(Song & that) const
{
	int worked;
	worked = that.setSongFrom(title, artist, album, length);
	return 1;
}

// Spits copies to ts a string representation of the instance.
int Song::toStr(char * & ts) const
{
	if(title && artist)
	{
		if(ts) delete ts;
		ts = new char[strlen(title) + strlen(artist) + 1];
		strcat(ts, title);
		strcat(ts, artist);
		strcat(ts, "\n");
		return 1;
	}
	else return 0;
}
	
// Prints all data
std::ostream& Song::print(std::ostream & out) const
{
	out << "SONG:" << std::endl;
	out << "title:\t" << title << std::endl;
	out << "artist:\t" << artist << std::endl;
	out << "album:\t" << album << std::endl;
	out << "length:\t" << length << " sec" << std::endl;
	out << "in playlists:" << std::endl;
	playlists.print(out);
	out << "\n" << std::endl;
}

// Calls copySong
Song& Song::operator=(const Song & right)
{
	right.copySongTo(*this);
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Song* const song)
{
	song->print(out);
	return out;
}
