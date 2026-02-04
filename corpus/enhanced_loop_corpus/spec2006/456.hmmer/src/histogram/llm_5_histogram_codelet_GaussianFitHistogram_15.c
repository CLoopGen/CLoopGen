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
nbins = 0;
h->chisq = 0.0f;
int idx;
for (sc = h->lowscore; sc <= h->highscore; sc++) {
    idx = sc - h->min;
    delta = (float)h->histogram[idx] - h->expect[idx];
    if (!(h->expect[idx] >= 5. && h->histogram[idx] >= 5)) {
        goto next_iteration;
    }
    h->chisq += delta * delta / h->expect[idx];
    nbins++;
next_iteration:;
}
}
