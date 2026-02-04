#include <stdio.h>
#include <inttypes.h>

int m = 1000;
int n = 1200;

double data[1400][1200];
double corr[1200][1200];

int i;
int j;
int k;

void init_vars() {
    for (int ii = 0; ii < 1400; ii++) {
        for (int jj = 0; jj < 1200; jj++) {
            data[ii][jj] = (double)(ii * jj % 17) / 17.0;
        }
    }

    for (int ii = 0; ii < 1200; ii++) {
        for (int jj = 0; jj < 1200; jj++) {
            corr[ii][jj] = 0.0;
        }
    }

    i = 0;
    j = 0;
    k = 0;
}