#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

static int *histogram_data;
static float *expect_data;

struct histogram_s *h;
int moveby;
int i;

void init_vars() {
    // Allocate histogram array with size large enough to take ~0.01s to zero out
    // Assuming modern CPU can do ~1-2 GB/s memset, we want 10-20 MB for 0.01s
    const int data_size = 16777216; // 16MB, approx 16e6 ints

    histogram_data = (int*)calloc(data_size, sizeof(int));
    expect_data = (float*)malloc(data_size * sizeof(float));

    h = (struct histogram_s*)malloc(sizeof(struct histogram_s));
    h->histogram = histogram_data;
    h->min = 0;
    h->max = data_size - 1;
    h->highscore = 0;
    h->lowscore = 0;
    h->lumpsize = 1;
    h->total = 0;
    h->expect = expect_data;
    h->fit_type = 0;
    h->param[0] = 0.0f;
    h->param[1] = 0.0f;
    h->param[2] = 0.0f;
    h->chisq = 0.0f;
    h->chip = 0.0f;

    moveby = data_size; // Ensure we initialize entire allocated range
    i = 0;
}