#pragma once
#include <iostream>
#include <string>
using namespace std;
class Movie
{
private:
	string nameMovie;
	string countryMovie;
	string reviewMovie;
	int durationMovie;
	int yearMovie;
	Movie** movies;
public:
	Movie();
	Movie(string nameMovie, string countryMovie, string reviewMovie, int durationMovie, int yearMovie);
	~Movie();
	void createMovies(int numOfMovies);

	string printMovie();
	string printMoviePurchased();
};

