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



void loop() {
    for (sc = h->lowscore; sc <= h->highscore; sc++) {
        int idx = sc - h->min;
        if (h->expect[idx] < 5.0f) continue;
        if (h->histogram[idx] < 5) continue;
        delta = (float)h->histogram[idx] - h->expect[idx];
        float exp_val = h->expect[idx];
        h->chisq += (delta * delta) / exp_val;
        nbins++;
    }
}
