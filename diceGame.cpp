/*
 * Zayd Haque
 * 9/25/16
 * Project Dice game
 * The program will feature a simulation of casino gambling which puts the player vs the house(Computer)
 *
 */

#include <iostream> // used for input/output
#include <string> // string class 
#include <fstream> // used for input/ output for a file
#include <cstdlib> // random number generator 
#include <ctime> 

using namespace std;

int main(){
	
	// variable declarations

	string playerName; // player's name
	
	cout << "Player please enter your name: "; // prompt for user input of their name
	cin >> playerName;
	
	// outputting the rules

	cout << "\t \t  WELCOME!, " << playerName << " This is the dice game \t \t" << endl;
	cout << "The rules: the player tosses a pair of dice then depending on the sum, the winner will be decided, " << endl;
	cout << "\t \t if the roll = 2, 3, 12, the HOUSE WINS!" << endl;
	cout << "\t \t if the roll = 7 or 11,  " << playerName << " WINS!" << endl;
	cout << "\t \t if the roll = 4, 5, 6, 8,9, or 10, the GAME CONTINUES. "<< endl; 
	cout << "\t \t then if the GAME CONTINUES, the intial toss becomes the target value" << endl;
	cout << "\t \t " << playerName << " will continue to roll the dice until the target value is matched or hits 7," << endl;
	cout << "\t \t if target value is met then  " << playerName << " WINS!" << endl;
	cout << " \t \t if one of the rolls hits 7 before the target then the HOUSE WINS!" << endl;
	cout << "The game will begin. \n \n" << endl;

	// die1 and die2 will be a random number between 1 and 6 
	srand(time(0));
	 
	int die1, die2;
	die1 = (rand()% 6 + 1);
	die2 = (rand()% 6 + 1);

	// cout << die1 << " and " << die2 << endl; used this to test to make sure the RNG was working

	int targetValue = die1 + die2;

	// this will open a file to write the game data to

	ofstream outPutFile;
	outPutFile.open("game.dat");

	outPutFile << die1 << endl;
	outPutFile << die2 << endl;

	
	// output the outcome after the first roll

	cout << playerName << " rolled " << die1 << " , " << die2 << " The sum is........ " << targetValue <<  endl;

	// if the roll = 2,3,12 the house wins

	if(targetValue == 2 || targetValue == 3 || targetValue == 12)

		cout << "\t \t THE HOUSE WINS!!!!!!!! \t \t " << endl;
	
	// if the roll = 7, 11 then the player wins 

	else if(targetValue == 7 || targetValue == 11)
	
		cout << playerName << "  WINS!!!!!!!!!!" << endl;

	// if the roll is anything else then it will enter this branch

	else if(targetValue == 4 || targetValue == 5 || targetValue == 6 || targetValue == 8 || targetValue == 9 || targetValue == 10)
	{
		cout << "\n \n THE GAME CONTINUES....." << endl;
		cout << "If the target value is met, " << playerName << " WINS!" << endl;
		cout << "If the roll's sum equals 7 then the HOUSE WINS!" << endl;

		// new set of dice for the future rounds

		int die3;
		int die4;

		int dieSum = 0;
		int round = 1;
		
			// if the diceSum does not equal 7 or the target value which is the intial roll's sum 
			// then it will roll the dice again and until the target value is met or 7 is met

			while (dieSum != targetValue && dieSum != 7)
				{
					die3 = (rand() % 6 + 1);
					die4 = (rand() % 6 + 1);
				
					dieSum = die3 + die4; 
					
					cout << " The dice rolled " << die3 << " , " << die4 << endl;

					// outputs the data if the roll to the file

					outPutFile << die3 << endl;
					outPutFile << die4 << endl;

					// updates the round

					++ round;
	
					// if the dice sum equals the target value then the player wins

						if (dieSum == targetValue){

						cout << "The dice rollled: " << die3 << " , " << die4 << " which is equal to " << dieSum << " !" << endl;
						cout << " CONGRATS!! " << playerName << "WINS! in round: " << round << endl;
						
						}

						else if (dieSum == 7){

					// if the dice sum = 7 then the house wins 

							cout << "The dice rollled: " << die3 << " , " << die4 << " which is equal to " << dieSum << " !" << endl;
							cout << " THE HOUSE WINS! in round: " << round << endl;

						}
				}
	}


	// closes the file 
	outPutFile.close();


	// end of the program
	return 0;
}