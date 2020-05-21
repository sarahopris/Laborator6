#include "RepositoryExceptions.h"

FileException::FileException(const std::string& msg) : message(msg)
{
}

const char* FileException::what()
{
	return message.c_str();
}

RepositoryException::RepositoryException() : exception{}, message{ "" }
{
}

RepositoryException::RepositoryException(const std::string& msg) : message{ msg }
{
}

const char* RepositoryException::what()
{
	return this->message.c_str();
}

const char* DuplicateMovieException::what()
{
	return "There is another moviee with the same artist and title!";
}

const char* InexistentMovieException::what()
{
	return "There are no movies with the given artist and title!";
}
