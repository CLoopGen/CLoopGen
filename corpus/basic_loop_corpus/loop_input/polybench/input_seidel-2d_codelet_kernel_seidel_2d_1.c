#include <stdio.h>
#include <inttypes.h>

int tsteps = 50;
int n = 1000;
double A[2000][2000];
int t;
int i;
int j;

void init_vars() {
    for (int ii = 0; ii < 2000; ii++) {
        for (int jj = 0; jj < 2000; jj++) {
            A[ii][jj] = (double)(ii * jj) / 100.0;
        }
    }
}