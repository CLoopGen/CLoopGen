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
    int stride = 2;
    int adjusted_low = (int)lowbound;
    int adjusted_high = (int)highbound;
    // Process even indices first with strided access
    for (sc = adjusted_low | 1; sc <= adjusted_high; sc += stride) {
        int offset = sc - h->min;
        if (offset >= 0 && h->expect[offset] >= 5.0f && h->histogram[offset] >= 5) {
            delta = (float)h->histogram[offset] - h->expect[offset];
            h->chisq += delta * delta / h->expect[offset];
            nbins++;
        }
    }
    // Then process odd indices with same stride to simulate interleaved pattern
    for (sc = adjusted_low; sc <= adjusted_high; sc += stride) {
        int offset = sc - h->min;
        if (offset >= 0 && h->expect[offset] >= 5.0f && h->histogram[offset] >= 5) {
            delta = (float)h->histogram[offset] - h->expect[offset];
            h->chisq += delta * delta / h->expect[offset];
            nbins++;
        }
    }
}
