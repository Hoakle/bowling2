
#include "Game.h"
#include <vector>
#include <tuple>

using namespace std;

Game::Game()
{
}

Game::Game(score sc)
{
	s = sc;
}


Game::~Game()
{
}

int Game::calculScore()
{
	int somme = 0;
	unsigned int i = 0;
	while (i<s.size() && i<10) {
		if (get<0>(s.at(i)) + get<1>(s.at(i)) == 10) {
			if (get<0>(s.at(i)) == 10) {
				if (get<0>(s.at(i + 1)) == 10) {
					somme += get<0>(s.at(i)) + get<1>(s.at(i)) + get<0>(s.at(i + 1)) + get<0>(s.at(i + 2));
				}
				else {
					somme += get<0>(s.at(i)) + get<1>(s.at(i)) + get<0>(s.at(i + 1)) + get<1>(s.at(i + 1));
				}
				
			}
			else {
				somme += get<0>(s.at(i)) + get<1>(s.at(i)) + get<0>(s.at(i + 1)) + get<1>(s.at(i + 1));
			}
		}
		somme += get<0>(s.at(i)) + get<1>(s.at(i));
		i++;
	}
	return somme;
}

void Game::addTuple(tuple<int, int> t)
{
	if (s.size() < 10 && get<0>(t)+get<1>(t) <= 10 && get<0>(t) >= 0 && get<0>(t) <= 10 && get<1>(t) >= 0 && get<0>(t) <= 10) {
		s.push_back(t);
	}
	else if (s.size() == 10 && get<0>(t) >= 0 && get<0>(t) <= 10 && get<1>(t) >= 0 && get<0>(t) <= 10) {
		if(get<0>(s.at(9)) + get<1>(s.at(9)) == 10)
			s.push_back(t);
	}

	return;
}
