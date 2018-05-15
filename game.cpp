#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "game.h"
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
				if(i+1<s.size()) {
					if (get<0>(s.at(i + 1)) == 10) {
						if(i+2<s.size()) {
							somme += get<0>(s.at(i)) + get<1>(s.at(i)) + get<0>(s.at(i + 1)) + get<0>(s.at(i + 2));
						} else if(i == 9){
							somme += get<0>(s.at(i)) + get<1>(s.at(i)) + get<0>(s.at(i + 1)) + get<1>(s.at(i + 1));
						} else {
							somme += get<0>(s.at(i)) + get<1>(s.at(i)) + get<0>(s.at(i + 1));
						}
					}
					else {
						somme += get<0>(s.at(i)) + get<1>(s.at(i)) + get<0>(s.at(i + 1)) + get<1>(s.at(i + 1));
					}
				} else {
					somme += get<0>(s.at(i)) + get<1>(s.at(i));
				}
			}
			else {
				somme += get<0>(s.at(i)) + get<1>(s.at(i)) + get<0>(s.at(i + 1));
			}
		} else {
			somme += get<0>(s.at(i)) + get<1>(s.at(i));
		}
		i++;
	}
	return somme;
}

void Game::addTuple(tuple<int, int> t)
{
	/*if(s.size() == 10) {
		if(get<0>(s.at(s.size()-1)) == 10) {
			s.push_back(t);
		}
		if(get<0>(s.at(s.size()-1)) + get<1>(s.at(s.size()-1)) == 10) {
			cout << "tuple pushed" << endl;
			s.push_back(t);
		}
	}*/
	//cout << "We have : " << get<0>(t) << " & " << get<1>(t) << endl;
	if (s.size() < 10 && get<0>(t)+get<1>(t) <= 10 && get<0>(t) >= 0 && get<0>(t) <= 10 && get<1>(t) >= 0 && get<0>(t) <= 10) {
		s.push_back(t);
	}
	else if (s.size() == 10 && get<0>(t) >= 0 && get<0>(t) <= 10 && get<1>(t) >= 0 && get<0>(t) <= 10) {
		if(get<0>(s.at(s.size()-1)) == 10){
			if(get<0>(t) == 10) {
				s.push_back(t);
			} else if(get<0>(t) + get<1>(t) <= 10){
				s.push_back(t);
			}

		} else if(get<0>(s.at(s.size()-1)) + get<1>(s.at(s.size()-1))){
			if(get<1>(t) == 0){
				s.push_back(t);
			}
		}
	}

	return;
}
