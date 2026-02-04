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
    double sum1, sum2, b1, b2, t1, t2, c_val;
    int j1, j2, n1, n2;
    c_val = 1.0 - 1.0 / (2.0 * 2.0);
    n1 = (N - 1) / 2;
    n2 = n1 - 4;
    norm = 0.0;

    for (; n1 >= 0 && n2 >= 0; --n1, --n2) {
        sum1 = (n1 == 0);
        sum2 = (n2 == 0);
        b1 = b2 = t1 = t2 = 1.0;
        j1 = j2 = 1;

        while (j1 <= n1 && j2 <= n2 && (sum1 != t1 || sum2 != t2)) {
            t1 = sum1;
            t2 = sum2;
            b1 *= (n1 - j1) * (1.0 / j1);
            b2 *= (n2 - j2) * (1.0 / j2);
            ++j1; ++j2;
            sum1 += (b1 *= c_val * (N - n1 - j1 + 1) * (1.0 / j1));
            sum2 += (b2 *= c_val * (N - n2 - j2 + 1) * (1.0 / j2));
        }

        sum1 /= (N - 1 - n1);
        sum2 /= (N - 1 - n2);
        if (!norm) norm = (sum1 > sum2) ? sum1 : sum2;
        sum1 /= norm;
        sum2 /= norm;

        lut[n1] = sum1;
        lut[N - 1 - n1] = sum1;
        if (n2 >= 0) {
            lut[n2] = sum2;
            lut[N - 1 - n2] = sum2;
        }
    }

    for (; n1 >= 0; --n1) {
        sum = !n1;
        b = t = j = 1;
        for (; j <= n1 && sum != t; ) {
            t = sum;
            b *= (n1 - j) * (1.0 / j);
            ++j;
            sum += (b *= c_val * (N - n1 - j + 1) * (1.0 / j));
        }
        sum /= (N - 1 - n1);
        sum /= norm;
        lut[n1] = sum;
        lut[N - 1 - n1] = sum;
    }
}
