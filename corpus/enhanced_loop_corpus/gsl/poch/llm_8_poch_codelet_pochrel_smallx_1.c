#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double bern[21];
extern  double x;
extern double poly1;
extern  int nterms;
extern  double var2;
extern  double rho;
extern double term;
extern double gbern[24];
extern int k;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 2; k <= nterms; k += 2) {
    double gbk1 = 0.;
    double gbk2 = 0.;
    int k2 = k + 1;
    for (j = 1; j <= k; j++) {
        gbk1 += bern[k - j + 1] * gbern[j];
        if (k2 <= nterms && j <= k2) {
            gbk2 += bern[k2 - j + 1] * gbern[j];
        }
    }
    gbern[k + 1] = -rho * gbk1 / k;
    if (k2 <= nterms) {
        gbern[k2 + 1] = -rho * gbk2 / k2;
    }
    term *= (2 * k - 2 - x) * (2 * k - 1 - x) * var2;
    poly1 += gbern[k + 1] * term;
    if (k2 <= nterms) {
        double next_term = term * (2 * k2 - 2 - x) * (2 * k2 - 1 - x) * var2;
        poly1 += gbern[k2 + 1] * next_term;
    }
}
}
