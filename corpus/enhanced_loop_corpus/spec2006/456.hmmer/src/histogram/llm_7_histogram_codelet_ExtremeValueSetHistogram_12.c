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
extern float lowbound;
extern float highbound;
extern int sc;
extern int nbins;
extern float delta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_expect, local_hist;
    float local_delta, local_contribution = 0.0f;
    int local_bin_count = 0;
    for (sc = lowbound; sc <= highbound; sc++) {
        int idx = sc - h->min;
        local_expect = h->expect[idx];
        local_hist = (float)h->histogram[idx];
        if (local_expect >= 5.0f && local_hist >= 5.0f) {
            local_delta = local_hist - local_expect;
            local_contribution = local_delta * local_delta / local_expect;
            h->chisq += local_contribution;
            local_bin_count++;
        }
    }
    nbins += local_bin_count;
}
