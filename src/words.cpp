/*	Filename: words.cpp
 *	Developers: Micah Butler (princessjinifer)
 *				Lakshmipathi.G (Laks)
 *	Created: Sometime 2010
 * 	Edited: 2/1/2012
 *	It has no functionality, it does nothing useful, just has a few things mostly related to the game...
 *	v.0.2.0.1
*/

#include "words.h"

#define returnToMenu "press ENTER to get back to the menu"

// int main
string name;

// void play
string gcheck;
int guess;

// void list
string names;

// void random_chooser
int highn;

// the funtions used in the program
void body (string where_from);
void help ();
void play ();
void settings ();
void list ();
void credits ();
void you_win (int final_score, int incorrectGuess);
void highscores ();
void circleCalc ();

int random_chooser ()
{
	string hnum;
	int random_number;
	ifstream highnum ("number");
	if (highnum.is_open())
	{
		if ( highnum.good() )
		{
			getline (highnum,hnum);
		}
		highnum.close();
	}
	stringstream highn_str(hnum);
	highn_str >> highn;
	random_number = rand() % highn +1;
	return (random_number);
}

string password_check ()
{
	string password;
	
	ifstream secret_word ("password");
	if ( secret_word.is_open() )
	{
		if ( secret_word.good() )
		{
			getline (secret_word,password);
		}
		secret_word.close();
	}
	else
	{
		string file_error = "error";
		return (file_error);
	}
	return (password);
}

int main ()
{
	string returned_from = "name entry";
	
	cout << "What is your name? ";
	getline (cin, name);
	ofstream put_name ("names", ios::app);
	if (put_name.is_open())
	{
		put_name << name << endl;
		put_name.close();
	}
	system("clear");
	cout << "Why hello there " << name << ". Glad to see you!\n";
	cout << "Welcome to Words, the name is pretty lame, so think of a new one for me please?\n";
	body (returned_from);
}

void body (string where_from)
{
	string where_to, confirm_quit;

	cout << "Now that you have come from the " << where_from << ";\n";
	accident:
	cout << "Type your command here, anything not in the help will end the program\n";
	cout << "Type 'help' if you don't know any of the commands\n";
	cout << ": ";
	getline (cin, where_to);
	if (where_to == "help" || where_to == "Help" || where_to == "HELP")
	{
		help ();
	}
	if (where_to == "settings" || where_to == "Settings" || where_to == "SETTINGS")
	{
		settings ();
	}
	if (where_to == "list" || where_to == "List" || where_to == "LIST")
	{
		list ();
	}
	if (where_to == "play" || where_to == "Play" || where_to == "PLAY")
	{
		play ();
	}
	if (where_to == "credits" || where_to == "Credits" || where_to == "CREDITS")
	{
		credits ();
	}
	if (where_to == "highscores" || where_to == "Highscores" || where_to == "HIGHSCORES")
	{
		highscores ();
	}
	if (where_to == "circle" || where_to == "Circle" || where_to == "CIRCLE")
	{
		circleCalc ();
	}
	else
	{
		while (true)
		{
			cout << "Are you sure you want to quit? [yes(y)/no(n)] ";
			getline (cin, confirm_quit);
			if (confirm_quit == "yes" || confirm_quit == "Yes" || confirm_quit == "y" || confirm_quit == "Y")
			{
				exit (1);
			}
			if (confirm_quit == "no" || confirm_quit == "No" || confirm_quit == "n" || confirm_quit == "N")
			{
				system("clear");
				goto accident;
			}
			cout << "That is not one of my known commands, enter one of the given choices.\n";
		}
	}
}

void help ()
{
	string returned_from = "help";
	
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
	body (returned_from);
}

void settings ()
{
	string new_number, word, newword, change;
	string secretw = password_check ();
	string returned_from = "settings";

	if (secretw == "error")
	{
		cout << "Sorry there was a problem with the stored password file.\n";
		cout << returnToMenu;
		cin.get();
		system("clear");
		body (returned_from);
	}
	while (word != secretw)
	{
		system("clear");
		cout << "Password: ";
		getline (cin, word);
		system("clear");
	}
	cout << "Access Granted\n";
	while (true)
	{
		cout << "Please enter a number\n";
		cout << "1. Return to the program\n";
		cout << "2. Change the settings password\n";
		cout << "3. Change the high number for the guessing game\n";
		cout << ": ";
		getline (cin, change);
		if (change == "1")
		{
			system("clear");
			body (returned_from);
		}
		if (change == "2")
		{
			ofstream password ("password", ios::trunc);
			if (password.is_open())
			{
				cout << "Please enter the new password" << endl;
				getline (cin, newword);
				password << newword;
				password.close();
				system("clear");
				cout << "Password change successful" << endl;
			}
			else cout << "Sorry, there was an error opening the password file for editing";
		}
		if (change == "3")
		{
			ofstream number ("number", ios::trunc);
			if (number.is_open())
			{
				cout << "Please enter the new number" << endl;
				getline (cin, new_number);
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

void list ()
{
	string returned_from = "list of names";
	
	ifstream users ("names");
	if (users.is_open())
	{
		while ( users.good())
		{
			getline (users,names);
			cout << names << endl;
		}
		users.close();
	}
	else cout << "Unable to open file";
	cout << returnToMenu;
	cin.get();
	system("clear");
	body (returned_from);
}

void credits ()
{
	string returned_from = "credits";
	
	system("clear");
	cout << "Princessjinifer: Owner and main programmer http://goo.gl/i6qvk\n";
	cout << "Lakshmipathi.G: Main tester and secondary programmer http://www.giis.co.in/\n\n";
	cout << returnToMenu;
	cin.get();
	system("clear");
	body (returned_from);
}

void highscores ()
{
	string highscore;
	string returned_from = "highscores";

	ifstream show_scores ("highscores");
	if (show_scores.is_open())
	{
		while ( show_scores.good())
		{
			getline (show_scores,highscore);
			cout << highscore << endl;
		}
		show_scores.close();
	}
	else cout << "Unable to open file";
	cout << returnToMenu;
	cin.get();
	system("clear");
	body (returned_from);
}

void play ()
{
	int rando;
	rando = random_chooser ();

	system("clear");
	cout << "I have chosen a number between 1 and " << highn << ", you are going to take a guess and I will tell you if you are too high or too low...\n";
	int score=0;
	int incorrect_guess=0;
//	cout << rando << endl; // used for developer purposes only
	game:
	while (true)
	{
		cout << "Guess a number: ";
		getline (cin, gcheck);
		stringstream guessc(gcheck);
		if (guessc >> guess)
			break;
			cout << "Sorry, you have to guess a number\n";
			incorrect_guess++;
	}
	if (guess>highn)
	{
		cout << "Sorry, you have to guess a number between 1 and " << highn << endl;
		incorrect_guess++;
		goto game;
	}
	score++;
	if (guess==rando)
	{
		you_win (score, incorrect_guess);
	}
	if (guess<rando)
	{
		cout << "Your guess is too low, guess higher!\n";
	 	goto game;
	}
	if (guess>rando)
	{
		cout << "Your guess is too high, guess lower!\n";
	 	goto game;
	}
//	}
}

void you_win (int final_score, int incorrectGuess) // this is the procedure after the person has won the game :3
{
	string playagain;
	string returned_from = "game";

	cout << "You guessed correctly!\n"; // yay! you won!
	cout << "You guessed " << final_score << " times before winning o: I know you can do better than that!!\n";
	if (incorrectGuess > 0)
	{
		cout << "You guessed " << incorrectGuess << " words/blank guesses/numbers higher than " << highn << ", You should be a little more careful :P\n";
	}
	ofstream put_score ("highscores", ios::app);
	if (put_score.is_open())
	{
		put_score << name << "\t\t" << final_score << "\t\t" << incorrectGuess << endl;
		put_score.close();
	}
	while (true)
	{
		cout << "Play again? (y,n): ";
		getline (cin, playagain);
		if (playagain == "y")
		{
			play ();
		}
		if (playagain == "n")
		{
			system("clear");
			body (returned_from);
		}
		cout << "Sorry, you have to use either 'y' or 'n'...\n";
	}
}
