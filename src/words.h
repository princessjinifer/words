/*	Filename: words.h
 *	Developers: Micah Butler (princessjinifer)
 *				Lakshmipathi.G (Laks)
 *	Created: Sometime 2011
 *	Edited: 2/1/2012
 *	It has no functionality, it does nothing useful, just has a few things mostly related to the game...
 *	v.0.2.0.1
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

// void play

extern string gcheck; // for checking the guess
extern int guess; // guessing the number in the game

// void list

extern string names; // extracts the names file to this

// void random_chooser

extern int highn; // used to generate the random number

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
