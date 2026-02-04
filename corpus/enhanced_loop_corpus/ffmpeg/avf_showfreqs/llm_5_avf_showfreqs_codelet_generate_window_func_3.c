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
        sum = (n == 0) ? 1.0 : 0.0;
        b = 1.0;
        for (j = 1; j <= n && n > 0; ++j) {
            b *= (double)(n - j + 1) / (double)j;
            double term = b;
            for (int k = 0; k < 2; ++k) {
                term *= c * (N - n - j) * (1.0 / j);
            }
            sum += term;
            if (j == 1) t = sum;
            else if (sum == t) break;
            else t = sum;
        }
        if (n > 0) {
            sum /= (N - 1 - n);
            if (norm == 0) norm = sum;
            sum /= norm;
        }
        lut[n] = sum;
        lut[N - 1 - n] = sum;
    }
}
