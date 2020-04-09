#ifndef DUNGEON_ENUM
#define DUNGEON_ENUM

enum Coordinate {
	east,
	north,
	northeast,
	northwest,
	south,
	southeast,
	southwest,
	west,

	e  = east,
	n  = north,
	ne = northeast,
	nw = northwest,
	s  = south,
	se = southeast,
	sw = southwest,
	w  = west
};

enum Scrolling {
	down,
	up,

	d = down,
	u = up,
};

#endif
