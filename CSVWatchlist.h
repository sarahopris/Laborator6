#pragma once
#include "FileWatchlist.h"
#include <string>

class CSVWatchlist : public FileWatchlist
{
public:
	/*
	Writes the Watchlist to file.
	Throws: FileException - if it cannot write.
	*/
	void writeToFile() override;

	/*
	Displays the Watchlist using Microsoft Excel.
	*/
	void displayWatchlist() const override;
};


