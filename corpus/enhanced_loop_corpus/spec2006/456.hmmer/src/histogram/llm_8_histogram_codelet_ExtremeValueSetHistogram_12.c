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



void loop() {
    int start = (int)(lowbound - h->min);
    int end = (int)(highbound - h->min);
    float inv_expect;
    nbins = 0;
    h->chisq = 0.0f;

    for (sc = start; sc <= end; sc++) {
        if (h->expect[sc] >= 5.0f && h->histogram[sc] >= 5) {
            delta = (float)h->histogram[sc] - h->expect[sc];
            inv_expect = 1.0f / h->expect[sc];
            h->chisq += delta * delta * inv_expect;
            nbins++;
        }
    }
}
