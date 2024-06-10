#include "Movie.h"
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

void allocaleNewMoviesList(Movie* movies, int newSize) {
	Movie* movie = new Movie[newSize];
}

void parametrsOfMovie(const Movie& movies) {
	cout << movies.tittle << endl;					//Показывает ошибку при взятии данных из файла
	cout << "Год выпука: " << movies.issueYear << endl;
	cout << "Рейтинг: " << movies.popularity << endl;
	cout << "Цена за один билет: " << movies.viewPrice << endl;
	cout << "Жанр фильма: ";
	printGenre(movies.genre);
	cout << endl;
}

void printAllMovies(const Movie* movies, int size) {
	for (int i = 0; i < size; i++) {
		parametrsOfMovie(movies[i]);
		cout << endl;
	}
}

void printMovie(const Movie& movies, int size) {
	parametrsOfMovie(movies);
	cout << endl;
}

void enterIssueYear(Movie* movies) {
	while (true) {
		cin >> movies->issueYear;
		cin.ignore();

		if (movies->issueYear >= 1895 && movies->issueYear <= 2020)
			break;
		else
			cerr << "Диапазон варьируется от 1895 до 2020 " << endl;
	}
}

void enterPrice(Movie* movies) {
	while (true) {
		cin >> movies->viewPrice;
		cin.ignore();

		if (movies->viewPrice >= 0)
			break;
		else
			cerr << "Цена не может быть отрицательной " << endl;
	}
}

void enterPopularity(Movie *movies) {			//Специально для популярности фильма, значение обязательно должно быть дробным
	bool correctPopularity = false;
	do {
		cin >> movies->popularity;
		cin.ignore();
		
		if (movies->popularity >= 0 && movies->popularity <= 10) {
			correctPopularity = true;
		}
		else
			cerr << "Популярность 0 - 10 " << endl;

	} while (!correctPopularity);
}

void addMovie(Movie* movies) {			//Добавить новый фильма					
	cout << endl;					
	cout << "Введите название фильма ";
	cin.getline(movies->tittle, 20);

	cout << "Введите год выпуска фильма ";
	enterIssueYear(movies);

	cout << "Введите рейтинг фильма ";
	enterPopularity(movies);

	cout << "Введите цену за билет ";
	enterPrice(movies);

	int typeGenre;
	do {
		cout << "Выберите одну из категорий ";
		showAllGenre();
		cin >> typeGenre;
		cin.ignore();
		addGenreForMovie(movies->genre, typeGenre);
	} while (!ifGenreIsNotInMoviesList(typeGenre));
}

void addSpaceForMovie(Movie*& movies, int& oldSize) {			//Выделить место для нового фильма
	int newSize = oldSize + 1;
	Movie* newMovies = new Movie[newSize];

	memcpy(newMovies, movies, sizeof(Movie) * oldSize);
	addMovie(newMovies + oldSize);

	delete[] movies;

	movies = newMovies;
	oldSize = newSize;
}

void sortMovies(Movie* movies, int size, int sortChoice) {			//Сортировка каталога фильмов
	char searchStr[SIZE_MOVIE];

	if (sortChoice == MOVIE_TITTLE) {
		cout << "\nВведите строку, которую хотите найти " << endl;
		cin.getline(searchStr, SIZE_MOVIE);
		cout << endl;
		sortMovieByName(movies, size, searchStr);
	}
	else if (sortChoice == GENRE_MOVIE) {
		showAllGenre();
		cout << "Введите жанр фильма ";
		int searchGenre;
		cin >> searchGenre;
		cin.ignore();
		cout << endl;
		sortByGenre(movies, size, searchGenre);
	}
	else if (sortChoice == POPULARITY_MOVIE || sortChoice == PRICE_MOVIE || sortChoice == ISSUE_YEAR_MOVIE) {
		cout << endl;
		sorting(movies, size, sortChoice);
		printAllMovies(movies, size);
	}
	else
		cerr << "\nОшибка, неверно выбран фильтр! " << endl;
}

void swap(Movie& moviesA, Movie& moviesB) {					
	Movie temp = moviesA;
	moviesA = moviesB;
	moviesB = temp;
}

void sorting(Movie*& movies, int size, int choice) {					//Сортировка для фильмов по популярности, цене или году
	for (int ceiling = size - 1; ceiling >= 0; ceiling--) {
		for (int i = 0; i + 1 <= ceiling; i++) {
			if (choice == POPULARITY_MOVIE) {
				if (movies[i].popularity > movies[i + 1].popularity)
					swap(movies[i], movies[i + 1]);
			}
			else if (choice == PRICE_MOVIE) {
				if (movies[i].viewPrice > movies[i + 1].viewPrice)
					swap(movies[i], movies[i + 1]);
			}
			else if (choice == ISSUE_YEAR_MOVIE) {
				if (movies[i].issueYear < movies[i + 1].issueYear)
					swap(movies[i], movies[i + 1]);
			}
		}
	}
}

void sortMovieByName(const Movie* movies, int size, char* searchStr) {		//Поиск по названию 
	bool isInArrayOfMovies = false;
	for (int i = 0; i < size; i++) {
		if (strstr(movies[i].tittle, searchStr)) {
			parametrsOfMovie(movies[i]);
			isInArrayOfMovies = true;
			cout << endl;
		}
	}

	if (!isInArrayOfMovies)
		cerr << "Введенного вами фильма нет в базе " << endl;
	cout << endl;
}

void sortByGenre(const Movie* movies, int size, int searchGenre) {			//Сортировка по жанру (меню 1, 2, 3...)
	if (!ifGenreIsNotInMoviesList(searchGenre)) {
		cerr << "По такому жанру нет фильма " << endl;
		return;
	}

	for (int i = 0; i < size; i++)
		if (movies[i].genre == searchGenre) {
			parametrsOfMovie(movies[i]);
			cout << endl;
		}
}

Movie* initMovies(Movie* movies, int size) {				//Пробелы в файле считаюся разделителями, по этой причине высе пробелы были заменены на _
	movies[0] = { "Venom", 2020, COMEDY, 8.2, 1500 };
	movies[1] = { "The_Twilight_Saga_:_Breaking_Dawn_Part_2", 2012, ROMANTIC, 6.6, 1000 };
	movies[2] = { "Iron_Man_2", 2010, THILLER, 7.5, 1350 };
	movies[3] = { "Calls", 2017, HORROR, 4.8, 1700 };
	movies[4] = { "Where_monsters_live", 2010, FANTAZY, 6.9, 700 };
	movies[5] = { "Ouiji:_Devil's_Board", 2014, HORROR, 4.9, 900 };
	movies[6] = { "Lord_of_the_Rings_:_Two_Towers", 2002, FANTAZY, 8.6, 1700 };
	movies[7] = { "The_blade", 2020, THILLER, 5.6, 1390 };
	movies[8] = { "Fantasy_island", 2020, HORROR, 5.4, 1150 };
	movies[9] = { "Step_by_step", 2020, COMEDY, 6.5, 1600 };

	return movies;
}

void saveMoviesListToFile(const Movie *movies, int size_of_films) {				//Записать все данные в файл
	ofstream filmsFile;
	filmsFile.open("filmsFile.txt", ios::out);

	if (!filmsFile) {
		cerr << "File path not found: filmsFile.txt " << endl;
		return;
	}

	filmsFile << size_of_films << endl;

	for (int i = 0; i < size_of_films; i++) {
		filmsFile << movies[i].tittle << endl
			<< movies[i].issueYear << ' '
			<< movies[i].genre << ' '
			<< movies[i].popularity << ' '
			<< movies[i].viewPrice << endl;
	}

	filmsFile.close();
}

void readMoviesFromFile(Movie *&movies, int &size_of_films) {				//Читаем данные из файла и записываем в массив
	ifstream readFilmslist;												

	readFilmslist.open("filmsFile.txt", ios::in);
	if (!readFilmslist) {
		cerr << "File path not found: filmsFile.txt " << endl;
		return;
	}

	int newSize;
	readFilmslist >> newSize;

	Movie* newMovies = new Movie[newSize];
	int *tempGenre = new int[newSize];

	for (int i = 0; i < newSize; i++) {
		readFilmslist >> newMovies[i].tittle
			>> newMovies[i].issueYear
			>> tempGenre[i]
			>> newMovies[i].popularity
			>> newMovies[i].viewPrice;
	}

	for (int i = 0; i < newSize; i++)
		addGenreForMovie(newMovies[i].genre, tempGenre[i]);

	delete[] movies;
	delete[] tempGenre;
	readFilmslist.close();

	movies = newMovies;
	size_of_films = newSize;
}