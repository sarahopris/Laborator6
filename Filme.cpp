#include "Filme.h"
#include <Windows.h>
#include <shellapi.h>
#include "Utils.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

Filme::Filme() : title(""), genre(""), year(), like(), trailer("") {}

Filme::Filme(const std::string& title, const std::string& genre, const int& year, const int& like, const std::string& trailer)
{
	this->title = title;
	this->genre = genre;
	this->year = year;
	this->like = like;
	this->trailer = trailer;
}



bool Filme::operator==(const Filme& m)
{
	return (this->title == m.title && this->genre == m.genre);
}

void Filme::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}

istream& operator>>(istream& is, Filme& m)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 5) // make sure all the starship data was valid
		return is;

	m.title = tokens[0];
	m.genre = tokens[1];
	m.year = stoi(tokens[2]);
	m.like = stoi(tokens[3]);
	m.trailer = tokens[4];

	return is;

}

ostream& operator<<(ostream& os, const Filme& m)
{
	os << m.title << ", " << m.genre << ", " << m.year << ", " << m.like << ", " << m.trailer << "\n";
	return os;
}
