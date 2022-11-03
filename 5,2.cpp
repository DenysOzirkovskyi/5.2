// 5,2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double S(const double x, const double eps, int& n, double s);
double A(const double x, const int n, double a);
double F(double x, double q);
int main()
{
	double xp,q=0,w, xk, x, dx, eps, s = 0;
	int n = 0;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;
	cout << fixed;
	cout << "-------------------------------------------------" << endl;
	cout << "|" << setw(5) << "x" << " |"
		<< setw(10) << "arcth" << " |"
		<< setw(7) << "S" << " |"
		<< setw(5) << "n" << " |"
		<< endl;
	cout << "-------------------------------------------------" << endl;
	x = xp;
	while (x <= xk)
	{
		if (abs(x) > 1)
		{
			q = F(x, q);
			s = S(x, eps, n, s);
			cout << "|" << setw(7) << setprecision(2) << x << " |"
				<< setw(10) << setprecision(5) << q << " |"
				<< setw(10) << setprecision(5) << s << " |"
				<< setw(5) << n << " |"
				<< endl;
			x += dx;
		}
		else
			x += dx;
	}
	cout << "-------------------------------------------------" << endl;
	return 0;
}
double S(const double x, const double eps, int& n, double s)
{
	n = 0; // вираз залежить від умови завдання варіанту
	double a = 1 / x * 1.0; // вираз залежить від умови завдання варіанту
	s = a;
	do {
		n++;
			a = A(x, n, a);
		s += a;
	} while (abs(a) >= eps);
	return s;
}
double A(const double x, const int n, double a)
{
	double R = ((2 * n * 1.0 - 1) / (2 * n * 1.0 + 1)) * 1.0 / (x * x); // вираз залежить від умови завдання варіанту
	a *= R;
	return a;
}
double F(double x , double q)
{
	q=log(((x + 1) / (x - 1))) / 2;

	return q;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
