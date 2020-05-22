#include "Repository.h"
#include <string>
#include <fstream>
#include "Utils.h"
#include "RepositoryExceptions.h"

using namespace std;

Repository::Repository(const std::string& filename)
{
	this->filename = filename;
	this->readFromFile();
}

void Repository::addMovie(const Filme& m)
{
	Filme m1{};
	try
	{
		m1 = this->findByTitleandGenre(m.getTitle(), m.getGenre());
		throw DuplicateMovieException();
	}
	catch (InexistentMovieException& ) {}
	this->movielist.push_back(m);
	this->writeToFile();
}

void Repository::removeMovie(const Filme& m)
{
	auto it = find(this->movielist.begin(), this->movielist.end(), m);
	if (it == this->movielist.end())
		throw InexistentMovieException{};
	this->movielist.erase(it);
	this->writeToFile();
}


Filme Repository::findByTitleandGenre(const std::string& title, const std::string& genre) const
{
	for (auto m : this->movielist)
	{
		if (m.getTitle() == title && m.getGenre() == genre)
			return m;
	}
	throw InexistentMovieException{};
}

void Repository::readFromFile()
{
	ifstream file(this->filename);
	if (!file.is_open())
		throw FileException("The file could not be opened!");

	
	Filme m;
	while (file >> m)
		this->movielist.push_back(m);

	file.close();
}

void Repository::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw FileException("The file could not be opened!");

	for (auto m : this->movielist)
	{
		file << m;
	}

	file.close();
}