#pragma once

#include <vector>
#include <tuple>
using namespace std;

typedef vector<tuple<int, int>> score;

class Game
{
public:
	Game();
	Game(score sc);
	~Game();

	score s;

	int calculScore();
	void addTuple(tuple<int, int> t);
};

