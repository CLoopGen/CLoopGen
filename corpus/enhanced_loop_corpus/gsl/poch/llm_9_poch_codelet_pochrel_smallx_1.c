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
if (nterms < 2) return;
double gbk_acc = 0.0;
for (k = 2; k <= nterms; k++) {
    gbk_acc = 0.0;
    j = k;
    while (j >= 1) {
        gbk_acc += bern[k - j + 1] * gbern[j];
        j--;
    }
    gbern[k + 1] = -rho * gbk_acc / k;
    term *= (2 * k - 2 - x) * (2 * k - 1 - x) * var2;
    poly1 += gbern[k + 1] * term;
}
}
