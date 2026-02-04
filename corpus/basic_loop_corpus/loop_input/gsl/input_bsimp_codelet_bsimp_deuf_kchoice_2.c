#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double a_work[8] = {0.0};
double alpha[7][7] = {{0.0}};
int k = 0;

void init_vars() {
    for (int i = 0; i < 8; i++) {
        a_work[i] = 1.0 + i * 0.1;
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            alpha[i][j] = 0.5 + (i * 7 + j) * 1e-3;
        }
    }
    k = 0;
}