#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

int nr = 140;
int nq = 120;
int np = 150;

double A[150][140][160];

int i, j, k;

void init_vars() {
    nr = 140;
    nq = 120;
    np = 150;

    srand(time(NULL));
}