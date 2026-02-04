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
    for (i = h->lowscore - h->min; i <= h->highscore - h->min; i++) {
        if (!(h->histogram[i] > maxbar)) {
            continue;
        }
        maxbar = h->histogram[i];
        lowbound = i + h->min;
    }
}
