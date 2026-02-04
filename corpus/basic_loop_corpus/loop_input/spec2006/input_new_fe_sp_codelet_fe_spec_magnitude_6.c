#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double r;
    double i;
} complex;

double *data;
int data_len;
int j;
int wrap;
complex *IN;

void init_vars() {
    data_len = 64 * 1024 * 1024; // ~512 MB of data (64M doubles)
    data = (double*)aligned_alloc(32, data_len * sizeof(double));
    IN = (complex*)aligned_alloc(32, data_len * sizeof(complex));

    for (int i = 0; i < data_len; i++) {
        data[i] = 1.0;
        IN[i].r = 0.0;
        IN[i].i = 0.0;
    }

    j = 0;
    wrap = 0;
}