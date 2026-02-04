#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int len = 1048576; // 1MB of int32_t data (about 4 million samples), suitable for ~0.01s runtime

double b0 = 0.5;
double b1 = 0.25;
double b2 = 0.125;
double a1 = 0.1;
double a2 = 0.05;

int *clippings = NULL;
int disabled = 0;

int32_t *ibuf = NULL;
int32_t *obuf = NULL;

double i1 = 0.0;
double i2 = 0.0;
double o1 = 0.0;
double o2 = 0.0;
double wet = 0.8;
double dry = 0.2;
double out = 0.0;
int i = 0;

void init_vars() {
    clippings = (int*)malloc(sizeof(int));
    *clippings = 0;

    ibuf = (int32_t*)aligned_alloc(32, len * sizeof(int32_t));
    obuf = (int32_t*)aligned_alloc(32, len * sizeof(int32_t));

    if (!ibuf || !obuf || !clippings) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize input buffer with non-zero values to ensure meaningful computation
    for (int j = 0; j < len; j++) {
        ibuf[j] = (int32_t)(j % 1000 - 500); // Small varying input in range [-500, 499]
    }

    // Ensure initial state is clean
    i1 = 0.0;
    i2 = 0.0;
    o1 = 0.0;
    o2 = 0.0;
    *clippings = 0;
}