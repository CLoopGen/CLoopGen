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
    if (hsize > 0) {
        idx = 0;
        for (int block = 0; block < hsize; block += 1) {
            h->expect[idx] = 0.;
            idx++;
        }
    }
}
