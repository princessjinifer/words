/*	Filename: dirCheck.cpp
 *	Developers: Micah Butler (princessjinifer)
 *				Lakshmipathi.G (Laks)
 *	Created: 9/23/2012
 * 	Edited: 3/14/2013
 *	Checks to see if the user is in the correct directory.
 *	v.0.2.1
*/

#include "words.h"

string homeFolder(string fileName);

bool storedAtHome = false;

bool fileChecking(string filename) {
	string filePath = homeFolder(filename);
	ifstream numberFileHome(filePath.c_str());
	bool fileExists = (numberFileHome.is_open());
	numberFileHome.close();
	return fileExists;
}

bool directoryCheck() {
	// variables for global file checks
	bool fileOneHome = fileChecking("number"); // checking number file
	bool fileTwoHome = fileChecking("names"); // checking names file
	bool fileThreeHome = fileChecking("highscores"); // checking highscores file
	bool fileFourHome = fileChecking("password"); // checking password file
		
	// checking results
	if ((fileOneHome) && (fileTwoHome) && (fileThreeHome) && (fileFourHome)) {
		storedAtHome = true;
		return storedAtHome;
	} else {
		// variables for local file checks
		bool fileOneLocal = fileChecking("number"); // checking number file
		bool fileTwoLocal = fileChecking("names"); // checking names file
		bool fileThreeLocal = fileChecking("highscores"); // checking highscores file
		bool fileFourLocal = fileChecking("password"); // checking password file
		
		// checking results
		if ((fileOneLocal) && (fileTwoLocal) && (fileThreeLocal) && (fileFourLocal)) {
			return true;
		} else {
			return false;
		}
	}
}
