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

int countChars(char letter);

int sumofletters()
{
	int freq[128];     // frequencies of letters
	ifstream inFile;   // input file
	char ch;

	inFile.open("test.txt");
	if (!inFile)
	{
		cout << "The input file could not be opened." << endl;
		return 1;
	}

	// initialize frequency counts to zero for each possible letter
	for (int k = 0; k < 128; k++)
	{
		freq[k] = 0;
	}

	// Read the file, keeping track of frequency with which each letter occurs
	ch = inFile.get();
	while (ch != EOF)
	{
		ch = toupper(ch);
		freq[ch]++;
		ch = inFile.get();
	}
	// Print the output table

	int sum = 0;
	for (char ch = 'A'; ch <= 'Z'; ch++)
	{

		sum = freq[ch] + sum;
	}
	cout << "Suma liter: " << sum << endl;
	return 0;
}

int download()
{
	char adres[] = "https://s3.zylowski.net/public/input/7.txt";
	char destination[] = "test.txt";
	char buffer[512];
	HRESULT dl;

	typedef HRESULT(WINAPI* URLDownloadToFileA_t)(LPUNKNOWN pCaller, LPCSTR szURL, LPCSTR szFileName, DWORD dwReserved, void* lpfnCB);
	URLDownloadToFileA_t xURLDownloadToFileA;
	xURLDownloadToFileA = (URLDownloadToFileA_t)GetProcAddress(LoadLibraryA("urlmon"), "URLDownloadToFileA");

	dl = xURLDownloadToFileA(NULL, adres, destination, 0, NULL);

	sprintf(buffer, "Downloading File From: %s, To: %s", adres, destination);

	if (dl == S_OK)
	{
		sprintf(buffer, "File Successfully Downloaded To: %s", destination);
		printf(buffer);
	}
	else if (dl == E_OUTOFMEMORY)
	{
		sprintf(buffer, "Failed To Download File Reason: Insufficient Memory");
		printf(buffer);
		return 0;
	}
	else
	{
		sprintf(buffer, "Failed To Download File Reason: Unknown");
		printf(buffer);
		return 0;
	}
}

int countWords() {
	string line;
	int words = 0;
	string word;
	ifstream myfile("test.txt");
	while (myfile >> word) {
		++words;
	}
	cout << words << "\n";

	return 0;
}


class RedirectStdOutput {
public:
	RedirectStdOutput(std::ofstream& file)
		: _psbuf{ file.rdbuf() }, _backup{ std::cout.rdbuf() }
	{
		std::cout.rdbuf(_psbuf);
	}

	~RedirectStdOutput() {
		std::cout.rdbuf(_backup);
	}

private:
	std::streambuf* _psbuf;
	std::streambuf* _backup;
};


int letterslist()
{
	char letter;

	cout << "Letter\t\tHow many times" << endl;

	for (letter = 'a'; letter <= 'z'; letter++)
	{

		cout << letter << "\t\t" << countChars(letter) << " times" << endl;
	}
	for (letter = 'A'; letter <= 'Z'; letter++)
	{
		cout << letter << "\t\t" << countChars(letter) << " times" << endl;
	}




	return EXIT_SUCCESS;
}

int zdania() {
	const int n = 4;
	int countx = 0;
	char chars[n] = { '.', ',', '?', '!' };

	ifstream myfile("test.txt");
	char c;
	while (!myfile.eof()) {
		myfile >> c;
		for (int i = 0; i < n; i++) {
			if (c == chars[i]) {
				countx++;
			}
		}
	}
	myfile.close();
	cout << "Ilosc znakow interpunkcyjnych" << countx - 1 << endl;
	return 0;
}


int znaki() {
	const int n = 4;
	int count = 0;
	char chars[n] = { '.', ',', '?', '!' };
	ifstream myfile("test.txt");
	char c;
	while (!myfile.eof()) {
		myfile >> c;
		for (int i = 0; i < n; i++) {
			if (c == chars[i]) {
				count++;
			}
		}
	}
	myfile.close();
	cout << "Ilosc zdan:" << count - 1 << endl;
	return 0;
}

int countChars(char letter)
{
	{
		ifstream stream;
		char character;
		int count = 0;

		stream.open("test.txt");
		stream.get(character);

		while (!stream.fail())
		{
			if (character == letter)
				count++;
			stream.get(character);
		}
		stream.close();

		return count;
	}
}

int stats1()
{

	freopen("statystyki.txt", "w", stdout);
	sumofletters();
	zdania();
	znaki();
	fclose(stdout);
	return 0;
}

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

			download();
			break;
		case 2:
			sumofletters();
			break;
		case 3:
			countWords();
			break;
		case 4:
			znaki();
			break;

		case 5:
			zdania();
			break;
		case 6:
			letterslist();
			break;
		case 7:
			stats1();;
			break;
		case 8:
			cout << "Goodbye!";
			if (remove("test.txt") != 0)
				perror("Error deleting file");
			else
				puts("File successfully deleted");
			
			if (remove("statystyki.txt") != 0)
				perror("Error deleting file");
			else
				puts("File successfully deleted");
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