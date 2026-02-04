#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

double *CDF;
int lengthCDF;
double value;
int _usr_index;
int x;

#define index _usr_index

void init_vars() {
    lengthCDF = (int)(64 * 1024 * 1024 / sizeof(double)); // ~512MB of data to target 0.01s runtime on modern CPU
    CDF = (double*)aligned_alloc(32, lengthCDF * sizeof(double));
    if (!CDF) exit(1);

    for (int i = 0; i < lengthCDF; i++) {
        CDF[i] = (double)i / lengthCDF; // monotonically increasing values [0, 1)
    }

    value = 0.5; // ensure the loop breaks around middle
    _usr_index = -1; // default not found
    x = 0; // initialize loop counter
}