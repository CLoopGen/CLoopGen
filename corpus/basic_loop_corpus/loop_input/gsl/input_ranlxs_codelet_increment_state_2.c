#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01s runtime

int next[12];
double one_bit = 1.0;
double shift = 0.5;
int k = 0;
int kmax;
double _usr_y1;
double y2;
double *xdbl;
double *ydbl;
double carry = 0.0;
unsigned int ir;
unsigned int jr;

void init_vars() {
    xdbl = (double *)aligned_alloc(32, DATA_SIZE);
    ydbl = (double *)aligned_alloc(32, DATA_SIZE);

    for (size_t i = 0; i < DATA_SIZE / sizeof(double); ++i) {
        xdbl[i] = (double)(i % 1000) / 100.0;
        ydbl[i] = 0.0;
    }

    for (int i = 0; i < 12; ++i) {
        next[i] = (i + 1) % 12;
    }

    kmax = 1000000;

    ir = 0;
    jr = 1;

    carry = 0.0;
}