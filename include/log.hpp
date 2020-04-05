/** @file log.hpp
  */

#ifndef DUNGEON_LOG
#define DUNGEON_LOG

#include <ctime>
#include <stack>
#include <string>
#include <vector>

/** @class Log
  * @brief Events log with game time registry
  *
  * @var Log* instance
  * Singleton instance pointer
  *
  * @var size_t pending
  * Number of events recorded but not printed
  *
  * @var time_t now
  * Current time, compared with `starttime` to get the game gime
  *
  * @var time_t starttime
  * Game start timestamp
  *
  * @var std::vector<std::string> history
  * Events history
  */

class Log {
private:
	static Log * instance;

	size_t pending;
	time_t now,
	       starttime;
	std::vector<std::string> history;

	Log ();
	Log (const Log & other) = delete;

public:
	static Log * Instance ();
	~Log ();

	size_t Pending () const;

	void Reset  ();
	void Record (const std::string text);

	std::string             Print        () const;
	std::string             Print        (size_t position) const;
	std::stack<std::string> Print        (size_t from, size_t to) const;
	std::stack<std::string> PrintPending ();
};

#endif
