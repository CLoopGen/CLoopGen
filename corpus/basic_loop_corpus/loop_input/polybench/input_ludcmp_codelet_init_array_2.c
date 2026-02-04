#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int n = 2000;
int r;
int s;
double (*B)[2000][2000];

void init_vars() {
    B = (double (*)[2000][2000])calloc(1, sizeof(double[2000][2000]));
    if (B == NULL) {
        exit(1);
    }
    n = 2000;
}