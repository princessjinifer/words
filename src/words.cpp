/*	Filename: words.cpp
 *	Devs: Micah Butler (princessjinifer)
 *		  Lakshmipathi.G (Laks)
 *	Created: Sometime 2010
 * 	Edited: 5/9/2010
 *	It has no functionality, it does nothing useful, just has a few things mostly related to the game...
 *	v.0.2
*/

#include "words.h"

string name; // for the name exchange
string where_to; // getting around the program
string confirm_quit; // confirmation of quitting the program
string gcheck; // for checking the guess
int guess; // guessing the number in the game
int score; // how many guesses that you have made
int incorrect_guess; // how many times they guess something other than something in between 1 and highn
string word; // the password on the settings
string change; // in the settings, when it asks you what you want to do
string newword; // when choosing a new password in the settings
string secretw; // the password when entering the settings
string names; // extracts the names file to this
string hnum; // extraction of the number file
int highn; // used to generate the random number
int rando; // the random number
string playagain; // when you are asked if you want to play again
string highscore; // for displaying the highscores of the game

void quit (); // the part where the program kinda quits... idk... :D
void help (); // shows the help section
void game (); // explaining the game
void play (); // the actual game play
void settings (); // the settings for the program
void list (); // for showing the names of names
void credits (); // used for showing the credits
void extract (); // used for getting the number from the file
void random_range (); // getting the random number
void you_win (); // after you win the game, it takes you here
void highscores (); // the highscores for the game
void circle (); // the circle calculations :D

// extract is a cool name for it, but not a good one, this one needs changing too :/
void extract () // extracts the high number from the file
{
	ifstream highnum ("number"); // open the file
	if (highnum.is_open()) // if its open then:
	{
		if ( highnum.good() ) // idk exactly
		{
			getline (highnum,hnum); // get the file contents and make it the string hnum
		}
		highnum.close(); // closes teh file
	}
	stringstream highn_str(hnum);
	highn_str >> highn;
	random_range ();
}

void random_range ()
{
	srand(static_cast<unsigned int>(time(0)));
	// Thanks to Laks for fixing this part in my program, it really helps :)
	rando = rand() % highn +1;
	game ();
}

int main ()
{
	cout << "Please enter your name: "; // prints 'Please enter your name'
	getline (cin, name); // gets users name
	ofstream put_name ("names", ios::app); // opens the 'names' file for writing the name to it
	if (put_name.is_open())
	{
		put_name << name << endl; // writes the name to it
		put_name.close(); // closes it
	}
	cout << "Well hello there " << name << "!" << endl; // prints Hello 'name'!
	cout << "Welcome to words, the name is lame, so think up a new one for me pwease? :3" << endl; // That is a good idea XD
	quit ();
}

// I have no clue why I called this one quit, I need to change that in a future version, remind me?
void quit ()
{
	system("clear");
	// I need a better way to word this too, this will suffice for the time being, but I want my users to be less confused...
	accident:
	cout << "If you don't know what to do here, just type 'help' :D" << endl; // Lets start 'splainin
	cout << "Type something in, anything not mentioned in 'help' will end the program: "; // well?
	getline (cin, where_to); // type something
	if (where_to == "help" || where_to == "Help" || where_to == "HELP") // so you want to see the help?
	{
		help (); // takes you to the help section (so it can help you!) :D
	}
	if (where_to == "settings" || where_to == "Settings" || where_to == "SETTINGS") // Oh, so making a few adjustments?
	{
		settings (); // takes you to the settings section (so you can make this YOUR program XD)
	}
	if (where_to == "list" || where_to == "List" || where_to == "LIST") // Being nosey on who has used this XP
	{
		list (); // takes you to the list section (so you can see who all has used it)
	}
	if (where_to == "play" || where_to == "Play" || where_to == "PLAY") // lets play a game XD
	{
		extract (); // Oooh, that function sounds fun, take me there XD
	}
	if (where_to == "credits" || where_to == "Credits" || where_to == "CREDITS") // Now here is where it gives credit to everyone who has made it :)
	{
		credits ();
	}
	if (where_to == "highscores" || where_to == "Highscores" || where_to == "HIGHSCORES") // The highscores :3
	{
		highscores ();
	}
	if (where_to == "circle" || where_to == "Circle" || where_to == "CIRCLE")
	{
		circle ();
	}
	else // anything else entered
	{
		retry:
		cout << "Are you sure you want to quit? [yes(y)/no(n)] ";
		getline (cin, confirm_quit);
		if (confirm_quit == "yes" || confirm_quit == "Yes" || confirm_quit == "y" || confirm_quit == "Y")
		{
			exit (1); // kills the program >:D
		}
		if (confirm_quit == "no" || confirm_quit == "No" || confirm_quit == "n" || confirm_quit == "N")
		{
			system("clear");
			goto accident;
		}
		else
		{
			cout << "I do not recognize that, enter one of the given choices..." << endl;
			goto retry;
		}
	}
}

void help () // Here is the help
{
	cout << "Commands:\n";
	cout << "help: shows the help\n";
	cout << "settings: shows the settings of the program\n";
	cout << "list: shows a list of all the people who have used this\n";
	cout << "play: lets you play a number guessing game\n";
	cout << "credits: displays the credits!\n\n";
	cout << "circle: a circle calculator";
	// ^ thats alot, and I am still adding as I go o:
	cout << "Press ENTER to get back to the menu";
	cin.get();
	system("clear");
	quit (); // takes you back to the ending thingie
}

void settings () // the settings :D
{
	system("clear"); // clears the screen to start fresh
	tryagain: // here is when they might get the password wrong >:D
	cout << "Password: "; // So what is it?
	getline (cin, word); // is that right?
	ifstream sword ("word"); // lets check the file, first open it :)
	if (sword.is_open()) // then, once it opens, do this:
	{
		if ( sword.good() ) // while the secret word is, idk exactly what this means :P
		{
			getline (sword,secretw); // change it to secretw
		}
		sword.close(); // close teh file!!
	}
	else
	{
		cout << "Sorry there was a problem" << endl; // tell them there was a problem
		quit (); // head back to the body
	}
	if (word == secretw) // if what you entered up there ^ equals what we have here <
	{
		cout << "Access Granted" << endl; // you got it!!
		goto settings; // go to the fun stuff!! XD
	}
	else // otherwise, if your wrong
	{
		cout << "Access Denied" << endl; // BAHAHA, you failed!! >:D
		goto tryagain; // go back to the beginning and try again
	}
	settings: // here is where we actually do some editing
	cout << "Please enter a number" << endl << "1. Return to the program" << endl << "2. Change the settings password" << endl << "3. Change the high number for the guessing game" << endl << ": "; // explains what all you can do
	getline (cin, change); // get what they want
	if (change == "2") // if you want the 2nd one
	{
		ofstream word ("word", ios::trunc); // open our password file
		if (word.is_open()) // if its open
		{
			cout << "Please enter the new password" << endl; // then enter the new one
			getline (cin, newword); // get the new password
			word << newword; // and put it in our file
			word.close(); // close teh file
			system("clear"); // clears the screen
			cout << "Password change successful" << endl; // great job! you changed it, was it THAT hard?
			goto settings; // back to the fun stuff :)
		}
		else cout << "Unable to open file"; // cant open the file :(
	}
	if (change == "1") // if you chose the first one
	{
		system("clear"); // clear the screen
		quit (); // and get back to the, umm, other thing :P
	}
	if (change == "3") // if you want the 3rd one
	{
		ofstream number ("number", ios::trunc); // open the number file
		if (number.is_open()) // if its open
		{
			cout << "Please enter the new number" << endl; // type the new number
			getline (cin, hnum); // got it!
			number << hnum; // write it to the file
			number.close(); // close teh file
			system("clear"); // clears the screen
			cout << "Number was changed successfully" << endl; // good job!
			goto settings; // back to the fun stuff XD
		}
		else cout << "Unable to open file"; // sorry, can't open the file :(
	}
	else // otherwise
	{
		system("clear"); // clear the screen
		cout << "I'm sorry, but I don't recognize that, please enter a number from above..." << endl; // and tell you I don't recognize that :/
		goto settings; // go back to the fun stuff
	}
}

void list () // lets show who all has used it...
{
	ifstream users ("names"); // open the file
	if (users.is_open()) // if its open then:
	{
		while ( users.good() ) // idk exactly
		{
			getline (users,names); // get the file contents
			cout << names << endl; // and display them all here
		}
		users.close(); // close teh file
	}
	else cout << "Unable to open file"; // sorry, cannot open that one either :(
	cout << "press ENTER to get back to the menu";
	cin.get();
	system("clear");
	quit (); // back to the main thingy
}

void credits () // here are the cool people
{
	system("clear"); // clear the screen
	cout << "Princessjinifer: Owner and main programmer http://goo.gl/i6qvk" << endl << "Lakshmipathi.G: Main tester and secondary programmer http://www.giis.co.in/" << endl; // yup yup!
	quit (); // the main thingy again
}

void highscores () // here you get to see how well you have been doing :)
{
	ifstream show_scores ("highscores"); // open the file
	if (show_scores.is_open()) // if its open then:
	{
		while ( show_scores.good() ) // idk exactly
		{
			getline (show_scores,highscore); // get the file contents
			cout << highscore << endl; // and display them all here
		}
		show_scores.close(); // close teh file
	}
	else cout << "Unable to open file"; // sorry, cannot open that one either :(
	cout << "press ENTER to get back to the menu";
	cin.get();
	system("clear");
	quit (); // back to the main thingy
}

void game () // now for the fun stuff!!
{
	system("clear"); // clear the screen
	cout << "I have chosen a number between 1 and " << hnum << ", you are going to take a guess and I will tell you if you are too high or too low..." << endl; // some 'splainin
	play (); // now it starts...
}

void play () // the part where you actually play
{
//	cout << rando << endl; // used for developer purposes only
	score=0;
	incorrect_guess=0;
//	cout << score;
	game: // starts teh game, FINALLY!!!
//	cout << score << endl; // used for developer purposes only
//	cout << incorrect_guess << endl; // used for developer purposes only
	while (true) // this is a while loop, 
	{
	cout << "Guess a number: "; // prints Guess a number
	getline (cin, gcheck); // the player guesses
	stringstream guessc(gcheck); // and it converts it to something else
/*	if (guess=="^d") // still working on this
	{
		exit (1); // Kills it >:D
	}*/
	if (guessc >> guess) // idk where guess came from, cause I don't see where they input to it...
		break; // belongs with the 'while (true)' statement up there
		cout << "Sorry, you have to guess a number" << endl; // Sorry, that's not a number
		incorrect_guess++;
	}
	if (guess>highn) // is it bigger than 100?
	{
		incorrect_guess++;
		cout << "Sorry, you have to guess a number between 1 and " << highn << endl; // then sorry, it has to be lower
		goto game; // go back to the start of the game
	}
	score++; // increases their guess count by 1
	if (guess==rando) // are you correct?
	{
		you_win ();
	}
	if (guess<rando) // is it smaller than the chosen number?
	{
		cout << "Your guess is too low, guess higher!" << endl; // guess higher!
	 	goto game; // goes to teh beginning
	}
	if (guess>rando) // is it bigger than the chosen number?
	{
		cout << "Your guess is too high, guess lower!" << endl; // nope, guess lower
	 	goto game; // goes back to the beginning
	}
}

void you_win () // this is the procedure after the person has won the game :3
{
	cout << "You guessed correctly!" << endl; // yay! you won!
	cout << "You guessed " << score << " times before winning o: I know you can do better than that!!" << endl;
	cout << "You guessed " << incorrect_guess << " words/blank guesses/numbers higher than " << highn << ", You should be a little more careful :P" << endl;
	ofstream put_score ("highscores", ios::app); // opens the 'names' file for writing the name to it
	if (put_score.is_open())
	{
		put_score << name << "\t\t" << score << "\t\t" << incorrect_guess << endl; // writes the name to it
		put_score.close(); // closes it
	}
	play_again:
	cout << "Play again? (y,n): "; // do you want to play again?
	getline (cin, playagain); // yes or no?
	if (playagain=="y") // good, let's play
	{
		extract (); // go back to the beginning of the game section
	}
	if (playagain=="n") // ok, play again soon! :)
	{
		system("clear");
		quit (); // goes to the thingie :P
	}
	else // yeppity yep
	{
		cout << "Sorry, you have to use either 'y' or 'n'..." << endl;
		goto play_again;
	}
}
