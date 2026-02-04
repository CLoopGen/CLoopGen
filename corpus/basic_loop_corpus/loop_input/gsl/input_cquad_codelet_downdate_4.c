#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double bee[68];
int n;
int d;
int bidx[4];
double b_new[34];
int i;

void init_vars() {
    n = 33;
    d = 0;
    bidx[0] = 0;
    bidx[1] = 17;
    bidx[2] = 34;
    bidx[3] = 51;

    for (int j = 0; j < 68; j++) {
        bee[j] = (double)(j * 2);
    }

    for (int j = 0; j < 34; j++) {
        b_new[j] = 0.0;
    }
}