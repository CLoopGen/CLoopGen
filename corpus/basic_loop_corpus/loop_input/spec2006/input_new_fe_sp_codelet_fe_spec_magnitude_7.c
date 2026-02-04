#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct {
    double r;
    double i;
} complex;

double *data;
int data_len;
int j;
complex *IN;

void init_vars() {
    data_len = 32000000; // Approximately 256MB of data (32M * 8 bytes per double)

    data = (double *)aligned_alloc(32, data_len * sizeof(double));
    IN = (complex *)aligned_alloc(32, data_len * sizeof(complex));

    for (int i = 0; i < data_len; i++) {
        data[i] = (double)(i & 0xFF);
        IN[i].r = 0.0;
        IN[i].i = 0.0;
    }

    j = 0;
}