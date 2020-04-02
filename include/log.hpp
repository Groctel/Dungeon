#ifndef DUNGEON_LOG
#define DUNGEON_LOG

#include <string>
#include <vector>

class Log {
private:
	static Log * instance;

	int pending;
	std::vector<std::string> history;

	Log ();
	Log (const Log & other) = delete;
public:
	static Log * Instance ();
	~Log ();

	void Record (const std::string message);
	void Print  () const;
};

#endif
