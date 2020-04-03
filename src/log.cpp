#include "log.hpp"

Log * Log :: instance = nullptr;

Log :: Log ()
{ }

Log * Log :: Instance () {
	if (instance == nullptr)
		instance = new Log;

	return instance;
}

Log :: ~Log () {
	delete instance;
}

size_t Log :: Pending () const {
	return pending;
}

void Log :: Start () {
	time(&starttime);
}

void Log :: Record (const std::string message) {
	int seconds,
	    minutes;

	time(&now);

	seconds  = difftime(now, starttime);
	minutes  = seconds/60;
	seconds %= 60;

	history.push_back("[");

	if (minutes < 10)
		history.rbegin()->append("0");

	history.rbegin()->append(std::to_string(minutes));
	history.rbegin()->append(":");

	if (seconds < 10)
		history.rbegin()->append("0");

	history.rbegin()->append(std::to_string(seconds));
	history.rbegin()->append("] ");
	history.rbegin()->append(message);

	pending++;
}

std::string Log :: Print () {
	pending = 0;
	return * history.rbegin();
}

std::string Log :: Print (size_t position) const {
	std::vector<std::string>::const_reverse_iterator it = history.crbegin();

	for (size_t i=0; i<position; i++, ++it);

	return *it;
}

std::stack<std::string> Log :: Print (size_t from, size_t to) const {
	std::stack<std::string> messages;
	std::vector<std::string>::const_reverse_iterator it = history.crbegin();

	for (size_t i=0; i<from; i++, ++it);

	for (size_t i=from; i<=to; i++, ++it)
		messages.push(*it);

	return messages;
}

std::stack<std::string> Log :: PrintPending () {
	std::stack<std::string> messages;
	std::vector<std::string>::const_reverse_iterator it = history.crbegin();

	for (size_t i=0; i<pending; i++, ++it)
		messages.push(*it);

	pending = 0;

	return messages;
}
