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
    sum = (n ? 1 : 0);
    b = t = j = 1;
    for (; j <= n && !(sum == t && j > 1); ++j) {
        t = sum;
        b = b * c * (N - n - j) / j;
        sum += b;
        b = b * (n - j) / j;
    }
    sum /= (N - 1 - n);
    norm = (norm != 0) ? norm : sum;
    sum /= norm;
    lut[n] = sum;
    lut[N - 1 - n] = sum;
}
}
