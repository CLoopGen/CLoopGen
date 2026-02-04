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
extern int maxbar;
extern int i;
extern int lowbound;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_maxbar = maxbar;
    int temp_lowbound = lowbound;
    int start = h->lowscore - h->min;
    int end = h->highscore - h->min;
    for (int idx = start; idx <= end; idx++) {
        int val = h->histogram[idx];
        if (val > temp_maxbar) {
            temp_maxbar = val;
            temp_lowbound = idx + h->min;
        }
    }
    maxbar = temp_maxbar;
    lowbound = temp_lowbound;
}
