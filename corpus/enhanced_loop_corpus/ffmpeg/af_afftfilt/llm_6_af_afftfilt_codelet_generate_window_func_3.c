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
for (c = 1 - 1 / (b * b), n = (N - 1) / 2; n >= 0; --n) {
    temp_sum = 0.0;
    for (sum = !n, b = t = j = 1; j <= n && sum != t; ++j) {
        double prev_b = b;
        b *= (n - j) * (1. / j);
        t = sum;
        sum += (b *= c * (N - n - j) * (1. / j));
        temp_sum += prev_b;
    }
    sum /= (N - 1 - n);
    norm = norm ? norm : sum;
    sum /= norm;
    lut[n] = sum;
    lut[N - 1 - n] = sum;
}
}
