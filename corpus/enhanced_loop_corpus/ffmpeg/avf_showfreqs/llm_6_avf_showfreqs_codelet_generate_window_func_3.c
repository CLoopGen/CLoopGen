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
double temp_sum, temp_b, temp_t;
for (c = 1 - 1 / (b * b), n = (N - 1) / 2; n >= 0; --n) {
    temp_sum = !n;
    temp_b = 1.0;
    temp_t = 1.0;
    for (j = 1; j <= n && temp_sum != temp_t; ++j) {
        temp_b *= (n - j) * (1.0 / j);
        temp_t = temp_sum;
        temp_b *= c * (N - n - j) * (1.0 / j);
        temp_sum += temp_b;
    }
    temp_sum /= (N - 1 - n);
    norm = norm ? norm : temp_sum;
    temp_sum /= norm;
    lut[n] = temp_sum;
    lut[N - 1 - n] = temp_sum;
}
}
