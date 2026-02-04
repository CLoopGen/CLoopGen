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
    int idx = h->lowscore - h->min;
    int limit = h->highscore - h->min;
    for (; idx <= limit; idx += 2) {
        if (idx < limit + 1 && h->histogram[idx] > maxbar) {
            maxbar = h->histogram[idx];
            lowbound = idx + h->min;
        }
        if (idx + 1 <= limit && h->histogram[idx + 1] > maxbar) {
            maxbar = h->histogram[idx + 1];
            lowbound = idx + 1 + h->min;
        }
    }
}
