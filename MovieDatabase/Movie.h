#pragma once
#include "Genre.h"
const int SIZE_MOVIE = 100;

struct Movie
{
	char tittle[SIZE_MOVIE];
	int issueYear;
	Genre genre;
	double popularity;
	int viewPrice;
};

enum TypeOfSort {
	MOVIE_TITTLE = 1, GENRE_MOVIE = 2, POPULARITY_MOVIE = 3, PRICE_MOVIE = 4, ISSUE_YEAR_MOVIE = 5
};


Movie* initMovies(Movie* movies, int size);
void allocaleNewMoviesList(Movie* movies, int newSize);

void parametrsOfMovie(const Movie& movies);
void printAllMovies(const Movie* movies, int size);
void printMovie(const Movie& movies, int size);

void enterPrice(Movie* movies);
void enterPopularity(Movie* movies);
void enterIssueYear(Movie* movies);
void addMovie(Movie* movies);
void addSpaceForMovie(Movie*& movies, int& oldSize);

void sortMovies(Movie* movies, int size, int sortChoice);
void sortByGenre(const Movie* movies, int size, int searchGenre);
void swap(Movie& moviesA, Movie& moviesB);
void sorting(Movie*& movies, int size, int choice);
void sortMovieByName(const Movie* movies, int size, char* searchStr);

void saveMoviesListToFile(const Movie* movies, int size_of_films);
void readMoviesFromFile(Movie*& movies, int& size_of_films);