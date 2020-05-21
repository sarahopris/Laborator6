#pragma once
#include <iostream>

class Filme
{
private:
	std::string title;
	std::string genre;
	int year; // appearance year
	int like;
	std::string trailer; // youtube link

public:
	// default constructor
	Filme();

	// constructor with parameters
	Filme(const std::string& title, const std::string& genre, const int& year, const int& like, const std::string& trailer);

	std::string getTitle() const { return title; }
	std::string getGenre() const { return genre; }
	int getYear() const { return year; }
	int getLike() const { return like; }
	std::string getTrailer() const { return trailer; }

	bool operator==(const Filme& m);

	void play();

	friend std::istream& operator>>(std::istream& is, Filme& m);
	friend std::ostream& operator<<(std::ostream& os, const Filme& m);
};
