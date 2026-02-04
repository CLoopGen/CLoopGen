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
        sum = 1.0;
        if (n == 0) {
            lut[n] = 1.0;
            lut[N - 1 - n] = 1.0;
            continue;
        }
        b = t = j = 1;
        for (j = 1; j <= n; ++j) {
            b *= (n - j + 1) * (1.0 / j);
            double delta = b * c * (N - n - j) * (1.0 / j);
            sum += delta;
            if (sum == t) break;
            t = sum;
        }
        sum /= (N - 1 - n);
        if (norm == 0) norm = sum;
        sum /= norm;
        lut[n] = sum;
        lut[N - 1 - n] = sum;
    }
}
