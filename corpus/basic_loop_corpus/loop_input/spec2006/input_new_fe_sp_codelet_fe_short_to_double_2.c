#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef short int16;

int16 *in;
double *out;
int len;
int i;

void init_vars() {
    len = 64 * 1024 * 1024 / sizeof(int16);  // ~128MB of input data for sufficient runtime (~0.01 sec on modern CPU)
    in = (int16*)malloc(len * sizeof(int16));
    out = (double*)malloc(len * sizeof(double));

    for (int j = 0; j < len; j++) {
        in[j] = (int16)(j % 32768);
    }
}