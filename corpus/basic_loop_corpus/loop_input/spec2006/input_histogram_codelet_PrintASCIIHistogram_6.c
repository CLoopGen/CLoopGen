#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>

struct histogram_s {
    int *histogram;
    int min;
    int max;
    int highscore;
    int lowscore;
    int lumpsize;
    int total;
    float *expect;
    int fit_type;
    float param[3];
    float chisq;
    float chip;
};

static struct histogram_s h_storage;
struct histogram_s *h = &h_storage;

int i;
int lowbound;
int lowcount;

void init_vars() {
    // Set parameters to ensure meaningful loop execution
    h->min = 100;
    h->lowscore = 200;
    lowbound = 500;
    int hist_size = lowbound - h->min + 1; // Ensure inclusive range [lowscore-min, lowbound-min]

    // Allocate histogram array and initialize to zero
    h->histogram = (int*)calloc(hist_size, sizeof(int));
    if (!h->histogram) {
        exit(1);
    }

    // Initialize histogram values to non-zero to simulate real data
    for (int idx = 0; idx < hist_size; idx++) {
        h->histogram[idx] = (idx * idx) % 100; // Arbitrary non-trivial pattern
    }

    // Other fields not used in loop but initialized for completeness
    h->max = lowbound + 100;
    h->highscore = 400;
    h->lumpsize = 1;
    h->total = 0;
    h->expect = NULL;
    h->fit_type = 0;
    h->param[0] = 0.0f;
    h->param[1] = 0.0f;
    h->param[2] = 0.0f;
    h->chisq = 0.0f;
    h->chip = 0.0f;

    // Ensure loop runs enough to meet timing (~0.01 sec)
    // The loop runs (lowbound - h->lowscore + 1) iterations
    // Adjust data size if necessary — currently ~300 iterations, which is too small

    // To increase runtime, we scale the problem: make histogram much larger
    // Free old histogram and re-allocate bigger one
    free(h->histogram);

    // Target: ~64M elements to ensure measurable runtime (each iteration is very cheap)
    int target_size = 64 * 1024 * 1024;
    h->histogram = (int*)calloc(target_size, sizeof(int));
    if (!h->histogram) {
        exit(1);
    }

    // Adjust bounds so that loop index stays within [0, target_size-1]
    h->min = 0;
    h->lowscore = target_size / 4;
    lowbound = target_size / 2;

    // Re-initialize data
    for (int idx = 0; idx < target_size; idx++) {
        h->histogram[idx] = (int)(idx % 256);
    }

    // Initialize loop counters
    i = 0;
    lowcount = 0;
}