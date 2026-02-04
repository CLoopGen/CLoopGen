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
int num;
int i;
int highbound;
int emptybins;

void init_vars() {
    // Allocate histogram data with ~64MB of integers (16M ints)
    const int data_size = 16 * 1024 * 1024;
    
    int *histogram_data = (int*)calloc(data_size, sizeof(int));
    
    // Set up parameters to ensure valid access and meaningful loop execution
    h = (struct histogram_s*)malloc(sizeof(struct histogram_s));
    h->histogram = histogram_data;
    h->min = 1000000;  // offset into the array
    h->max = data_size - 1;
    h->highscore = h->min + 500000;  // ensures highbound starts below highscore
    h->lumpsize = 10;
    h->total = 0;
    h->fit_type = 0;
    h->chisq = 0.0f;
    h->chip = 0.0f;
    
    // Allocate expect array to avoid dangling pointer
    h->expect = (float*)calloc(data_size, sizeof(float));
    
    // Initialize some non-zero values in histogram after a gap
    int gap_start = h->min + 100000;
    for (int j = 0; j < 100; j++) {
        histogram_data[gap_start + j] = (j % 10) + 1;
    }
    
    // Set up emptybins so that we have to scan through many zeros
    emptybins = 50;
    
    // Initialize loop variables
    num = 0;
    highbound = h->min + 100;  // Start within valid range but before filled region
}

// Definitions of external variables
struct histogram_s *h;
int num;
int i;
int highbound;
int emptybins;