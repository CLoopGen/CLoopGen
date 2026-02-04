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
    nbins = 0;
    h->chisq = 0.0f;
    int stride = 2;
    int aligned_end = h->highscore - (h->highscore - h->lowscore) % stride;
    
    // Unrolled loop with step size 2 to reduce trip count and increase arithmetic per iteration
    for (sc = h->lowscore; sc <= aligned_end - 1; sc += stride) {
        int idx1 = sc - h->min;
        int idx2 = sc + 1 - h->min;

        float exp1 = h->expect[idx1], exp2 = h->expect[idx2];
        float hist1 = (float)h->histogram[idx1], hist2 = (float)h->histogram[idx2];

        // Process first element
        if (exp1 >= 5.0f && hist1 >= 5.0f) {
            delta = hist1 - exp1;
            h->chisq += delta * delta / exp1;
            nbins++;
        }

        // Process second element
        if (exp2 >= 5.0f && hist2 >= 5.0f) {
            delta = hist2 - exp2;
            h->chisq += delta * delta / exp2;
            nbins++;
        }
    }

    // Handle remaining element if any
    if (sc == h->highscore) {
        int idx = sc - h->min;
        if (h->expect[idx] >= 5.0f && h->histogram[idx] >= 5.0f) {
            delta = (float)h->histogram[idx] - h->expect[idx];
            h->chisq += delta * delta / h->expect[idx];
            nbins++;
        }
    }
}
