#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;
// parámetros
double omega = 2.4;
double gamma_ = 0.1; 
double a = 0.5;
double b = 0.25; 
double F0 = 2.0;

void find_dxvdt(double t, double xv[], double dxvdt[]) { 
dxvdt[0] = xv[1]; 
dxvdt[1] = - gamma_ * xv[1] + 2 * a * xv[0] - 4 * b * pow(xv[0], 3.0) + F0 * cos(omega * t);
 } 

int main() 
{
 	double xv[2]; // array: xv[0] = x, xv[1] = v 
	double dt, t_max; 
	string file_name;
	cout << " Duffing Oscillator\n" 
	<< " =============================\n" 
	<< " Ingresar x and v inicial: ";
	cin >> xv[0] >> xv[1];
	cout << " Ingresar el tiempo de paso dt: ";

	cin >> dt; 
	cout << " Ingresar el tiempo de integración: "; 
	cin >> t_max; 
	cout << " Ingresar el nombre del archivo de salida: "; 
	cin >> file_name;

	ofstream file(file_name.c_str()); 
	double t = 0; 
	file << t << ’\t’ << xv[0] << ’\t’ << xv[1] << ’\n’;
}