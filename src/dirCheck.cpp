/*	Filename: dirCheck.cpp
 *	Developers: Micah Butler (princessjinifer)
 *				Lakshmipathi.G (Laks)
 *	Created: 9/22/2012
 * 	Edited: 9/22/2012
 *	Checks to see if the user is in the correct directory.
 *	v.0.2.0.1.1
*/

#include "words.h"

//bool directoryCheck();

bool directoryCheck() {
	ifstream highNumberFile("number");
	if (highNumberFile.is_open()) {
		return true;
	} else {
		return false;
	}
}
