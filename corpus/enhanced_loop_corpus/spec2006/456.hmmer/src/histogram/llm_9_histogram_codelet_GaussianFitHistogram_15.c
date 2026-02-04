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
extern float delta;
extern int sc;
extern int nbins;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float chisq_local = 0.0f;
    int nbins_local = 0;
    int base = h->min;
    int low = h->lowscore;
    int high = h->highscore;

    for (sc = low; sc <= high; sc++) {
        int idx = sc - base;
        float expected_val = h->expect[idx];
        int observed_val = h->histogram[idx];

        if (expected_val >= 5.0f && observed_val >= 5) {
            float diff = (float)observed_val - expected_val;
            float term = (diff * diff) / expected_val;
            chisq_local += term;
            nbins_local++;
        }
    }

    h->chisq += chisq_local;
    nbins += nbins_local;
}
