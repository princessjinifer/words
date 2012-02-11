/*	Circle Calculator
 *	Micah Butler (princessjinifer)
 *	5-5-2011
 *	Calculates the radius, circumference and diameter depending on what the user inputs :)
 * 	Appended to words v.0.2
*/

#include "words.h"
#include "ccalc.h"

string measurement_type;
string another_one;
float measurement_length;
float measurement_length_diameter;
float measurement_length_circumference;
float measurement_length_radius;
float measurement_length_area;
float measurement_length_area_radius;

void circleCalc ();
void sphere ();
void cylindar ();
void circleArea (); // calculating the diameter, circumference and radius
void circleRadius (); // calculating the diameter, circumference and area
void circleDiameter (); // calculating the circumference, radius and area
void circleCircumference (); // calculating the diameter, radius and area
void afterwards (); // after the calculations
void circles (); // when it enters from words :)
void body (string where_from); // the part where the program kinda quits... idk... :D

void circleCalc ()
{
	string kindOfProblem;

	system("clear");
	while (true)
	{
		cout << "Enter \"circle\", \"cylindar\" or \"sphere\"\n";
		cout << "What are we trying to calculate here? ";
		getline(cin,kindOfProblem);
		if (kindOfProblem == "circle")
		{
			circles ();
			break;
		}
		if (kindOfProblem == "cylindar")
		{
			cylindar ();
			break;
		}
		if (kindOfProblem == "sphere")
		{
			sphere ();
			break;
		}
	}; //while (kindOfProblem != "circle" || kindOfProblem != "cylindar" || kindOfProblem != "sphere");
}

void circles ()
{
	system("clear");
	retry:
	cout << "Do you have the radius (r), diameter (d), circumference (c) or area (a) of the circle? (exit to return to words) ";
	getline (cin, measurement_type);
	if (measurement_type == "radius" || measurement_type == "r")
	{
		circleRadius ();
	}
	if (measurement_type == "diameter" || measurement_type == "d")
	{
		circleDiameter ();
	}
	if (measurement_type == "circumference" || measurement_type == "c")
	{
		circleCircumference ();
	}
	if (measurement_type == "area" || measurement_type == "a")
	{
		circleArea ();
	}
	else
	{
		cout << "Sorry, you have to choose 'radius(r)', 'diameter(d)', 'circumference(c)' or 'area(a)'\n";
		goto retry;
	}
//	return 0;
}

void circleRadius ()
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

void circleDiameter ()
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

void circleCircumference ()
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

void circleArea ()
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

void cylindar ()
{
	string cylindarCalcType, cylindarCircleType;
	float cylindarCircleMeasurement, cylindarLength;
	cylindarAreaCalculations cylindarAreaCalculateMeasurements;
	cylindarSurfaceAreaCalculations cylindarSurfaceAreaCalculateMeasurements;

	cout << "Calculting the area or the surface area? ";
	getline(cin,cylindarCalcType);
	if (cylindarCalcType == "area")
	{
		cout << "Do you have the radius or the diameter of the circle? ";
		getline(cin,cylindarCircleType);
		if (cylindarCircleType == "radius")
		{
			cout << "What is the radius of the circle? ";
			cin >> cylindarCircleMeasurement;
			cout << "What is the length of the cylindar? ";
			cin >> cylindarLength;
			cylindarAreaCalculateMeasurements.set_values (cylindarCircleMeasurement, cylindarLength);
			cout << "The area of the cylindar is " << cylindarAreaCalculateMeasurements.calculations() << endl << endl;
			afterwards();
		}
		if (cylindarCircleType == "diameter")
		{
			cout << "diameter\n";
			exit(0);
		}
	}
	if (cylindarCalcType == "surface area" || cylindarCalcType == "surface")
	{
		cout << "Do you have the radius or the diameter of the circle? ";
		getline(cin,cylindarCircleType);
		if (cylindarCircleType == "radius")
		{
			cout << "What is the radius of the circle? ";
			cin >> cylindarCircleMeasurement;
			cout << "What is the length of the cylindar? ";
			cin >> cylindarLength;
			cylindarSurfaceAreaCalculateMeasurements.set_values (cylindarCircleMeasurement, cylindarLength);
			cout << "The area of the cylindar is " << cylindarSurfaceAreaCalculateMeasurements.calculations() << endl << endl;
			afterwards();
		}
		if (cylindarCircleType == "diameter")
		{
			cout << "What is the diameter of the circle? ";
			cin >> cylindarCircleMeasurement;
			cylindarCircleMeasurement = cylindarCircleMeasurement/2;
			cout << "What is the length of the cylindar? ";
			cin >> cylindarLength;
			cylindarSurfaceAreaCalculateMeasurements.set_values (cylindarCircleMeasurement, cylindarLength);
			cout << "The area of the cylindar is " << cylindarSurfaceAreaCalculateMeasurements.calculations() << endl << endl;
			afterwards();
		}
	}
}

void sphere ()
{
	cout << "sphere :p\n";
	exit(0);
}

void afterwards ()
{
	string returned_from = "circle calculator";
	retry:
	cin.get();
	cout << "Do you have another one? [yes(y)/no(n)] ";
	getline (cin, another_one);
	if (another_one == "yes" || another_one == "y")
	{
		system("clear");
		circleCalc ();
	}
	if (another_one == "no" || another_one == "n")
	{
		system("clear");
		body (returned_from);
	}
	else
	{
		cout << "[yes(y)/no(n)]\n";
		goto retry;
	}
}
