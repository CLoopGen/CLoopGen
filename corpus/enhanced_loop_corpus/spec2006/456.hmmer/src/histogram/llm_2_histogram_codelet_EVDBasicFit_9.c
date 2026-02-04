#include <stdio.h>

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


extern struct histogram_s *h;
extern float *d;
extern float *x;
extern int sum;
extern int sc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing h->histogram with offset (sc - h->min), we precompute the base pointer
    // and use consecutive indexing. Similarly, d and x are accessed consecutively via a local index.
    int base = h->lowscore - h->min;
    int start = h->lowscore - h->lowscore;
    int end = h->highscore - h->lowscore;
    sum = 0; // Ensure sum starts correctly
    for (int i = 0; i <= end - start; i++) {
        int sc = h->lowscore + i;
        sum += h->histogram[base + i];
        d[i] = (float)sum / (float)h->total;
        x[i] = (float)(sc + 1);
    }
}
