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
int i;
int highbound;
int highcount;

void init_vars() {
    // Allocate histogram data: aim for ~64MB of integers to target ~0.01s runtime
    const size_t num_bins = 16 * 1024 * 1024; // 16M integers = 64 MB
    int *hist_data = (int*)calloc(num_bins, sizeof(int));
    
    // Initialize histogram boundaries
    h = (struct histogram_s*)malloc(sizeof(struct histogram_s));
    h->histogram = hist_data;
    h->min = 0;
    h->max = num_bins - 1;
    h->highscore = num_bins - 1;   // highest index we will access
    h->lowscore = 0;
    h->lumpsize = 1;
    h->total = 0;
    h->expect = NULL;
    h->fit_type = 0;
    h->param[0] = 0.0f;
    h->param[1] = 0.0f;
    h->param[2] = 0.0f;
    h->chisq = 0.0f;
    h->chip = 0.0f;

    // Set highbound such that we access a significant portion of the array
    // We want: i >= highbound - h->min  =>  i from (highscore-min) down to (highbound-min)
    // So highbound should be less than or equal to highscore
    highbound = h->highscore - (num_bins / 4);  // Make loop run over ~25% of range

    // Ensure no out-of-bounds access: indices from (h->highscore - h->min) down to (highbound - h->min)
    // Which is: (highscore) down to (highbound), since min=0
    // So we require: highbound >= 0 and highbound <= highscore
    if (highbound < 0) highbound = 0;

    // Initialize some histogram values in the accessed region to non-zero
    for (size_t j = highbound; j <= h->highscore; j++) {
        h->histogram[j] = (j % 100) + 1;  // ensure non-zero counts
        h->total += h->histogram[j];
    }

    // Initialize loop counters
    highcount = 0;
    i = 0;
}