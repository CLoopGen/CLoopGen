#include <stdio.h>
#include <inttypes.h>

int tsteps = 10;
int n = 512;

double A[1300][1300];
double B[1300][1300];

int t;
int i;
int j;

void init_vars() {
    for (int ii = 0; ii < 1300; ii++) {
        for (int jj = 0; jj < 1300; jj++) {
            A[ii][jj] = (double)(ii * jj % 17) / 17;
            B[ii][jj] = 0.0;
        }
    }
}