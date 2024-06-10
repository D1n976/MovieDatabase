// MovieDatabase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <Windows.h>

#include "Movie.h"
using namespace std;

const int ADD_FILM = 1;
const int LOOK_INF_FILMS = 2;

void menuOfSortMovies() {
	cout << left << "\n1. ������������� �� ��������"
		<< "\n2. ������������� �� ����� "
		<< "\n3. ������������� �� ��������"
		<< "\n4. ������������� �� ����"
		<< "\n5. ������������� �� ����" << endl;
}

void mainMenu() {
	cout << left << "\"1. �������� ����� \"" << endl;
	cout << left << "\"2. ������� ���������� ������ \"" << endl;
}

bool proceed(char* continueWork) {
	while (true) {
		cout << "������ ����������? (yes / no) " << endl;
		cin.getline(continueWork, SIZE_MOVIE);

		if (*continueWork == '\0')
			return false;

		if (!_strnicmp("yes", continueWork, strlen(continueWork)))
			return true;
		else if (!_strnicmp("no", continueWork, strlen(continueWork)))
			return false;
		else
			cerr << "\n������ �������� ���, ���������� �����! " << endl;
	}
}

void actionsOfMenu(Movie *&movies, int &size) {				//�������� � �������� ���������� ����
	char continueWork[SIZE_MOVIE];
	do
	{
		int choice;
		mainMenu();
		cin >> choice;
		cin.ignore();

		if (choice == ADD_FILM) {
			addSpaceForMovie(movies, size);
			printMovie(movies[size - 1], size);
		}
		else if (choice == LOOK_INF_FILMS) {
			menuOfSortMovies();
			cin >> choice;
			cin.ignore();
			sortMovies(movies, size, choice);
		}
		else {
			HWND hWnd = GetForegroundWindow();
			MessageBox(hWnd, L"������ �������� �� ����������! ", L"������", MB_OK);
			exit('0');
		}

		cout << endl;
	} while (proceed(continueWork));
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size_of_films = 10;
	Movie* movies = new Movie[size_of_films];
	movies = initMovies(movies, size_of_films);

	ifstream sizeOfFilms;
	sizeOfFilms.open("filmsFile.txt");
	if (!sizeOfFilms)
		abort();
	int newSize = -1;
	sizeOfFilms >> newSize;
	sizeOfFilms.close();

	if (newSize > size_of_films) {
		readMoviesFromFile(movies, size_of_films);
	}

	cout << "� ������� ��������-�� ���� �������� ���� ������ ������� " << endl
		<< "��������� ����� ����������� ��������� ��� ����������� ������," << endl
		<< "���� �� ��������� �������� - �������� �����, �� ��������� ��������� ��� � �����, " << endl
		<< "���� �� ��������� ������� ����������, �� � ��� ���� �������� ������������," << endl
		<< "�� ������� �� ������ ������������� ���� ������ �������\n" << endl;
	actionsOfMenu(movies, size_of_films);
	saveMoviesListToFile(movies, size_of_films);
}