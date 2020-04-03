#ifndef DUNGEON_LOG
#define DUNGEON_LOG

#include <stack>
#include <string>
#include <vector>

class Log {
private:
	static Log * instance;

	size_t pending;
	std::vector<std::string> history;

	Log ();
	Log (const Log & other) = delete;
public:
	static Log * Instance ();
	~Log ();

	size_t Pending () const;

	void Record (const std::string message);

	std::string             Print        ();
	std::string             Print        (size_t position) const;
	std::stack<std::string> PrintPending ();
	std::stack<std::string> Print        (size_t from, size_t to) const;
};

#endif
