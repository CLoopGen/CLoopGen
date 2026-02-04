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
    int sc_forward, sc_backward;
    float delta_forward = 0.0f, delta_backward = 0.0f;
    int nbins_temp = 0;

    // Forward and backward unrolled-like traversal to create WAW and WAR dependencies on delta
    for (sc_forward = h->lowscore, sc_backward = h->highscore; 
         sc_forward <= h->highscore; 
         sc_forward++, sc_backward--) {
        
        int idx_forward = sc_forward - h->min;
        int idx_backward = sc_backward - h->min;

        // Process forward index
        if (h->expect[idx_forward] >= 5. && h->histogram[idx_forward] >= 5) {
            delta = (float)h->histogram[idx_forward] - h->expect[idx_forward];
            delta_forward = delta * delta / h->expect[idx_forward]; // WAR: delta used after write
            h->chisq += delta_forward;
            nbins_temp++;
        }

        // Process backward index (except middle duplicate in odd-sized ranges)
        if (sc_backward > sc_forward && h->expect[idx_backward] >= 5. && h->histogram[idx_backward] >= 5) {
            delta = (float)h->histogram[idx_backward] - h->expect[idx_backward]; // WAW: delta overwritten
            delta_backward = delta * delta / h->expect[idx_backward];
            h->chisq += delta_backward;
            nbins_temp++;
        }
    }
    nbins += nbins_temp;
}
