#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double dst[3][3];
double src1[3][3];
double src2[3][3];
int m;
int n;

void init_vars() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            src1[i][j] = (double)(i * 3 + j + 1);
            src2[i][j] = (double)(i * 3 + j + 1) * 2.0;
            dst[i][j] = 0.0;
        }
    }
    m = 0;
    n = 0;
}