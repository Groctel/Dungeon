#include "log.hpp"

Log :: Log ()
{ }

Log * Log :: Instance () {
	if (instance == nullptr) {
		instance = new Log;
	}

	return instance;
}

Log :: ~Log () {
	delete instance;
}

void Log :: Record (const std::string action) {
	history.push_back(action);
}

void Log :: Print () const {

}
