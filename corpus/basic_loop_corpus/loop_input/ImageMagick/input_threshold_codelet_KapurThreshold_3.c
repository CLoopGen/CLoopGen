#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <string.h>

double *black_entropy;
double maximum_entropy;
double *white_entropy;
ssize_t j;
size_t threshold;

static double black_entropy_data[256];
static double white_entropy_data[256];

void init_vars() {
    black_entropy = black_entropy_data;
    white_entropy = white_entropy_data;
    maximum_entropy = 0.0;
    j = 0;
    threshold = 0;

    for (int i = 0; i < 256; i++) {
        black_entropy[i] = rand() / (double)RAND_MAX * 100.0;
        white_entropy[i] = rand() / (double)RAND_MAX * 100.0;
    }
}