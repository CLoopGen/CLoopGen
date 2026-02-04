#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef short int16;

int16 *in;
double *out;
int len;
float factor;
int i;

void init_vars() {
    len = 131072; // Approximately 1MB input (131072 elements * 2 bytes per int16 = ~256KB, output ~1MB total)
    factor = 0.75f;

    in = (int16*)calloc(len, sizeof(int16));
    out = (double*)calloc(len, sizeof(double));

    for (i = 0; i < len; i++) {
        in[i] = (int16)(i % 32768);
    }
}