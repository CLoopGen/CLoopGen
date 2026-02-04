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
double temp_sum;
for (c = 1 - 1 / (b * b); ; ) {
    n = (N - 1) / 2;
    for (; n >= 0; --n) {
        sum = (n == 0);
        b = t = j = 1;
        for (; j <= n && sum != t; ++j) {
            t = sum;
            b *= (n - j + 1) * (1. / j);
            sum += b * c * (N - n - j) * (1. / j);
        }
        sum /= (N - 1 - n);
        norm = norm ? norm : sum;
        sum /= norm;
        lut[n] = sum;
        lut[N - 1 - n] = sum;
    }
    break;
}
}
