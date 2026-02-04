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
for (c = 1 - 1 / (b * b), n = (N - 1) / 2; n >= 0; --n) {
    if (n > 0) {
        for (sum = 0.0, b = t = j = 1; j <= n; ++j) {
            t = sum;
            b *= (n - j + 1) * (1. / j);
            sum += b * c * (N - n - j) * (1. / j);
            if (sum == t) break;
        }
    } else {
        sum = 1.0;
    }
    sum /= (N - 1 - n);
    norm = norm ? norm : sum;
    sum /= norm;
    lut[n] = sum;
    lut[N - 1 - n] = sum;
}
}
