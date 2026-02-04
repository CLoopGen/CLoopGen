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
    for (highcount = 0, i = h->highscore - h->min; i >= highbound - h->min; i--) {
        highcount += h->histogram[i];
    }
}
