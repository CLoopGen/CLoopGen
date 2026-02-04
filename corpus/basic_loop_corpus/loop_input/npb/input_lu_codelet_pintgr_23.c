#include <stdio.h>

int ki1 = 1;
int ki2 = 65;
int j;
int k;
int jbeg = 1;
int jfin1 = 65;
double phi1[66][66];
double phi2[66][66];
double frc3;

void init_vars() {
    for (int i = 0; i < 66; i++) {
        for (int jj = 0; jj < 66; jj++) {
            phi1[i][jj] = (double)(i * 66 + jj) / 100.0;
            phi2[i][jj] = (double)(i * 66 + jj + 1) / 101.0;
        }
    }
    frc3 = 0.0;
}