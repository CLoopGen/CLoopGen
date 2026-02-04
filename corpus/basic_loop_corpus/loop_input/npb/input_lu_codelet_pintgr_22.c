#include <stdio.h>

int i;
int k;

double phi1[66][66];
double phi2[66][66];

void init_vars() {
    for (int ii = 0; ii < 66; ii++) {
        for (int kk = 0; kk < 66; kk++) {
            phi1[ii][kk] = 0.0;
            phi2[ii][kk] = 0.0;
        }
    }
}