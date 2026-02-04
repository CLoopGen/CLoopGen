#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int n = 2000;
double A[2000][2000];
int r;
int s;
double (*B)[2000][2000];

void init_vars() {
    double (*b_ptr)[2000][2000] = (double (*)[2000][2000])malloc(sizeof(double[2000][2000]));
    if (b_ptr == NULL) {
        exit(1);
    }
    B = b_ptr;
    n = 2000;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            (*B)[i][j] = 1.0 / (i + j + 1);
        }
    }
}