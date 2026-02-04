#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

#define DATA_SIZE_MB 64
#define ARRAY_SIZE (DATA_SIZE_MB * (1 << 20) / sizeof(double))

int next[12];
double one_bit;
int k;
double _usr_y1;
double y2;
double *xdbl;
double carry;
unsigned int ir;
unsigned int jr;

void init_vars() {
    size_t i;

    one_bit = 1.0;
    carry = 0.0;
    k = 0;
    _usr_y1 = 0.0;
    y2 = 0.0;

    xdbl = (double *)aligned_alloc(32, ARRAY_SIZE * sizeof(double));
    if (!xdbl) exit(1);

    for (i = 0; i < ARRAY_SIZE; ++i) {
        xdbl[i] = (double)(rand() % 1000) / 100.0;
    }

    for (i = 0; i < 11; ++i) {
        next[i] = (int)(i + 1);
    }
    next[11] = 0;

    ir = 1;
    jr = 5;

    while (ir == jr) {
        ir = rand() % 11 + 1;
        jr = rand() % 11 + 1;
    }
}