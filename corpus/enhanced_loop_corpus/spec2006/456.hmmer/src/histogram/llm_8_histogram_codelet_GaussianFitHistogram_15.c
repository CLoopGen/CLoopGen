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
    int start = h->lowscore;
    int end = h->highscore;
    int min_val = h->min;
    float *expect_ptr = h->expect;
    int *histogram_ptr = h->histogram;
    float chisq_local = h->chisq;
    int nbins_local = nbins;

    for (sc = start; sc <= end; sc += 2) {
        int idx = sc - min_val;
        if (expect_ptr[idx] >= 5.0f && histogram_ptr[idx] >= 5) {
            delta = (float)histogram_ptr[idx] - expect_ptr[idx];
            chisq_local += delta * delta / expect_ptr[idx];
            nbins_local++;
        }
        if (sc + 1 <= end) {
            idx = sc + 1 - min_val;
            if (expect_ptr[idx] >= 5.0f && histogram_ptr[idx] >= 5) {
                delta = (float)histogram_ptr[idx] - expect_ptr[idx];
                chisq_local += delta * delta / expect_ptr[idx];
                nbins_local++;
            }
        }
    }

    h->chisq = chisq_local;
    nbins = nbins_local;
}
