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



void loop() {
    int start = h->lowscore - h->min;
    int end = h->highscore - h->min;
    for (int idx = start; idx <= end; idx++) {
        if (h->expect[idx] >= 5.0f && h->histogram[idx] >= 5) {
            delta = (float)h->histogram[idx] - h->expect[idx];
            h->chisq += delta * delta / h->expect[idx];
            nbins++;
        }
    }
}
