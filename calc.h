#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <math.h>
#include "validation.h"
#define M_PI 3.14159265358979323846
double taylor_sin(double x, double epsilon)
{
    double sigma = x, sin = sigma;
    unsigned n = 1;
    do
    {
        sigma *= -x * x / ((n +2)* (n + 1));
        sin += sigma;
        n += 2;
    }
    while (fabs(sigma) > epsilon);
    return sin;
}
double taylor_cos(double x, double epsilon)
{
    if (fabs(x) > 360)
        {
        double i = x/360.0;
        x -= 360.0*i;
        }
    double sigma = 1, cos = sigma;
    unsigned n = 1;
    do
    {
        sigma *= -x * x / (2 * n * (2 * n - 1));
        cos += sigma;
        n++;
    }
    while (fabs(sigma) > epsilon);
    return cos;
}
#endif