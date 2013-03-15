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
void afterwards (); // after the calculations
void circles (); // when it enters from words :)
void body (string where_from); // the part where the program kinda quits... idk... :D

void circleCalc ()
{
	string kindOfProblem;

	system("clear");
	while (true)
	{
		cout << "What do you want to calculate?\n\n";
		cout << "\t1. Circle (radius, diameter, circumference, area)\n";
		cout << "\t2. Cylindar (area, surface area)\n";
		cout << "\t3. Sphere (area)\n\n";
		cout << "What are we trying to calculate here? ";
		getline(cin,kindOfProblem);
		if (kindOfProblem == "circle" || kindOfProblem == "Circle" || kindOfProblem == "1")
		{
			circles ();
			break;
		}
		if (kindOfProblem == "cylindar" || kindOfProblem == "Cylindar" || kindOfProblem == "2")
		{
			cylindar ();
			break;
		}
		if (kindOfProblem == "sphere" || kindOfProblem == "Sphere" || kindOfProblem == "3")
		{
			sphere ();
			break;
		}
	}
}

void circles ()
{
	system("clear");
	while (true) {
		cout << "Do you have the radius (r), diameter (d), circumference (c) or area (a) of the circle? ";
		getline (cin, measurement_type);
		if (measurement_type == "radius" || measurement_type == "r")
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
			break;
		}
		if (measurement_type == "diameter" || measurement_type == "d")
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
			break;
		}
		if (measurement_type == "circumference" || measurement_type == "c")
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
			break;
		}
		if (measurement_type == "area" || measurement_type == "a")
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
			break;
		}
		else
		{
			cout << "Sorry, you have to choose 'radius(r)', 'diameter(d)', 'circumference(c)' or 'area(a)'\n";
		}
	}
}

void cylindar ()
{
	string returned_from = "ERROR: typo in the cylindar calculator";
	string cylindarCalcType, cylindarCircleType;
	float cylindarCircleMeasurement, cylindarLength;
	cylindarAreaCalculations cylindarAreaCalculateMeasurements;
	cylindarSurfaceAreaCalculations cylindarSurfaceAreaCalculateMeasurements;

	cout << "Calculating the area or the surface area? ";
	getline(cin,cylindarCalcType);
	if (cylindarCalcType == "area")
	{
		cout << "Do you have the radius or the diameter of the circle? ";
		getline(cin,cylindarCircleType);
		if (cylindarCircleType == "radius")
		{
			cout << "What is the radius of the circle? ";
			cin >> cylindarCircleMeasurement;
			cin.ignore();
			cout << "What is the length of the cylindar? ";
			cin >> cylindarLength;
			cin.ignore();
			cylindarAreaCalculateMeasurements.set_values (cylindarCircleMeasurement, cylindarLength);
			cout << "The area of the cylindar is " << cylindarAreaCalculateMeasurements.calculations() << endl << endl;
			afterwards();
		}
		if (cylindarCircleType == "diameter")
		{
			cout << "diameter\n";
			exit(0);
		}
		else
		{
			system("clear");
			body(returned_from);
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
			cin.ignore();
			cout << "What is the length of the cylindar? ";
			cin >> cylindarLength;
			cin.ignore();
			cylindarSurfaceAreaCalculateMeasurements.set_values (cylindarCircleMeasurement, cylindarLength);
			cout << "The surface area of the cylindar is " << cylindarSurfaceAreaCalculateMeasurements.calculations() << endl << endl;
			afterwards();
		}
		if (cylindarCircleType == "diameter")
		{
			cout << "What is the diameter of the circle? ";
			cin >> cylindarCircleMeasurement;
			cin.ignore();
			cylindarCircleMeasurement = cylindarCircleMeasurement/2;
			cout << "What is the length of the cylindar? ";
			cin >> cylindarLength;
			cin.ignore();
			cylindarSurfaceAreaCalculateMeasurements.set_values (cylindarCircleMeasurement, cylindarLength);
			cout << "The surface area of the cylindar is " << cylindarSurfaceAreaCalculateMeasurements.calculations() << endl << endl;
			afterwards();
		}
		else
		{
			system("clear");
			body(returned_from);
		}
	}
}

void sphere ()
{
//	string returned_from = "ERROR: typo in the sphere calculator";
	float sphereCircleMeasurement;
	sphereAreaCalculations sphereAreaCalculateMeasurements;

	cout << "What is the radius of the cylindar? ";
	cin >> sphereCircleMeasurement;
	cin.ignore();
	sphereAreaCalculateMeasurements.set_values (sphereCircleMeasurement);
	cout << "The area of the sphere is " << sphereAreaCalculateMeasurements.calculations() << endl << endl;
	afterwards();
}

void afterwards ()
{
	string returned_from = "circle calculator";
	while (true) {
		cout << "Do you have another one? [yes(y)/no(n)] ";
		getline (cin, another_one);
		if (another_one == "yes" || another_one == "y")
		{
			system("clear");
			circleCalc ();
			break;
		}
		if (another_one == "no" || another_one == "n")
		{
			system("clear");
			body (returned_from);
			break;
		}
		else
		{
			cout << "[yes(y)/no(n)]\n";
		}
	}
}
