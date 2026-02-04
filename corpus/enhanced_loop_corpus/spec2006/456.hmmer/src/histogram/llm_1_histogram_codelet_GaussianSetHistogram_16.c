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
    for (int outer = 0; outer < hsize / 10 + 1; outer++) {
        for (int inner = 0; inner < 10; inner++) {
            idx = outer * 10 + inner;
            if (idx < hsize) {
                h->expect[idx] = 0.;
            }
        }
    }
}
