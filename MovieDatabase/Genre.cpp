#include "Genre.h"
#include <iomanip>
#include <iostream>
using namespace std;

void showAllGenre() {
	cout << "\n1. " << "Романтика "
		<< "\t2. " << "Боевик \n"
		<< "3. " << "Ужасы "
		<< "\t4. " << "Комедия \n"
		<< "5. " << "Фантастика \n" << endl;
}

bool ifGenreIsNotInMoviesList(int searchGenre) {
	return searchGenre >= ROMANTIC && searchGenre <= FANTAZY;
}

void printGenre(Genre genre) {
	if (genre == ROMANTIC)
		cout << "Романтика ";
	else if (genre == THILLER)
		cout << "Боевик ";
	else if (genre == HORROR)
		cout << "Ужасы ";
	else if (genre == COMEDY)
		cout << "Комедия ";
	else if (genre == FANTAZY)
		cout << "Фантастика ";
}

void addGenreForMovie(Genre &genre, int typeGenre) {

	if (typeGenre == ROMANTIC)
		genre = ROMANTIC;
	else if (typeGenre == THILLER)
		genre = THILLER;
	else if (typeGenre == HORROR)
		genre = HORROR;
	else if (typeGenre == COMEDY)
		genre = COMEDY;
	else if (typeGenre == FANTAZY)
		genre = FANTAZY;
}