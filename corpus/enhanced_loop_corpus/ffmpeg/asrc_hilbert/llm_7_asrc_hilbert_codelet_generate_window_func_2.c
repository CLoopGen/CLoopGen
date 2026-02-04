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
double local_norm = 0.0;
double prev_sum, current_sum;
for (c = 1 - 1 / (b * b), n = (N - 1) / 2; n >= 0; --n) {
    sum = !n;
    b = 1.0;
    t = 0.0;
    j = 1;
    prev_sum = sum;
    do {
        t = sum;
        b *= (n - j) * (1.0 / j);
        current_sum = t + b * c * (N - n - j) * (1.0 / j);
        sum = current_sum;
        j++;
    } while (j <= n && sum != t);

    sum /= (N - 1 - n);
    if (n == (N - 1) / 2) {
        local_norm = sum;
    }
    sum /= local_norm;
    lut[n] = sum;
    lut[N - 1 - n] = sum;
}
}
