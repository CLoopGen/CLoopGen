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
extern int i;
extern int highbound;
extern int highcount;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    highcount = 0;
    int start = h->highscore - h->min;
    int end = highbound - h->min;
    for (i = start; i >= end; i -= 2) {
        highcount += h->histogram[i];
        if (i - 1 >= end) {
            highcount += h->histogram[i - 1];
        }
    }
}
