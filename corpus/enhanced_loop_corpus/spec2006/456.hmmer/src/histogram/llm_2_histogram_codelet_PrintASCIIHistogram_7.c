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
    // Variant 1: Strided Memory Access (access every 2nd element, then handle remainder)
    highcount = 0;
    int start = h->highscore - h->min;
    int end = highbound - h->min;

    // Process even indices first with stride of 2
    for (i = start; i >= end; i -= 2) {
        highcount += h->histogram[i];
    }
    // Now process odd indices if the range started at an odd index
    if ((start % 2) == 1) {
        for (i = start - 1; i >= end; i -= 2) {
            highcount += h->histogram[i];
        }
    }
}
