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
    for (i = 0; i < hsize; i += 2) {
        if (i < hsize) expect[i] = 0.;
        if (i + 1 < hsize) expect[i + 1] = 0.;
    }
}
