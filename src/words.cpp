/*	Filename: words.cpp
 *	Developers: Micah Butler (princessjinifer)
 *				Lakshmipathi.G (Laks)
 *	Created: Sometime 2010
 * 	Edited: 9/22/2012
 *	It has no functionality, it does nothing useful, just has a few things mostly related to the game...
 *	v.0.2.0.1.1
*/

#include "words.h"

#define returnToMenu "press ENTER to get back to the menu"

// int main()
string name;

// void play()
int guess;

// void list()
string names;

// void random_chooser()
int highNumberInt;

// the funtions used throughout the program
void body(string whereFrom);
void help();
void play();
void settings();
void list();
void credits();
void youWin(int finalScore, int incorrectGuess);
void highscores();
void circleCalc();

int random_chooser() {
	string highNumberString;
	int randomNumber;
	
	ifstream highNumberFile("number");
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
	
	ifstream secret_word("password");
	if (secret_word.is_open()) {
		if (secret_word.good()) {
			getline(secret_word,password);
		}
		secret_word.close();
	} else {
		string file_error = "error";
		return (file_error);
	}
	return (password);
}

int main() {
	srand(time(NULL));
	string returnedFrom = "name entry";
	
	cout << "What is your name? ";
	getline(cin, name);
	ofstream put_name("names", ios::app);
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
	string whereTo, confirm_quit;

	cout << "you have come from the " << whereFrom << ";\n";
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
			ofstream password("password", ios::trunc);
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
			ofstream number("number", ios::trunc);
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
		cout << "I'm sorry, but I don't recognize that, please enter a number from above..." << endl;
    }
}

void list () {
	string returnedFrom = "list of names";
	
	ifstream usersFile("names");
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

	ifstream showHighscores("highscores");
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
	int rando;
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

	cout << "You guessed correctly!\n";
	cout << "You guessed " << finalScore << " times before winning o: I know you can do better than that!!\n";
	if (incorrectGuess > 0) {
		cout << "You guessed " << incorrectGuess << " words/blank guesses/numbers higher than " << highNumberInt << ", You should be a little more careful :P\n";
	}
	ofstream putScore("highscores", ios::app);
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
