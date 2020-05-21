#include "MovieValidator.h"

using namespace std;

MovieException::MovieException(std::vector<std::string> _errors) : errors{ _errors }
{
}

std::vector<std::string> MovieException::getErrors() const
{
	return this->errors;
}

void MovieValidator::validate(const Filme& m)
{
	vector<string> errors;
	if (m.getGenre().size() < 3)
		errors.push_back(string("The genre name cannot be less than 3 characters!\n"));
	if (!isupper(m.getTitle()[0]))
		errors.push_back(string("The title must start with a capital letter!\n"));

	// search for "www" or "http" at the beginning of the source string
	int posWww = m.getTrailer().find("www");
	int posHttp = m.getTrailer().find("http");
	if (posWww != 0 && posHttp != 0)
		errors.push_back("The youtube link must start with one of the following strings: \"www\" or \"http\"");

	if (errors.size() > 0)
		throw MovieException(errors);
}