/*	Circle Calculator
 *	Micah Butler (princessjinifer)
 *	5-5-2011
 *	Calculates the radius, circumference and diameter depending on what the user inputs :)
 * 	Appended to words v.0.2
*/

#include "words.h"

#define PI 3.14

string measurement_type;
string another_one;
float measurement_length;
float measurement_length_diameter;
float measurement_length_circumference;
float measurement_length_radius;
float measurement_length_area;
float measurement_length_area_radius;

void area (); // calculating the diameter, circumference and radius
void radius (); // calculating the diameter, circumference and area
void diameter (); // calculating the circumference, radius and area
void circumference (); // calculating the diameter, radius and area
void afterwards (); // after the calculations
void circle (); // when it enters from words :)
void quit (); // the part where the program kinda quits... idk... :D

void circle ()
{
	system("clear");
	retry:
	cout << "Do you have the radius (r), diameter (d), circumference (c) or area (a) of the circle? (exit to return to words) ";
	getline (cin, measurement_type);
	if (measurement_type == "radius" || measurement_type == "r")
	{
		radius ();
	}
	if (measurement_type == "diameter" || measurement_type == "d")
	{
		diameter ();
	}
	if (measurement_type == "circumference" || measurement_type == "c")
	{
		circumference ();
	}
	if (measurement_type == "area" || measurement_type == "a")
	{
		area ();
	}
	if (measurement_type == "exit")
	{
		exit (1);
	}
	else
	{
		cout << "Sorry, you have to choose 'radius(r)', 'diameter(d)', 'circumference(c)' or 'area(a)'" << endl;
		goto retry;
	}
//	return 0;
}

void radius ()
{
	cout << "What is the radius of the circle? ";
	cin >> measurement_length;
	cin.ignore();
	measurement_length_diameter=measurement_length*2;
	measurement_length_circumference=measurement_length_diameter*PI;
	measurement_length_area=PI*measurement_length*measurement_length;
	cout << "The diameter is " << measurement_length_diameter << endl;
	cout << "The circumference is " << measurement_length_circumference << endl;
	cout << "The area is " << measurement_length_area << endl;
	afterwards ();
}

void diameter ()
{
	cout << "What is the diameter of the circle? ";
	cin >> measurement_length;
	cin.ignore();
	measurement_length_circumference=measurement_length*PI;
	measurement_length_radius=measurement_length/2;
	measurement_length_area=measurement_length_radius*measurement_length_radius*PI;
	cout << "The circumference is " << measurement_length_circumference << endl;
	cout << "The radius is " << measurement_length_radius << endl;
	cout << "The area is " << measurement_length_area << endl;
	afterwards ();
}

void circumference ()
{
	cout << "What is the circumference of the circle? ";
	cin >> measurement_length;
	cin.ignore();
	measurement_length_radius=measurement_length/PI/2;
	measurement_length_diameter=measurement_length/PI;
	measurement_length_area=measurement_length_radius*measurement_length_radius*PI;
	cout << "The radius is " << measurement_length_radius << endl;
	cout << "The diameter is " << measurement_length_diameter << endl;
	cout << "The area is " << measurement_length_area << endl;
	afterwards ();
}

void area ()
{
	cout << "What is the area of the circle? ";
	cin >> measurement_length;
	cin.ignore();
	measurement_length_area_radius=measurement_length/PI;
	measurement_length_radius=sqrt(measurement_length_area_radius);
	measurement_length_diameter=measurement_length_radius*2;
	measurement_length_circumference=measurement_length_diameter*PI;
	cout << "The radius is " << measurement_length_radius << endl;
	cout << "The diameter is " << measurement_length_diameter << endl;
	cout << "The circumference is " << measurement_length_circumference << endl;
	afterwards ();
}

void afterwards ()
{
	retry:
	cout << "Do you have another one? [yes(y)/no(n)] ";
	getline (cin, another_one);
	if (another_one == "yes" || another_one == "y")
	{
		system("clear");
		circle ();
	}
	if (another_one == "no" || another_one == "n")
	{
		quit ();
	}
	else
	{
		cout << "[yes(y)/no(n)]" << endl;
		goto retry;
	}
}