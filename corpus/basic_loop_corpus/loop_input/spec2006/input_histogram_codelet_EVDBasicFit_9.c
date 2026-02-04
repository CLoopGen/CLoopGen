#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

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
float *d;
float *x;
int sum;
int sc;

void init_vars() {
    // Allocate histogram structure
    h = (struct histogram_s *)malloc(sizeof(struct histogram_s));
    
    // Set reasonable bounds
    h->min = 100;
    h->max = 1000;
    h->lowscore = h->min;
    h->highscore = h->max - 1;  // ensure valid range
    h->total = 1000000;
    h->lumpsize = 1;
    h->fit_type = 0;
    h->chisq = 0.0f;
    h->chip = 0.0f;
    h->param[0] = 0.0f;
    h->param[1] = 0.0f;
    h->param[2] = 0.0f;

    // Allocate histogram array: from min to max inclusive
    int hist_size = h->max - h->min + 1;
    h->histogram = (int *)calloc(hist_size, sizeof(int));
    
    // Initialize histogram with some values to avoid all zeros
    for (int i = 0; i < hist_size; i++) {
        h->histogram[i] = (i % 256) + 1;  // small positive values
    }

    // Size of d and x arrays based on score range
    int data_size = h->highscore - h->lowscore + 1;
    
    // Allocate d and x arrays
    d = (float *)malloc(data_size * sizeof(float));
    x = (float *)malloc(data_size * sizeof(float));
    
    // Initialize sum
    sum = 0;
}