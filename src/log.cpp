/** @file log.cpp
  */

#include "log.hpp"

Log * Log :: instance = nullptr;

/** @fn Log :: Log ()
  * @brief Default constructor
  */

Log :: Log ()
	:pending (0)
{ }

/** @fn Log * Log :: Instance ()
  * @brief Log's singleton instance getter
  *
  * If the instance doesn't exist (`== nullptr`), it creates a Log instance.
  *
  * @return Unique instance pointer
  */

Log * Log :: Instance () {
	if (instance == nullptr)
		instance = new Log;

	return instance;
}

/** @fn Log :: ~Log ()
  * @brief Default destructor
  *
  * Free's the log's instance memory.
  */

Log :: ~Log () {
	delete instance;
}

/** @fn size_t Log :: Pending () const
  * @brief Number of pending to print events getter
  *
  * @return Number of pending to print events
  */

size_t Log :: Pending () const {
	return pending;
}

/** @fn void Log :: Reset ()
  * @brief Game start timestamp resetter
  *
  * Resets the game start timestamp.
  */

void Log :: Reset () {
	time(&starttime);
}

/** @fn void Log :: Record (const std::string event)
  * @brief Insert a event into the events history
  *
  * @param event Message to be inserted
  *
  * Gets the current time and prints it in `[HH:MM]` format into the event
  * string followed by the event.
  */

void Log :: Record (const std::string text) {
	int seconds,
	    minutes;
	std::string event = "[";

	time(&now);

	seconds  = difftime(now, starttime);
	minutes  = seconds/60;
	seconds %= 60;

	if (minutes < 10)
		event += "0";

	event += std::to_string(minutes) + ":";

	if (seconds < 10)
		event += "0";

	event += std::to_string(seconds) + "] " + text;

	history.push_back(event);
	pending++;
}

/** @fn std::string Log :: Print ()
  * @brief Last event getter
  *
  * @return Last event string
  */

std::string Log :: Print () const {
	return * history.rbegin();
}

/** @fn std::string Log :: Print (size_t position) const
  * @brief Specific event getter
  *
  * @param position Index of the event to be printed
  *
  * @return Event string at the specified position
  */

std::string Log :: Print (size_t position) const {
	std::vector<std::string>::const_reverse_iterator it = history.crbegin();

	for (size_t i=0; i<position; i++, ++it);

	return *it;
}

/** @fn std::stack<std::string> Log :: Print (size_t from, size_t to) const
  * @brief Multiple events getter
  *
  * @param from Index of the first event to get
  * @param to   Index of the last event to get
  *
  * Both `history[from]` and `history[to]` are printed.
  *
  * @return Stack with the requested events in chronological order
  */

std::stack<std::string> Log :: Print (size_t from, size_t to) const {
	std::stack<std::string> events;
	std::vector<std::string>::const_reverse_iterator it = history.crbegin();

	for (size_t i=0; i<from; i++, ++it);

	for (size_t i=from; i<=to; i++, ++it)
		events.push(*it);

	return events;
}

/** @fn std::stack<std::string> Log :: PrintPending ()
  * @brief Pending events getter
  *
  * Prints the pending events into a stack in chronological order and sets
  * `pending` to `0`.
  *
  * @return Stack with the pending events in chronological order
  */

std::stack<std::string> Log :: PrintPending () {
	std::stack<std::string> events;
	std::vector<std::string>::const_reverse_iterator it = history.crbegin();

	for (size_t i=0; i<pending; i++, ++it)
		events.push(*it);

	pending = 0;

	return events;
}
