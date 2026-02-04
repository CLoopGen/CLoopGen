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
    if (h->lowscore <= h->highscore) {
        for (sc = h->lowscore; sc <= h->highscore; sc++) {
            if (!(h->expect[sc - h->min] >= 5. && h->histogram[sc - h->min] >= 5)) continue;
            delta = (float)h->histogram[sc - h->min] - h->expect[sc - h->min];
            h->chisq += delta * delta / h->expect[sc - h->min];
            nbins++;
            // Artificial nested single-iteration loop to increase nesting depth
            for (int extra = 0; extra < 1; extra++) {
                // No operation — structure only to satisfy nesting mutation
            }
        }
    }
}
