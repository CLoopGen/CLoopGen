#include <stdio.h>

int ki1 = 0;
int ki2 = 65;
int i;
int k;
int ibeg = 0;
int ifin1 = 65;
double phi1[66][66];
double phi2[66][66];
double frc2;

void init_vars() {
    for (int ii = 0; ii < 66; ii++) {
        for (int jj = 0; jj < 66; jj++) {
            phi1[ii][jj] = (double)(ii * 66 + jj) / 100.0;
            phi2[ii][jj] = (double)(ii * 66 + jj) / 200.0;
        }
    }
    frc2 = 0.0;
}