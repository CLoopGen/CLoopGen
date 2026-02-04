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
double inner_sum, temp_b, temp_t;
for (c = 1 - 1 / (b * b), n = (N - 1) / 2; n >= 0; --n) {
    for (sum = !n, b = t = j = 1; j <= n && sum != t; ++j) {
        t = sum;
        b *= (n - j) * (1. / j);
        temp_b = b;
        temp_t = t;
        for (int k = 0; k < 2; ++k) {
            if (k == 1) {
                temp_b *= c * (N - n - j) * (1. / j);
                temp_t += temp_b;
            }
        }
        sum = temp_t;
    }
    sum /= (N - 1 - n);
    norm = norm ? norm : sum;
    sum /= norm;
    lut[n] = sum;
    lut[N - 1 - n] = sum;
}
}
