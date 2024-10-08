#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "validation.h"
#include "calc.h"
#define to_rad(x) (x * M_PI / 180.0)
int main()
{
    char choice = 0;
    double x1 = 0, x2 = 0, dx = 0, epsilon = 0, sin_x1 = 0, sin_x2 = 0, cos_x1 = 0, cos_x2 = 0, x1_rad  = 0, x2_rad  = 0;
    x1 = val_double_input("x1=");
    x2 = val_double_input("x2=");
    dx = val_double_input("dx=");
    epsilon = val_double_input("epsilon=");

    for (double x = x1; x1 < x2 ? x <= x2 : x >= x2; x += dx)
    {
        double radians = to_rad(x); // Переведення в радіани
        double taylor_result = 0, lib_result = 0, diff = 0;

        taylor_result = taylor_cos(radians, epsilon);
        lib_result = cos(radians);


        diff = fabs(taylor_result - lib_result);

        printf("  %-6.6lf    %-*.*lf    %-*.*lf    %-*.*lf  \n", x, abs(log10(epsilon)), abs(log10(epsilon)), taylor_result, abs(log10(epsilon)), abs(log10(epsilon)), lib_result, abs(log10(epsilon)), abs(log10(epsilon)), diff);
    }
}
