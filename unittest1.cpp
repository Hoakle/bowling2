#include "game.h"
#include <assert.h> 
#include <vector>
#include <tuple>
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
	
	{	//Test du constructeur
		typedef vector<tuple<int, int>> score;
		score tl;
		tl.push_back(tuple<int, int>(1,1));
		tl.push_back(tuple<int, int>(2, 2));
		Game game = Game(tl);
		assert(tl == game.s);
		Game game2 = Game();
		score t2;
		assert(t2 == game2.s);
	}
	{
		typedef vector<tuple<int, int>> score;
		score tl;
		tl.push_back(tuple<int, int>(1, 1));
		tl.push_back(tuple<int, int>(2, 2));
		Game game = Game(tl);
		assert(6 == game.calculScore());
		
		game.addTuple(tuple<int, int>(10, 0));
		game.addTuple(tuple<int, int>(1, 1));
		assert(game.s.size() == 4);
		assert(20 == game.calculScore());
		
		game.addTuple(tuple<int, int>(10, 0));
		game.addTuple(tuple<int, int>(10, 0));
		game.addTuple(tuple<int, int>(10, 0));
		assert(80 == game.calculScore());
		
		game.s.clear();
		game.addTuple(tuple<int, int>(2, 8));
		game.addTuple(tuple<int, int>(5, 5));
		game.addTuple(tuple<int, int>(5, 0));
		assert(35 == game.calculScore());
		
		game.s.clear();
		game.addTuple(tuple<int, int>(10, 0));
		game.addTuple(tuple<int, int>(10, 0));
		game.addTuple(tuple<int, int>(10, 0));
		game.addTuple(tuple<int, int>(10, 0));
		game.addTuple(tuple<int, int>(10, 0));
		game.addTuple(tuple<int, int>(10, 0));
		game.addTuple(tuple<int, int>(10, 0));
		game.addTuple(tuple<int, int>(10, 0));
		game.addTuple(tuple<int, int>(10, 0));
		game.addTuple(tuple<int, int>(10, 0));
		game.addTuple(tuple<int, int>(10, 10));
		assert(300 == game.calculScore());
	}
	{
		typedef vector<tuple<int, int>> score;
		score tl;
		tl.push_back(tuple<int, int>(1, 1));
		tl.push_back(tuple<int, int>(2, 2));
		Game game = Game(tl);
		game.addTuple(tuple<int, int>(1, 1));
		game.addTuple(tuple<int, int>(-2, 2));
		assert(3 == game.s.size());
		
		game.addTuple(tuple<int, int>(1, 1));
		game.addTuple(tuple<int, int>(12, 2));
		assert(4 == game.s.size());
		
		game.addTuple(tuple<int, int>(1, 1));
		game.addTuple(tuple<int, int>(2, 9));
		assert(5 == game.s.size());
		
		game.addTuple(tuple<int, int>(1, 1));
		game.addTuple(tuple<int, int>(2, 2));
		game.addTuple(tuple<int, int>(1, 1));
		game.addTuple(tuple<int, int>(2, 2));
		game.addTuple(tuple<int, int>(2, 2));
		game.addTuple(tuple<int, int>(2, 2));
		assert(10 == game.s.size());
		
		game.s.pop_back();
		game.addTuple(tuple<int, int>(10, 0));
		game.addTuple(tuple<int, int>(2, 2));
		assert(11 == game.s.size());
		
		game.s.pop_back();
		game.s.pop_back();
		game.addTuple(tuple<int, int>(5, 5));
		game.addTuple(tuple<int, int>(2, 2));
		assert(10 == game.s.size());
		
		game.addTuple(tuple<int, int>(2, 0));
		assert(11 == game.s.size());
	}
	return 0;
}