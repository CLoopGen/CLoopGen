#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int n = 200;
double A[2000][2000];
int r;
int s;
int t;
double (*B)[2000][2000];

void init_vars() {
    B = (double (*)[2000][2000]) malloc(sizeof(double[2000][2000]));
    for (int i = 0; i < 2000; ++i) {
        for (int j = 0; j < 2000; ++j) {
            A[i][j] = 1.0 / (i + j + 1);
            (*B)[i][j] = 0.0;
        }
    }
}