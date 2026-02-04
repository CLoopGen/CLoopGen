#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int n = 100;
double A[2000][2000];
int r;
int s;
int t;
double (*B)[2000][2000];

void init_vars() {
    B = (double (*)[2000][2000])malloc(sizeof(double[2000][2000]));
    n = 100;
    for (int i = 0; i < 2000; ++i) {
        for (int j = 0; j < 2000; ++j) {
            A[i][j] = 1.0;
        }
    }
    for (int i = 0; i < 2000; ++i) {
        for (int j = 0; j < 2000; ++j) {
            (*B)[i][j] = 0.0;
        }
    }
}