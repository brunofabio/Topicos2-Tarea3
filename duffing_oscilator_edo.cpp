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
	while (t < t_max) { 
	 // Paso Runge-Kutta de 4to orden
	 	double k1[2], k2[2], k3[2], k4[2], xv_step[2], dxvdt[2]; 
	 	find_dxvdt(t, xv, dxvdt); 
	 	for (int i = 0; i < 2; i++) 
	 		k1[i] = dt * dxvdt[i]; 
	 	for (int i = 0; i < 2; i++) 
	 		xv_step[i] = xv[i] + k1[i]/2; 
	 	find_dxvdt(t + 0.5 * dt, xv_step, dxvdt); 
	 	for (int i = 0; i < 2; i++) 
	 		k2[i] = dt * dxvdt[i]; 
	 	for (int i = 0; i < 2; i++) 
	 		xv_step[i] = xv[i] + k2[i]/2;
	 	find_dxvdt(t + 0.5 * dt, xv_step, dxvdt); 
	 	for (int i = 0; i < 2; i++) 
	 		k3[i] = dt * dxvdt[i]; 
	 	for (int i = 0; i < 2; i++) 
	 		xv_step[i] = xv[i] + k3[i]; 
	 	find_dxvdt(t + dt, xv_step, dxvdt); 
	 	for (int i = 0; i < 2; i++) 
	 		k4[i] = dt * dxvdt[i]; 
	 	for (int i = 0; i < 2; i++) 
	 		xv[i] += (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]) / 6.0; 
	 	t += dt; 
	 	file << t << ’\t’ << xv[0] << ’\t’ << xv[1] << ’\n’;
	 	 } 
	file.close(); cout << " Salida en archivo: " << file_name << endl; 
}