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
 
}