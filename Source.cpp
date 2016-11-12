/*
Quadratic equation solver will solve:
ax^2 + bx +c = 0
Answer = [- b +-(b^2 - 4 ac)^(1/2)]/2a
Will find complex numbers as well
*/

//#include directives
#include <iostream>
#include <cmath>
#include <complex>
#include <string>
#include <stdexcept>

//using declarations
using std::cout; using std::cin; using std::endl; using std::pow; using std::sqrt; using std::complex; using std::real;
using std::imag; using std::sqrt; using std::istream; using std::string; using std::domain_error;

//Functions
double Disct(double& a, double& b, double& c)
{
	return pow(b, 2) - 4 * a*c;
}
complex<double> Quad(double&a, double& b, complex<double>& S)
{
	complex <double> A(a, 0); complex <double> B(b, 0);
	double two = 2;
	return (-B + S) / (two * A);
}
double Enter(double& v, string s)
{
	cout << "Please enter the value for " << s << ": ";
	cin >> v;
	if (cin.fail())
	{
		cout << "\nSyntax Error, input is not a string, please try again.\n\nTerminated with error code 001.\n";
		throw domain_error("Syntax Error");
	}
	return v;
}


//main
int main()
{
	cout << "This programme will solve quadratic equations of the form:\n\n   ax^2 + bx +c =0\n" << endl;
	double a, b, c; string aS = "a", bS = "b", cS = "c";

	try{ Enter(a, aS); Enter(b, bS); Enter(c, cS); }
	catch (domain_error) { return 1; }

	//Call the Discriminant function
	cout << "\nCalculating...\n";
	complex<double> D(Disct(a, b, c), 0);
	if (real(D) >= 0)
	{
		cout << "\nDiscriminant is positive\n";
	}
	else
	{
		cout << "\nDiscriminant is imaginary\n";
	}

	//Find the roots
	cout << real(D) << "\n" << endl;
	complex<double> psD = sqrt(D), nsD = -sqrt(D);
	complex<double> x_1 = Quad(a, b, psD);
	complex<double> x_2 = Quad(a, b, nsD);

	//Print the results
	cout << "The answers are:\nx_1 = " << real(x_1);
	if (imag(x_1) != 0)
	{
		cout << " + " << imag(x_1) << "i";
	};
	cout << "\nx_2 = " << real(x_2);
	if (imag(x_2) != 0)
	{
		cout << " + " << imag(x_2) << "i";
	};
	cout << "\n" << endl;

	//End
	return 0;
}