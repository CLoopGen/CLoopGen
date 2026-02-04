#include <stdio.h>
#include <inttypes.h>

int n = 512;

double A[2000][2000];
int i;
int j;
int k;

void init_vars() {
    for (int ii = 0; ii < 2000; ii++) {
        for (int jj = 0; jj < 2000; jj++) {
            A[ii][jj] = (double)(ii * 2000 + jj + 1);
        }
    }
    for (int ii = 0; ii < n; ii++) {
        A[ii][ii] += 10.0;
    }
}