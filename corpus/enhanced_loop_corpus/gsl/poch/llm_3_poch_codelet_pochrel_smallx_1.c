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
for (k = 2; k <= nterms; k++) {
    double gbk = 0.;
    int idx, stride = 1;
    for (j = 1; j <= k; j++) {
        idx = (k - j + 1) * stride;
        gbk += bern[idx] * gbern[j * stride];
    }
    gbern[(k + 1) * stride] = -rho * gbk / k;
    term *= (2 * k - 2 - x) * (2 * k - 1 - x) * var2;
    poly1 += gbern[(k + 1) * stride] * term;
}
}
