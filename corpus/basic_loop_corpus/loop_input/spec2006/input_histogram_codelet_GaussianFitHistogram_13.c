#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
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

struct histogram_s *h;
float sum;
float sqsum;
float delta;
int sc;

static int *g_histogram_data = NULL;
static float *g_expect_data = NULL;

void init_vars() {
    // Allocate and initialize the histogram data
    const int data_size_mb = 64; // Target ~64MB of histogram data
    const int total_elements = (data_size_mb * 1024 * 1024) / sizeof(int);
    
    g_histogram_data = (int*)calloc(total_elements, sizeof(int));
    if (!g_histogram_data) {
        exit(1);
    }
    
    g_expect_data = (float*)malloc(total_elements * sizeof(float));
    if (!g_expect_data) {
        free(g_histogram_data);
        exit(1);
    }

    // Initialize histogram with non-zero values to ensure meaningful computation
    for (int i = 0; i < total_elements; i++) {
        g_histogram_data[i] = (i % 256) + 1;
        g_expect_data[i] = (float)(i % 100) / 10.0f;
    }

    // Set up histogram_s structure
    h = (struct histogram_s*)malloc(sizeof(struct histogram_s));
    if (!h) {
        free(g_histogram_data);
        free(g_expect_data);
        exit(1);
    }

    h->min = 100;
    h->max = h->min + total_elements - 1;
    h->lowscore = h->min + 1000;
    h->highscore = h->max - 1000;
    h->lumpsize = 1;
    h->total = 0;
    for (int i = h->lowscore - h->min; i <= h->highscore - h->min; i++) {
        h->total += g_histogram_data[i];
    }
    h->fit_type = 0;
    h->chisq = 0.0f;
    h->chip = 0.0f;
    h->param[0] = 1.0f;
    h->param[1] = 2.0f;
    h->param[2] = 3.0f;
    h->histogram = g_histogram_data;
    h->expect = g_expect_data;

    // Initialize global accumulators
    sum = 0.0f;
    sqsum = 0.0f;
    delta = 0.0f;
    sc = 0;
}