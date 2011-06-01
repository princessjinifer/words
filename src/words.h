/*	First c++ program
 *	Micah Butler (princessjinifer)
 *	Lakshmipathi.G (Laks)
 *	Sometime 2010
 *	It has no functionality, it does nothing useful, just has a few things mostly related to the game...
 *	v.0.2
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <math.h>

using namespace std;

// int main

extern string name; // for the name exchange

// void quit

extern string where_to; // getting around the program
extern string confirm_quit; // confirmation of quitting the program

// void play

extern string gcheck; // for checking the guess
extern int guess; // guessing the number in the game
extern int score; // how many guesses that you have made
extern int incorrect_guess; // how many times they guess something other than something in between 1 and highn

// void settings

extern string word; // the password on the settings
extern string change; // in the settings, when it asks you what you want to do
extern string newword; // when choosing a new password in the settings
extern string secretw; // the password when entering the settings

// void list

extern string names; // extracts the names file to this

// void extract

extern string hnum; // extraction of the number file

// void random_range

extern int highn; // used to generate the random number
extern int rando; // the random number

// void you_win

extern string playagain; // when you are asked if you want to play again

// void highscores

extern string highscore; // for displaying the highscores of the game

// ccalc.cpp

extern string measurement_type;
extern string another_one;
extern float measurement_length;
extern float measurement_length_diameter;
extern float measurement_length_circumference;
extern float measurement_length_radius;
extern float measurement_length_area;
