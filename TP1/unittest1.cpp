//#include "CppUnitTest.h"
#include "game.h"
#include <assert.h> 
#include <vector>
#include <tuple>
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

int main(){
	typedef vector<tuple<int, int>> score;
	score tl;
	tl.push_back(tuple<int, int>(1,1));
	tl.push_back(tuple<int, int>(2, 2));
	Game game = Game(tl);
	assert(tl == game.s);
	Game game2 = Game();
	score t2;
	assert(t2 == game2.s);
	cout << "passed" << endl;
	return 0;
}

/*namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(_GameInit)
		{
			// TODO: Ici, votre code de test
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

		TEST_METHOD(CalculScore)
		{
			typedef vector<tuple<int, int>> score;
			score tl;
			tl.push_back(tuple<int, int>(1, 1));
			tl.push_back(tuple<int, int>(2, 2));
			Game game = Game(tl);
			Assert::IsTrue(6 == game.calculScore());
			game.addTuple(tuple<int, int>(10, 0));
			game.addTuple(tuple<int, int>(1, 1));
			Assert::IsTrue(20 == game.calculScore());
			game.addTuple(tuple<int, int>(10, 0));
			game.addTuple(tuple<int, int>(10, 0));
			game.addTuple(tuple<int, int>(10, 0));
			//test
			Assert::IsTrue(80 == game.calculScore());
			game.s.clear();
			game.addTuple(tuple<int, int>(2, 8));
			game.addTuple(tuple<int, int>(5, 5));
			game.addTuple(tuple<int, int>(5, 0));
			Assert::IsTrue(45 == game.calculScore());
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
			game.addTuple(tuple<int, int>(10, 0));
			game.addTuple(tuple<int, int>(10, 10));
			Assert::IsTrue(300 == game.calculScore());
		}
		TEST_METHOD(AddTuple) {
			typedef vector<tuple<int, int>> score;
			score tl;
			tl.push_back(tuple<int, int>(1, 1));
			tl.push_back(tuple<int, int>(2, 2));
			Game game = Game(tl);
			game.addTuple(tuple<int, int>(1, 1));
			game.addTuple(tuple<int, int>(-2, 2));
			Assert::IsTrue(3 == game.s.size());
			game.addTuple(tuple<int, int>(1, 1));
			game.addTuple(tuple<int, int>(12, 2));
			Assert::IsTrue(4 == game.s.size());
			game.addTuple(tuple<int, int>(1, 1));
			game.addTuple(tuple<int, int>(2, 9));
			Assert::IsTrue(5 == game.s.size());
			game.addTuple(tuple<int, int>(1, 1));
			game.addTuple(tuple<int, int>(2, 2));
			game.addTuple(tuple<int, int>(1, 1));
			game.addTuple(tuple<int, int>(2, 2));
			game.addTuple(tuple<int, int>(2, 2));
			game.addTuple(tuple<int, int>(2, 2));
			Assert::IsTrue(10 == game.s.size());
			game.s.pop_back();
			game.addTuple(tuple<int, int>(10, 0));
			game.addTuple(tuple<int, int>(2, 2));
			Assert::IsTrue(11 == game.s.size());
			game.s.pop_back();
			game.s.pop_back();
			game.addTuple(tuple<int, int>(5, 5));
			game.addTuple(tuple<int, int>(2, 2));
			Assert::IsTrue(11 == game.s.size());
		}
	};
}*/