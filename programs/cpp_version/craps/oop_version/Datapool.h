//
// Created by Alec Moran on 12/30/21.
//

#ifndef DATAPOOL_H
#define DATAPOOL_H

#include "Player.h"
#include <vector>

class Datapool{
	public:
		int numPlayers;
		double goalRatio;
		int startingCash;
		int goalCash;
		enum betType{
			passLine, dontPass, fieldDouble, fieldTriple, anySeven, anyCraps, comeOnly, dontCome
		};
		int strategyInt;
		static bool allGameResults[];
		int numWins;
		int numLosses;
		static int numBets;
		double winRatio;
		vector<int> allRolls;
		int numRolls[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
		int totalNumRolls = 0;
		double rollPercentage[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
		double distAccuracy;


		Datapool(int numPlayers, int startingCash, double goalRatio, int strategyInt);

		void gatherPlayerData();

		void analyzeDiceData();

		void printResults();


};

#endif //DATAPOOL_H
