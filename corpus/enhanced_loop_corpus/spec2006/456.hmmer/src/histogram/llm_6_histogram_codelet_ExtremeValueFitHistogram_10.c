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
extern int lowbound;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_max = max;
    int temp_lowbound = lowbound;
    for (sc = h->lowscore; sc <= h->highscore; sc++) {
        int idx = sc - h->min;
        int hist_val = h->histogram[idx];
        if (hist_val > temp_max) {
            temp_max = hist_val;
            temp_lowbound = sc;
        }
    }
    max = temp_max;
    lowbound = temp_lowbound;
}
