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
    double c = 1 - 1 / (b * b);
    n = (N - 1) / 2;
    for (; n >= 0; --n) {
        sum = (n == 0) ? 1.0 : 0.0;
        b = 1.0;
        t = 1.0;
        j = 1;
        for (; j <= n && sum != t; ++j) {
            b *= (n - j + 1) * (1. / j);
            t = sum;
            sum += (b *= c * (N - n - j) * (1. / j));
        }
        sum /= (N - 1 - n);
        if (norm == 0) norm = sum;
        sum /= norm;
        lut[n] = sum;
        lut[N - 1 - n] = sum;
    }
}
