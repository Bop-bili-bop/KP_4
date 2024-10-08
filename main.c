#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "validation.h"
#include "calc.h"
#define to_rad(x) (x * M_PI / 180.0)
int main()
{
    char choice = 0;
    double x1 = 0, x2 = 0, dx = 0, epsilon = 0;
    x1 = val_double_input("x1=");
    x2 = val_double_input("x2=");
    if (x1 == x2)
        {
        dx = dx_numbers(0);
        }
    else
        {
        if (x1 < x2)
            {
            dx = dx_numbers(1);
            }
        else
            {
            dx = dx_numbers(2);
            }
        }
    epsilon = val_double_input("epsilon=");

    for (double x = x1; x1 < x2 ? x <= x2 : x >= x2; x += dx)
    {
        double radians = to_rad(x); // Переведення в радіани
        double taylor_result = 0, lib_result = 0, diff = 0;

        taylor_result = taylor_cos(radians, epsilon);
        lib_result = cos(radians);


        diff = fabs(taylor_result - lib_result);

        printf("  %-6.6lf    %-*.*lf    %-15.15lf    %-15.15lf  \n", x, abs(log10(epsilon)), abs(log10(epsilon)), taylor_result, lib_result, diff);
    }
}