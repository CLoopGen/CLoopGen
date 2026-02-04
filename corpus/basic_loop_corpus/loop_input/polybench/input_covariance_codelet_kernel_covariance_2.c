#include <stdio.h>
#include <inttypes.h>

int m = 1200;
int n = 1000;
double data[1400][1200];
double mean[1200];
int i;
int j;

void init_vars() {
    for (int ii = 0; ii < n; ii++) {
        for (int jj = 0; jj < m; jj++) {
            data[ii][jj] = (double)(ii * m + jj);
        }
    }
    for (int jj = 0; jj < m; jj++) {
        mean[jj] = (double)jj;
    }
}