#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
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
int sc;
int nbins;
float delta;

void init_vars() {
    // Allocate histogram and expect arrays with ~64k elements to ensure loop runtime around 0.01s
    const int arr_size = 65536;
    
    h = (struct histogram_s*)malloc(sizeof(struct histogram_s));
    h->histogram = (int*)malloc(arr_size * sizeof(int));
    h->expect = (float*)malloc(arr_size * sizeof(float));
    
    // Initialize array contents
    for (int i = 0; i < arr_size; i++) {
        h->histogram[i] = 10 + (i % 15);  // Ensure >=5 for many entries
        h->expect[i] = 8.0f + (i % 12);   // Ensure >=5
    }
    
    // Set bounds within allocated range
    h->min = 0;
    h->max = arr_size - 1;
    h->lowscore = 1000;           // Start within valid range
    h->highscore = 50000;         // End before upper bound
    h->lumpsize = 1;
    h->total = 0;
    h->fit_type = 0;
    h->param[0] = 0.0f;
    h->param[1] = 0.0f;
    h->param[2] = 0.0f;
    h->chisq = 0.0f;
    h->chip = 0.0f;
    
    sc = 0;
    nbins = 0;
    delta = 0.0f;
}