/*	Filename: upperCase.cpp
 *	Developers: Micah Butler (princessjinifer)
 *				Lakshmipathi.G (Laks)
 *	Created: 9/26/2012
 * 	Edited: 9/26/2012
 *	Changes all the names to uppercase, shortens some if statements
 *	v.0.2.1
*/

#include "words.h"

void upperCase(char *pWhereTo) {
	while (*pWhereTo) {
		if (islower(*pWhereTo)) {
			*pWhereTo = toupper(*pWhereTo);
		}
		*pWhereTo++;
	}
}

void processInput () {
	char *whereTo;
	char temp[10];
	
	while(true) {
		cout << "Type your command here, anything not in the help will end the program\n";
		cout << "Type 'help' if you don't know any of the commands\n";
		cout << ": ";
		cin >> temp;
		whereTo = temp;
		upperCase(whereTo);
		if (whereTo == "HELP") {
			help();
		} else if (whereTo == "SETTINGS") {
			settings();
		} else if (whereTo == "LIST") {
			list();
		} else if (whereTo =="PLAY") {
			play();
		} else if (whereTo == "CREDITS") {
			credits();
		} else if (whereTo == "HIGHSCORES") {
			highscores();
		} else if (whereTo == "CIRCLE") {
			circleCalc();
		} else if (whereTo == "EXIT" || whereTo == "QUIT") {
			exit(1);
		} else {
			system("clear");
			
			cout << "Sorry, but " << temp << " is not one of my known commands, enter help to see a list of\navailable choices.\n\n";
		}
	}
}
