#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

//Function prototype
int random();

//Main function
int main() {
	//Integers
	int index;
	int tally = 1;
	int matchNum = 0;
	
	//Constant
	const int MAX_AMOUNT = 8;
	
	//Arrays
	int matchup[MAX_AMOUNT];
	string contestants[] = { "Son Goku", "Krillin", "Nam", "Giran", "Ranfan", "Yamcha", "Jackie Chun", "Bacterian" };
	int matchNumCheck[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	
	//PRNG Setup
	unsigned seed = static_cast<unsigned int>(time(0));
	srand(seed);

	//Loop to fill the matchup array
	for (index = 0; index < MAX_AMOUNT; index++) {

		matchup[index] = random();
		matchNum = matchup[index];
		//Nested loop to check for any repeating numbers
		for (int check = 0; check < MAX_AMOUNT; check++) {
			//This statement checks for a matching number and removes it 
			//from the matchNumCheck array and breaks the loop
			if (matchNum == matchNumCheck[check]) {
				matchNumCheck[check] = MAX_AMOUNT;
				if (matchNum != MAX_AMOUNT) {
					break;
				}				
			}
			//This statement rolls back the original loop counter
			//by 1 if it fails to find a matching number in the
			//matchNumCheck array
			if (matchNum != matchNumCheck[matchNum]) {
				index--;
				break;
			}
		}
	}
	//Loop to output the contestants array
	for (index = 0; index < MAX_AMOUNT; index++) {
		matchNum = matchup[index];
		cout << contestants[matchNum] << endl;
		//This statement checks if 2 have been printed
		//and adds an extra line break to separate them
		//from the next pair of printed names
		if (tally == index) {
			cout << endl;
			tally += 2;
		}
	}
	return 0;
}

//PRNG function
int random() {
	const int MIN_VALUE = 0;
	const int MAX_VALUE = 7;
	int match;

	match = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	return match;
}
