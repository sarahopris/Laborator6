#pragma once
#include "Repository.h"
#include "FileWatchlist.h"
#include "MovieValidator.h"
#include <memory>

class Controller
{
private:
	Repository repo;
	FileWatchlist* watchlist;
	MovieValidator validator;

public:
	Controller(const Repository& r, FileWatchlist* p, MovieValidator v) : repo{ r }, watchlist{ p }, validator{ v } {}
	
	//controller nu poate fi copiat acum, pt ca contine unique_ptr
	Controller(const Controller& ctrl) = delete;		
	void operator=(const Controller& ctrl) = delete;	// la fel si pt assignment

	Repository getRepo() const { return repo; }
	Watchlist* getWatchlist() const { return watchlist; }

	/*
	Adds a song with the given data to the song repository.
	Throws: SongException - if the song is not valid
	DuplicateSongException - if there is another song with the same artist and title
	Throws: FileException - if the repository file cannot be opened.
	*/
	void addMovieToRepository(const std::string& title, const std::string& genre, const int& year, const int& like, const std::string& trailer);

	void removeMovieFromRepository(const std::string& title, const std::string& genre);


	/*
	Adds a given song to the current Watchlist.
	Input: song - Song, the song must belong to the repository.
	Output: the song is added to the Watchlist.
	*/
	void addMovieToWatchlist(const Filme& movie);

	// Adds all the songs from the repository, that have the given artist, to the current Watchlist.
	void addAllMoviesByGenreToWatchlist(const std::string& genre);

	void startWatchlist();
	void nextMovieWatchlist();

	/*
	Saves the Watchlist.
	 FileException - if the given file cannot be opened.
	*/
	void saveWatchlist(const std::string& filename);

	/*
	Opens the Watchlist, with an appropriate application.
	 FileException - if the given file cannot be opened.
	*/
	void openWatchlist() const;
};


