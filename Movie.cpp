#include "Movie.h"

Movie::Movie()
{
	nameMovie = " ";
	countryMovie = " ";
	reviewMovie = " ";
	durationMovie = 0;
	yearMovie = 0;
	movies = nullptr;
}

Movie::Movie(string nameMovie, string countryMovie, string reviewMovie, int durationMovie, int yearMovie)
{
	this->nameMovie = nameMovie;
	this->countryMovie = countryMovie;
	this->reviewMovie = reviewMovie;
	this->durationMovie = durationMovie;
	this->yearMovie = yearMovie;
	this->movies = movies;
}

Movie::~Movie()
{
	delete movies;
}

void Movie::createMovies(int numOfMovies)
{
	int movieCount = 0;
	movies = new Movie * [numOfMovies];

	printf("Nombre de la pelicula: \n");
	getline(cin, nameMovie);

	printf("Pais de la pelicula: \n");
	getline(cin, countryMovie);

	printf("Review de la pelicula: \n");
	getline(cin, reviewMovie);

	printf("Duracion de la pelicula en minutos: \n");
	scanf_s("%d", &durationMovie);

	printf("Anio de la pelicula: \n");
	scanf_s("%d", &yearMovie);
	cin.ignore();

	movies[movieCount] = new Movie(nameMovie, countryMovie, reviewMovie, durationMovie, yearMovie);
	movieCount++;
}

string Movie::getMovieName()
{
	return nameMovie;
}

string Movie::printMovie()
{
	string movie;

	movie += "Nombre: " + nameMovie + "\n";
	movie += "Pais: " + countryMovie + "\n";
	movie += "Review: " + reviewMovie + "\n";
	movie += "Duracion: " + to_string(durationMovie) + " minutos\n";
	movie += "Anio: " + to_string(yearMovie) + "\n";

	return movie;
}

string Movie::printMoviePurchased()
{
	return "Nombre: " + nameMovie + "\n";
}
