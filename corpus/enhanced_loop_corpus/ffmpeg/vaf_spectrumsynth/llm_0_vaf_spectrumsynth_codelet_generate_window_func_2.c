#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;
extern double b;
extern double sum;
extern double t;
extern double c;
extern double norm;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double c = 1 - 1 / (2.0 * 2.0);
    int n = (N - 1) / 2;
    for (; n >= 0; --n) {
        double sum = !n;
        double b = 1.0, t = 1.0;
        int j = 1;
        if (n > 0) {
            for (; j <= n && sum != t; ++j) {
                t = sum;
                b *= (n - j + 1) * (1.0 / j);
                double increment = b * c * (N - n - j) * (1.0 / j);
                sum += increment;
            }
        }
        sum /= (N - 1 - n);
        if (!norm) norm = sum;
        sum /= norm;
        lut[n] = sum;
        lut[N - 1 - n] = sum;
    }
}
