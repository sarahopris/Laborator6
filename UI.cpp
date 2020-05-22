#include "UI.h"
#include <string>
#include "MovieValidator.h"
#include "RepositoryExceptions.h"

using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1 - Manage repository." << endl;
	cout << "2 - Manage watchlist." << endl;
	cout << "0 - Exit." << endl;
}

void UI::printRepositoryMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add movie." << endl;
	cout << "\t 2 - Remove movie." << endl;
	cout << "\t 3 - Display all." << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::printPlayListMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add movie." << endl;
	cout << "\t 2 - Add movies by genre." << endl;
	cout << "\t 3 - Play." << endl;
	cout << "\t 4 - Next." << endl;
	cout << "\t 5 - Save watchlist to file." << endl;
	cout << "\t 6 - Display watchlist." << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::addMovieToRepo()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);
	int year;
	cout << "Enter the year: ";
	cin >> year;
	cin.ignore();
	int like;
	cout << "Enter the number of likes: ";
	cin >> like;
	cin.ignore();
	cout << "Trailer: ";
	std::string trailer;
	getline(cin, trailer);

	try
	{
		this->ctrl.addMovieToRepository(title, genre, year, like, trailer);
	}
	catch (MovieException & e)
	{
		for (auto s : e.getErrors())
			cout << s;
	}
	catch (RepositoryException & e)
	{
		cout << e.what() << endl;
	}
	catch (FileException & e)
	{
		cout << e.what() << endl;
	}
}

void UI::removeMovieFromRepo()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);

	try
	{
		this->ctrl.removeMovieFromRepository(title, genre);
	}
	catch (RepositoryException & e)
	{
		cout << e.what() << endl;
	}
}

void UI::displayAllMoviesRepo()
{
	vector<Filme> movielist = this->ctrl.getRepo().getMovies();
	if (movielist.size() == 0)
	{
		cout << "There are no movies in the repository." << endl;
		return;
	}

	for (auto m : movielist)
	{
		cout << m << endl;
	}
}

void UI::addMovieToWatchlist()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);

	// search for the song in the repository
	try
	{
		Filme m = this->ctrl.getRepo().findByTitleandGenre(title, genre);
		this->ctrl.addMovieToWatchlist(m);
	}
	catch (InexistentMovieException & e)
	{
		cout << e.what();
		cout << "Nothing will be added to the playlist." << endl;
	}
}

void UI::addAllMoviesByGenreToWatchlist()
{
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);

	this->ctrl.addAllMoviesByGenreToWatchlist(genre);
}

void UI::saveWatchlistToFile()
{
	std::string filename;
	cout << "Input the file name (absolute path): ";
	getline(cin, filename);

	try
	{
		this->ctrl.saveWatchlist(filename);

		if (this->ctrl.getWatchlist() == nullptr)
		{
			cout << "Watchlist cannot be displayed!" << endl;
			return;
		}
	}
	catch (FileException & e)
	{
		cout << e.what() << endl;
	}
}

void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		// repository management
		if (command == 1)
		{
			while (true)
			{
				UI::printRepositoryMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
					this->addMovieToRepo();
					break;
				case 2:
					this->removeMovieFromRepo();
					break;
				case 3:
					this->displayAllMoviesRepo();
					break;
				}
			}
		}

		// playlist management
		if (command == 2)
		{
			while (true)
			{
				UI::printPlayListMenu();
				int commandPlaylist{ 0 };
				cout << "Input the command: ";
				cin >> commandPlaylist;
				cin.ignore();
				if (commandPlaylist == 0)
					break;
				switch (commandPlaylist)
				{
				case 1:
					this->addMovieToWatchlist();
					break;
				case 2:
					this->addAllMoviesByGenreToWatchlist();
					break;
				case 3:
				{
					if (this->ctrl.getWatchlist()->isEmpty())
					{
						cout << "Nothing to watch, the watchlist is empty." << endl;
						continue;
					}
					this->ctrl.startWatchlist();
					Filme m = this->ctrl.getWatchlist()->getCurrentMovie();
					cout << "Now watching: " << m.getTitle() << endl;
					break;
				}
				case 4:
				{
					if (this->ctrl.getWatchlist()->isEmpty())
					{
						cout << "Nothing to play, the playlist is empty." << endl;
						continue;
					}
					this->ctrl.nextMovieWatchlist();
					Filme m = this->ctrl.getWatchlist()->getCurrentMovie();
					cout << "Now watching: " << m.getTitle() << endl;
					break;
				}
				case 5:
				{
					this->saveWatchlistToFile();
					break;
				}
				case 6:
				{
					this->ctrl.openWatchlist();
					break;
				}
				}
			}
		}
	}
}