#include <stdio.h>
#include <inttypes.h>

int m = 1000;
int n = 1000;
double A[1900][2100];
int i;
int j;

void init_vars() {
    for (int ii = 0; ii < 1900; ii++) {
        for (int jj = 0; jj < 2100; jj++) {
            A[ii][jj] = 0.0;
        }
    }
    m = 1000;
    n = 1000;
    i = 0;
    j = 0;
}