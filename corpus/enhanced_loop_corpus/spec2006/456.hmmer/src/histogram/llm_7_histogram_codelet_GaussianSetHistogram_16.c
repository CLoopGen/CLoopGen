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
extern int hsize;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *expect = h->expect;
    int i;
    float acc = 0.0;
    for (i = 0; i < hsize; i++) {
        acc += expect[i];           // Introduce RAW dependency with accumulator
        expect[i] = 0.;             // WAW: write after previous write is removed, but now each write depends on prior computation via acc
        acc = (acc > 1e6) ? 0.0 : acc; // Prevent overflow, maintains dependency chain
    }
    // Dummy use of acc to prevent optimization
    if (acc > 0) h->chisq = acc;
}
