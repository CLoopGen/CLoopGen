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
    int *hist = h->histogram;
    float *exp = h->expect;
    int base = h->min;
    int count = (h->highscore - h->lowscore + 1);
    for (int i = 0; i < count; i++) {
        int sc_val = h->lowscore + i;
        int idx = sc_val - base;
        if (exp[idx] >= 5.0f && hist[idx] >= 5) {
            delta = (float)hist[idx] - exp[idx];
            h->chisq += delta * delta / exp[idx];
            nbins++;
        }
    }
}
