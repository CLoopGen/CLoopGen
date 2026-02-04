#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

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

struct histogram_s *h;
int maxbar;
int i;
int lowbound;

static int *alloc_histogram;
static float *alloc_expect;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of int data for ~0.01s runtime target

    alloc_histogram = (int*)calloc(data_size, sizeof(int));
    if (!alloc_histogram) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    alloc_expect = (float*)calloc(data_size, sizeof(float));
    if (!alloc_expect) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    h = (struct histogram_s*)malloc(sizeof(struct histogram_s));
    if (!h) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    h->histogram = alloc_histogram;
    h->expect = alloc_expect;

    h->min = 1000;
    h->max = data_size - 1;
    h->lowscore = 2000;
    h->highscore = data_size / 2;
    h->lumpsize = 1;
    h->total = 0;
    h->fit_type = 0;
    h->param[0] = 0.0f;
    h->param[1] = 1.0f;
    h->param[2] = 0.5f;
    h->chisq = 0.0f;
    h->chip = 0.0f;

    maxbar = 0;
    lowbound = 0;

    for (size_t idx = h->lowscore - h->min; idx <= (size_t)(h->highscore - h->min); idx++) {
        h->histogram[idx] = (int)(rand() % 1000);
    }
}