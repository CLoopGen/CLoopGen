#include <stdio.h>
#include <inttypes.h>

int n = 1500;

double L[2000][2000];
double x[2000];
double b[2000];
int i;
int j;

void init_vars() {
    for (int ii = 0; ii < 2000; ii++) {
        for (int jj = 0; jj < 2000; jj++) {
            L[ii][jj] = 0.0;
        }
        x[ii] = 0.0;
        b[ii] = 0.0;
    }
    i = 0;
    j = 0;
}