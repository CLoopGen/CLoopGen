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
    int *hist = h->histogram;
    float *exp = h->expect;
    int base = h->min;
    int count = 0;
    int stride = 1;
    for (int sc = h->lowscore; sc <= h->highscore; sc += stride) {
        int idx = count * stride;
        int offset = sc - base;
        // Use strided access pattern: still logically valid but accesses with artificial stride
        if (exp[offset] >= 5.0f && hist[offset] >= 5) {
            delta = (float)hist[offset] - exp[offset];
            h->chisq += (delta * delta) / exp[offset];
            nbins++;
        }
        count++;
    }
}
