#include <stdio.h>

int i;
int k;

double phi1[66][66];
double phi2[66][66];

void init_vars() {
    for (int i = 0; i < 66; i++) {
        for (int k = 0; k < 66; k++) {
            phi1[i][k] = 0.0;
            phi2[i][k] = 0.0;
        }
    }
}