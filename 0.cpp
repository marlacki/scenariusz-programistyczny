#include <cstdlib>
#include <iostream>
#include<Windows.h>
#include<string>
#include <fstream>
#pragma warning(disable:4996)
#include <stdio.h>
#include <cctype>
#include <urlmon.h>


#define MAX_LINE 512;

using namespace std;

int main()
{
	int choice;

	do {
		cout << "Menu\n";
		cout << "Dokonaj wyboru\n";
		cout << "1 - Pobierz plik z internetu\n";
		cout << "2 - Zlicz liczbe liter w pliku\n";
		cout << "3 - Zlicz liczbe wyrazow w pliku\n";
		cout << "4 - Zlicz liczbe znakow interpunkcyjnych w pliku\n";
		cout << "5 - Zlicz liczbe zdan pliku\n";
		cout << "6 - Wygeneruj raport o uzyciu liter (A-Z)\n";
		cout << "7 - Zapisz statystyki z punktow 2-5 do pliku statystyki.txt\n";
		cout << "8 - Wyjscie z programu\n";
		cout << "Wybor: ";
		cin >> choice;

		switch (choice) {
		case 1:
			//download();
			break;
		case 2:
			//sumofletters();
			break;
		case 3:
			//countWords();
			break;
		case 4:
			//znaki();
			break;

		case 5:
			//zdania();
			break;
		case 6:
			//letterslist();
			break;
		case 7:
			//stats1();;
			break;
		case 8:
			cout << "Goodbye!";
			return 0;
		default:
			cout << "Menu\n";
			cout << "Dokonaj wyboru\n";
			cout << "1 - Pobierz plik z internetu\n";
			cout << "2 - Zlicz liczbe liter w pliku\n";
			cout << "3 - Zlicz liczbe wyrazow w pliku\n";
			cout << "4 - Zlicz liczbe znakow interpunkcyjnych w pliku\n";
			cout << "5 - Zlicz liczbe zdan pliku\n";
			cout << "6 - Wygeneruj raport o uzyciu liter (A-Z)\n";
			cout << "7 - Zapisz statystyki z punktow 2-5 do pliku statystyki.txt\n";
			cout << "8 - Wyjscie z programu\n";
			cout << "Wybór: ";
			cin >> choice;
		}
	} while (choice != 8);

	return EXIT_SUCCESS;
}