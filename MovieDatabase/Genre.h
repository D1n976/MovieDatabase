#pragma once

enum Genre
{
	ROMANTIC = 1, THILLER = 2, HORROR = 3, COMEDY = 4, FANTAZY = 5
};

void showAllGenre();
bool ifGenreIsNotInMoviesList(int searchGenre);
void printGenre(Genre genre);
void addGenreForMovie(Genre& genre, int typeGenre);