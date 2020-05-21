#include "Repository.h"
#include <string>
#include <fstream>
#include "Utils.h"


using namespace std;

Repository::Repository(const std::string& filename)
{
	this->filename = filename;
	this->readFromFile();
}

void Repository::addMovie(const Filme& m)
{
}

void Repository::removeMovie(const Filme& m)
{
}


Filme Repository::findByTitleandGenre(const std::string& title, const std::string& genre) const
{
	for (auto m : this->movielist)
	{
		if (m.getTitle() == title && m.getGenre() == genre)
			return m;
	}

}

void Repository::readFromFile()
{
	ifstream file(this->filename);

	
	Filme m;
	while (file >> m)
		this->movielist.push_back(m);

	file.close();
}

void Repository::writeToFile()
{
	ofstream file(this->filename);
	
	for (auto m : this->movielist)
	{
		file << m;
	}

	file.close();
}