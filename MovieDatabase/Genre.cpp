#include "Genre.h"
#include <iomanip>
#include <iostream>
using namespace std;

void showAllGenre() {
	cout << "\n1. " << "��������� "
		<< "\t2. " << "������ \n"
		<< "3. " << "����� "
		<< "\t4. " << "������� \n"
		<< "5. " << "���������� \n" << endl;
}

bool ifGenreIsNotInMoviesList(int searchGenre) {
	return searchGenre >= ROMANTIC && searchGenre <= FANTAZY;
}

void printGenre(Genre genre) {
	if (genre == ROMANTIC)
		cout << "��������� ";
	else if (genre == THILLER)
		cout << "������ ";
	else if (genre == HORROR)
		cout << "����� ";
	else if (genre == COMEDY)
		cout << "������� ";
	else if (genre == FANTAZY)
		cout << "���������� ";
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