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
    // Variant 2: Strided Memory Access Pattern
    // Simulate a strided access by stepping through the range with a stride of 2,
    // then filling in the gaps with a second pass if needed.
    // This variant uses a fixed stride to demonstrate non-unit access pattern.
    const int stride = 2;
    int low_offset = h->lowscore - h->lowscore;
    int high_offset = h->highscore - h->lowscore;
    sum = 0;

    // First pass: odd indices (simulate strided access)
    for (int idx = low_offset; idx <= high_offset; idx += stride) {
        int sc = h->lowscore + idx;
        sum += h->histogram[sc - h->min];
        d[idx] = (float)sum / (float)h->total;
        x[idx] = (float)(sc + 1);
    }

    // Second pass: even indices (fill in the stride)
    for (int idx = low_offset + 1; idx <= high_offset; idx += stride) {
        int sc = h->lowscore + idx;
        sum += h->histogram[sc - h->min];
        d[idx] = (float)sum / (float)h->total;
        x[idx] = (float)(sc + 1);
    }
}
