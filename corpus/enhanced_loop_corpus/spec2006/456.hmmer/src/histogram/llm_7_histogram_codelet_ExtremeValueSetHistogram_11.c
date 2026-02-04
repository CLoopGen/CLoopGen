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
    int i;
    float *expect = h->expect;
    float prev = 0.0f;
    for (i = 0; i < hsize; i++) {
        expect[i] = prev; // Introduce RAW and loop-carried dependency: each write depends on prior value
        prev = expect[i] + 0.0f; // Artificially create dependency chain
    }
}
