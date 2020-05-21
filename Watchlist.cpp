#include "Watchlist.h"


Watchlist::Watchlist()
{
	this->current = 0;
}

void Watchlist::add(const Filme& movie)
{
	this->movielist.push_back(movie);
}

Filme Watchlist::getCurrentMovie()
{
	if (this->current == this->movielist.size())
		this->current = 0;
	return this->movielist[this->current];
	return Filme{};
}

void Watchlist::play()
{
	if (this->movielist.size() == 0)
		return;
	this->current = 0;
	Filme currentMovie = this->getCurrentMovie();
	currentMovie.play();
}

void Watchlist::next()
{
	if (this->movielist.size() == 0)
		return;
	this->current++;
	Filme currentMovie = this->getCurrentMovie();
	currentMovie.play();
}

bool Watchlist::isEmpty()
{
	return this->movielist.size() == 0;
}