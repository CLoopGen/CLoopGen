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
    int sc_forward, sc_backward;
    float delta_forward = 0.0f, delta_backward = 0.0f;
    int nbins_temp = 0;
    int mid = (h->lowscore + h->highscore) / 2;

    for (sc_forward = h->lowscore, sc_backward = h->highscore;
         sc_forward <= mid || sc_backward > mid;
         sc_forward++, sc_backward--) {

        if (sc_forward <= mid) {
            int idx_forward = sc_forward - h->min;
            if (h->expect[idx_forward] >= 5. && h->histogram[idx_forward] >= 5) {
                delta_forward = (float)h->histogram[idx_forward] - h->expect[idx_forward];
                h->chisq += delta_forward * delta_forward / h->expect[idx_forward];
                nbins++;
            }
        }

        if (sc_backward > mid) {
            int idx_backward = sc_backward - h->min;
            if (h->expect[idx_backward] >= 5. && h->histogram[idx_backward] >= 5) {
                delta_backward = (float)h->histogram[idx_backward] - h->expect[idx_backward];
                h->chisq += delta_backward * delta_backward / h->expect[idx_backward];
                nbins++;
            }
        }
    }
}
