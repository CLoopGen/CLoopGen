#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

long mrand_list[56];
int inext;
int inextp;
double a[2097152]; // ~16 MB of double data (2^21 elements)
int len;
int i;
long lval;
double factor;

void init_vars() {
    // Initialize mrand_list with pseudo-random values
    srand((unsigned int)time(NULL));
    for (int j = 0; j < 56; j++) {
        mrand_list[j] = ((long)rand() << 31) | rand();
    }

    // Initialize state variables
    inext = 0;
    inextp = 31; // Standard initialization gap used in some MRG32k3a implementations

    // Set factor to a reasonable value for scaling
    factor = 1.0 / 9223372036854775807.0;

    // Set length to ensure ~0.01 sec runtime (~2M iterations typical for modern CPU)
    len = 2097152; // 2^21 elements, gives sufficient workload
}