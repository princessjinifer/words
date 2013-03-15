/*	Filename: words.cpp
 *	Developers: Micah Butler (princessjinifer)
 *				Lakshmipathi.G (Laks)
 *	Created: Sometime 2010
 * 	Edited: 3/14/2013
 *	It has no functionality, it does nothing useful, just has a few things mostly related to the game...
 *	v.0.2.1.1
*/

#include "words.h"

#define returnToMenu "press ENTER to get back to the menu"

// global variables
string versionNumber = "-0.2.1.1";
string home = getenv("HOME");
string name; // the users name is stored here
int highNumberInt; // the high number of "guess the number between 1 and __"

// the funtions used throughout the program
void upperCase(char *pWhereTo);
void body(string whereFrom);
void help();
void play();
void settings();
void list();
void credits();
void youWin(int finalScore, int incorrectGuess);
void highscores();
void circleCalc();
bool directoryCheck();
void processInput();

string homeFolder(string fileName) {
	string dataDir = "/.words/";
	string finalDir;
	finalDir += home;
	finalDir += dataDir;
	finalDir += fileName;
	
	return finalDir;
}

string fileLocations (string fileName) {
	if (storedAtHome) {
		return homeFolder(fileName);
	} else {
		return fileName;
	}
}

int random_chooser() {
	string highNumberString;
	string filePath = fileLocations("number");
	int randomNumber;
	
	ifstream highNumberFile(filePath.c_str());
	if (highNumberFile.is_open()) {
		if (highNumberFile.good()) {
			getline(highNumberFile,highNumberString);
		}
		highNumberFile.close();
	}
	stringstream ssHighNumberString(highNumberString);
	ssHighNumberString >> highNumberInt;
	randomNumber = rand() % highNumberInt +1;
	return (randomNumber);
}

string password_check() {
	string password;
	string filePath = fileLocations("password");
	
	ifstream secretWord(filePath.c_str());
	if (secretWord.is_open()) {
		if (secretWord.good()) {
			getline(secretWord,password);
		}
		secretWord.close();
	} else {
		string file_error = "error";
		return (file_error);
	}
	return (password);
}

int main() {
	//bool dirCheck;
	bool dirCheck = directoryCheck();
	if (!dirCheck) {
		cout << "ERROR (Code 2). move to the bin directory in the words" << versionNumber << " and then start\nthe program again, or copy the four data files (found in the words" << versionNumber << "\ndirectory you downloaded) in to the same folder that you moved the executable\nto.\n";
		cout << "If the error still occurs, contact princessjinifer@gmail.com or just download\nthe program again.\n";
		exit(1);
	}
	srand(time(NULL));

	string filePath = fileLocations("names");

//	cout << filePath << "\n"; // Developer use only

	string returnedFrom = "name entry";
	
	cout << "What is your name? ";
	getline(cin, name);
	ofstream put_name(filePath.c_str(), ios::app);
	if (put_name.is_open()) {
		put_name << name << endl;
		put_name.close();
	}
	system("clear");
	cout << "Why hello there " << name << ". Glad to see you!\n";
	cout << "Welcome to Words, the name is pretty lame, so think of a new one for me please?\n";
	body(returnedFrom);
}

void body(string whereFrom) {
	string whereTo;

	cout << "you have come from the " << whereFrom << ";\n";
	
//	processInput(); // Work in progress.
	
	while(true) {
		cout << "Type your command here, anything not in the help will end the program\n";
		cout << "Type 'help' if you don't know any of the commands\n";
		cout << ": ";
		getline(cin, whereTo);
		if (whereTo == "help" || whereTo == "Help" || whereTo == "HELP") {
			help();
		}
		if (whereTo == "settings" || whereTo == "Settings" || whereTo == "SETTINGS") {
			settings();
		}
		if (whereTo == "list" || whereTo == "List" || whereTo == "LIST") {
			list();
		}
		if (whereTo == "play" || whereTo == "Play" || whereTo == "PLAY") {
			play();
		}
		if (whereTo == "credits" || whereTo == "Credits" || whereTo == "CREDITS") {
			credits();
		}
		if (whereTo == "highscores" || whereTo == "Highscores" || whereTo == "HIGHSCORES") {
			highscores();
		}
		if (whereTo == "circle" || whereTo == "Circle" || whereTo == "CIRCLE") {
			circleCalc();
		}
		if (whereTo == "exit" || whereTo == "Exit" || whereTo == "EXIT" || whereTo == "quit" || whereTo == "Quit" || whereTo == "QUIT") {
			exit(1);
		} else {
			system("clear");
			
			cout << "Sorry, but " << whereTo << " is not one of my known commands, enter one of the given choices.\n\n";
		}
	}
}

void help() {
	string returnedFrom = "help";
	
	cout << "Commands:\n";
	cout << "help: displays this list of commands\n";
	cout << "settings: edit the settings of the program\n";
	cout << "list: shows a list of all the names that have been entered\n";
	cout << "play: a little number guessing game\n";
	cout << "credits: the people who have contributed to writing this\n";
	cout << "circle: used to calculate the different parts of a circle\n\n";
	cout << returnToMenu;
	cin.get();
	system("clear");
	body(returnedFrom);
}

void settings() {
	int change;
	string new_number, word, newword;
	string secretw = password_check();
	string returnedFrom = "settings";
	string filePath;

	if (secretw == "error") {
		cout << "Error (Code 1). Problem with password file. Email princessjinifer@gmail.com for a fix\n";
		cout << returnToMenu;
		cin.get();
		system("clear");
		body(returnedFrom);
	}
	while (word != secretw) {
		system("clear");
		cout << "Password: ";
		getline(cin, word);
		system("clear");
	}
	cout << "Access Granted\n";
	while (true) {
		cout << "Enter a number\n";
		cout << "1. Return to the program\n";
		cout << "2. Change the settings password\n";
		cout << "3. Change the high number for the guessing game\n";
		cout << ": ";
		cin >> change;
		if (change == 1) {
			system("clear");
			body(returnedFrom);
		}
		if (change == 2) {
			filePath = fileLocations("password");
			ofstream password(filePath.c_str(), ios::trunc);
			if (password.is_open()) {
				cout << "Please enter the new password" << endl;
				getline(cin, newword);
				password << newword;
				password.close();
				system("clear");
				cout << "Password change successful" << endl;
			} else cout << "Sorry, there was an error opening the password file";
		}
		if (change == 3) {
			filePath = fileLocations("number");
			ofstream number(filePath.c_str(), ios::trunc);
			if (number.is_open()) {
				cout << "Please enter the new number" << endl;
				getline(cin, new_number);
				number << new_number;
				number.close();
				system("clear");
				cout << "Number was changed successfully" << endl;
			}
			else cout << "Unable to open file";
		}
		system("clear");
		cout << "I'm sorry, but I don't recognize that, please enter a number from above." << endl;
    }
}

void list () {
	string names;
	string returnedFrom = "list of names";
	string filePath = fileLocations("names");
	
	ifstream usersFile(filePath.c_str());
	if (usersFile.is_open()) {
		while (usersFile.good()) {
			getline(usersFile,names);
			cout << names << endl;
		}
		usersFile.close();
	}
	else cout << "Unable to open file";
	cout << returnToMenu;
	cin.get();
	system("clear");
	body(returnedFrom);
}

void credits() {
	string returnedFrom = "credits";
	
	system("clear");
	cout << "Princessjinifer: Owner and main programmer http://goo.gl/uj0E4\n";
	cout << "Lakshmipathi.G: Main tester and secondary programmer http://www.giis.co.in/\n\n";
	cout << returnToMenu;
	cin.get();
	system("clear");
	body(returnedFrom);
}

void highscores() {
	string highscore;
	string returnedFrom = "highscores";
	string filePath = fileLocations("highscores");

	ifstream showHighscores(filePath.c_str());
	if (showHighscores.is_open()) {
		while (showHighscores.good()) {
			getline(showHighscores,highscore);
			cout << highscore << endl;
		}
		showHighscores.close();
	} else cout << "Unable to open file";
	cout << returnToMenu;
	cin.get();
	system("clear");
	body(returnedFrom);
}

void play() {
	int rando, guess;
	rando = random_chooser();
	int score=0;
	int incorrectGuess=0;
	string intGuessCheck;

	system("clear");
	cout << "I have chosen a number between 1 and " << highNumberInt << ", you are going to take a guess and I will tell you if you are too high or too low...\n";
	while(true) {
		while (true) {
			cout << "Guess a number: ";
			getline(cin, intGuessCheck);
			stringstream ssGuessCheck(intGuessCheck);
			if (ssGuessCheck >> guess) {
				break;
			}
				cout << "Sorry, you have to guess a number\n";
				incorrectGuess++;
		}
		score++;
		if (guess==rando) {
			youWin(score, incorrectGuess);
			break;
		}
		if (guess<rando) {
			cout << "Your guess is too low, guess higher!\n";
		}
		if (guess>rando) {
			if (guess > highNumberInt) {
				cout << "Sorry, you have to guess a number between 1 and " << highNumberInt << endl;
				incorrectGuess++;
			} else {
				cout << "Your guess is too high, guess lower!\n";
			}
		}
	}
}

void youWin(int finalScore, int incorrectGuess) {
	string playagain;
	string returnedFrom = "game";
	string filePath = fileLocations("highscores");

	cout << "You guessed correctly!\n";
	cout << "You guessed " << finalScore << " times before winning o: I know you can do better than that!!\n";
	if (incorrectGuess > 0) {
		cout << "You guessed " << incorrectGuess << " words/blank guesses/numbers higher than " << highNumberInt << ", You should be a little more careful :P\n";
	}
	ofstream putScore(filePath.c_str(), ios::app);
	if (putScore.is_open()) {
		putScore << name << "\t\t" << finalScore << "\t\t" << incorrectGuess << endl;
		putScore.close();
	}
	while (true) {
		cout << "Play again? (y,n): ";
		getline(cin, playagain);
		if (playagain == "y") {
			play();
			break;
		}
		if (playagain == "n") {
			system("clear");
			body(returnedFrom);
			break;
		}
		cout << "Sorry, you have to use either 'y' or 'n'...\n";
	}
}
