#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
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
int num;
int i;
int lowbound;
int emptybins;

void init_vars() {
    // Allocate histogram structure
    h = (struct histogram_s *)calloc(1, sizeof(struct histogram_s));
    
    // Define data size: aim for moderate memory footprint (~4-8 MB for int array)
    const int DATA_SIZE = 2 * 1024 * 1024; // 2 million elements
    
    h->min = 1000;
    h->max = h->min + DATA_SIZE - 1;
    h->lowscore = h->min + DATA_SIZE / 4;   // Start scanning from quarter point
    h->highscore = h->max - 100;
    
    // Ensure lowbound starts above lowscore to enter loop
    lowbound = h->lowscore + 500;
    
    // Set emptybins threshold
    emptybins = 100;
    
    // Allocate and initialize histogram array
    h->histogram = (int *)calloc(DATA_SIZE, sizeof(int));
    
    // Initialize most bins to zero, but set some non-zero values near the end
    // to ensure loop eventually breaks without underflow
    int start_nonzero = DATA_SIZE - 1000;
    for (int idx = start_nonzero; idx < DATA_SIZE; idx++) {
        h->histogram[idx] = (idx % 7) ? 0 : 1; // Sparse non-zero pattern
    }
    
    // Initialize remaining fields
    h->lumpsize = 1;
    h->total = 0;
    h->fit_type = 0;
    h->chisq = 0.0f;
    h->chip = 0.0f;
    memset(h->param, 0, sizeof(h->param));
    
    // Allocate expect array same size as histogram (not used in loop, but complete struct)
    h->expect = (float *)calloc(DATA_SIZE, sizeof(float));
    
    // Initialize loop counters
    num = 0;
    i = 0;
}