#pragma once
#include <iostream>
#include <string>
#include "Movie.h"
#include "Room.h"
using namespace std;

class Cinema
{
private:
	int option;
	bool open;
	Movie movieInfo;
	Movie* movies;
	Room roomInfo;

public:
	Cinema();

	void archiveMenu();
	void maintenanceMenu();
	void reserveMenu();

	void about();

	void createMovies(Movie movie);
};

