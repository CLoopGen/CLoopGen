#include <stdio.h>

int i;
int k;

double phi1[66][66];
double phi2[66][66];

void init_vars() {
    for (int idx_i = 0; idx_i < 66; idx_i++) {
        for (int idx_k = 0; idx_k < 66; idx_k++) {
            phi1[idx_i][idx_k] = 0.0;
            phi2[idx_i][idx_k] = 0.0;
        }
    }
}