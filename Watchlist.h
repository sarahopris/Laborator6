#pragma once
#include <vector>
#include "Filme.h"

class Watchlist
{
protected:
	std::vector<Filme> movielist;
	int current;

public:
	Watchlist();

	// Adds a movie to the Watchlist.
	void add(const Filme& movie);

	// Returns the movie trailer that is currently being watched.
	Filme getCurrentMovie();

	// Starts the watchlist - plays the first movie trailer.
	void play();

	// Plays the next movie trailer in the watchlist.
	void next();

	// Checks if the Watchlist is empty.
	bool isEmpty();

	virtual ~Watchlist() {}
};

