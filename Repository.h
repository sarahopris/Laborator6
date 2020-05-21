#pragma once
#include "Filme.h"
#include <vector>

class Repository
{
private:
	std::vector<Filme> movielist;
	std::string filename;

public:
	
	//Constructor with parameters.
	Repository(const std::string& filename);

	
	//Adds a movie to the repository.
	void addMovie(const Filme& m);

	
	void removeMovie(const Filme& m);

	
	//Finds a song, by artist and title.
	Filme findByTitleandGenre(const std::string& title, const std::string& genre) const;

	std::vector<Filme> getMovies() const { return movielist; }

private:
	void readFromFile();
	void writeToFile();
};