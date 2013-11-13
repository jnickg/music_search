#include <cstring>
#include <cstdlib>
#include <iostream>
#include "MusicLib.h"


// This implementation of main is simply a test of the data structures implemented
int main(void)
{
	MusicLib m;
	Song tmpS;
	Album tmpA;
	jnickg::adt::List<Song> tmpL;

	std::cout << "Creating new song: Thriller, by Michael JAckson" << std::endl;
	tmpS.setSongFrom("Thriller", "Michael Jackson", "Thriller", 500);

	std::cout << "Copying Thriller to the music library" << std::endl;
	m.cpyToLib(tmpS);

	std::cout << "Trying to pull by Artist" << std::endl;
	m.getByArtist("Michael Jackson", tmpL);

	std::cout << "Attempting to print the pulled list of songs by Michael Jakcson." << std::endl;
	tmpL.print(std::cout);

	std::cout << "Trying to pull by album" << std::endl;
	m.getByAlbum("Thriller", tmpA);

	std::cout << "Attempting to print the pulled album \'Thriller\'" << std::endl;
	tmpA.print(std::cout);


	return 0;
}
