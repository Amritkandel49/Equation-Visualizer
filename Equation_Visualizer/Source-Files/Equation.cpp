#include "Equation.h"
using namespace std;

//for reading equation


void Equation::analyze() {
    float a = coeff_of_x2;
    float b = coeff_of_y2;
    float c = constant;
    float h = coeff_of_xy / 2;
    float g = coeff_of_x / 2;
    float f = coeff_of_y / 2;


    try {
        if (a == 0 && b == 0 && h == 0) {
            t = t_StLine;
            cout << "St line" << endl;

        }
        else if (((a * b * c) + (2 * f * g * h) - (a * f * f) - (b * g * g) - (c * h * h)) == 0) {
            t = t_PairOfStLine;
            cout << "Pair of St line" << endl;
        }
        else{
            if ((h * h) - (a * b) == 0) {
                t = t_Parabola;
                cout << "Parabola" << endl;
            }
            else if (((h * h) - (a * b)) > 0) {
                if (a == -b) {
                    t = t_RectHyperbola;
                    cout << "Rect Hyperbola" << endl;
                }
                else if (a != b){
                    t = t_Hyperbola;
                    cout << "Hyperbola" << endl;
                }
            }
            else if (((h * h) - (a * b)) < 0) {
                if (a == b) {
                    t = t_Circle;
                    cout << "Circle" << endl;
                }
                else {
                    t = t_Ellipse;
                    cout << "Ellipse" << endl;
                }
            }
            else
                throw;
        }
    }

    catch (...) {
        cout << "Please enter valid equation" << endl;
    }
}

void Equation::readEquation() {
    cout << "Enter the coefficients of Ax^2 + Hxy + By^2 + Gx + Fy + C = 0" << endl;
    cin >> coeff_of_x2 >> coeff_of_xy >> coeff_of_y2 >> coeff_of_x >> coeff_of_y >> constant;
  
    analyze();
    //cout << t << endl;
}