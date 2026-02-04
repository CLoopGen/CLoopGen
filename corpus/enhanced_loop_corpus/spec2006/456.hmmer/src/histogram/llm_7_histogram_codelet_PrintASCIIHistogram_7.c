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
    for (int idx = h->highscore - h->min; idx >= highbound - h->min; idx--) {
        highcount += (idx == h->highscore - h->min) ? h->histogram[idx] : h->histogram[idx] + h->histogram[idx + 1];
    }
    if ((h->highscore - h->min) > (highbound - h->min)) {
        highcount -= h->histogram[h->highscore - h->min + 1]; // Compensate for over-addition in last iteration
    }
}
