#include <stdio.h>

int i;
int j;
int ibeg = 1;
int ifin1 = 64;
int jbeg = 1;
int jfin1 = 64;
double phi1[66][66];
double phi2[66][66];
double frc1;

void init_vars() {
    frc1 = 0.0;
    for (int ii = 0; ii < 66; ii++) {
        for (int jj = 0; jj < 66; jj++) {
            phi1[ii][jj] = (double)(ii * 66 + jj) / 100.0;
            phi2[ii][jj] = (double)(ii * 66 + jj) / 200.0;
        }
    }
}