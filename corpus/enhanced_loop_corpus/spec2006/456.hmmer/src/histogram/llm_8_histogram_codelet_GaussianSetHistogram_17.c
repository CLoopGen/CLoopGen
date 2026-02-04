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
extern int sc;
extern int nbins;
extern float delta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = h->lowscore;
    int end = h->highscore;
    float inv_expect;
    nbins = 0;
    h->chisq = 0.0f;
    for (sc = start; sc <= end; sc++) {
        int idx = sc - h->min;
        float hist_val = (float)h->histogram[idx];
        float exp_val = h->expect[idx];
        if (exp_val >= 5.0f && hist_val >= 5.0f) {
            delta = hist_val - exp_val;
            inv_expect = 1.0f / exp_val;
            h->chisq += delta * delta * inv_expect;
            nbins++;
        }
    }
}
