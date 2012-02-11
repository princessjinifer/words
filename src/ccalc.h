/*	Circle Calculator
 *	Micah Butler (princessjinifer)
 *	5-5-2011
 *	Calculates the radius, circumference and diameter depending on what the user inputs :)
 * 	Appended to words v.0.2
*/

#define PI 3.14

class cylindarAreaCalculations {
	float cylindarCircleRadiusClass, cylindarLengthClass;

public:
	void set_values (float, float);
	float calculations ()
	{
		float returnedCalc = (cylindarCircleRadiusClass*cylindarCircleRadiusClass*PI)*cylindarLengthClass;
		return (returnedCalc);
	}
};

void cylindarAreaCalculations::set_values (float cylindarCircleRadiusVoid, float cylindarLengthVoid)
{
	cylindarCircleRadiusClass = cylindarCircleRadiusVoid;
	cylindarLengthClass = cylindarLengthVoid;
}

class cylindarSurfaceAreaCalculations {
	float cylindarCircleRadiusClass, cylindarLengthClass;

public:
	void set_values (float, float);
	float calculations ()
	{
		float returnedCalc = (((cylindarCircleRadiusClass*2)*PI)*cylindarLengthClass) + (((cylindarCircleRadiusClass*cylindarCircleRadiusClass)*PI)*2);
		return (returnedCalc);
	}
};

void cylindarSurfaceAreaCalculations::set_values (float cylindarCircleRadiusVoid, float cylindarLengthVoid)
{
	cylindarCircleRadiusClass = cylindarCircleRadiusVoid;
	cylindarLengthClass = cylindarLengthVoid;
}