#include <stdio.h>
#include <inttypes.h>

int m = 1000;
int n = 1200;
double alpha = 1.5;

double A[1000][1000];
double B[1000][1200];

int i, j, k;

void init_vars() {
    for (int ii = 0; ii < 1000; ii++) {
        for (int jj = 0; jj < 1000; jj++) {
            A[ii][jj] = (double)(ii + jj) / 1000.0;
        }
    }
    for (int ii = 0; ii < 1000; ii++) {
        for (int jj = 0; jj < 1200; jj++) {
            B[ii][jj] = (double)(ii * jj) / 2000.0;
        }
    }
    i = 0;
    j = 0;
    k = 0;
}