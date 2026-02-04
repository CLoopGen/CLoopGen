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
    int local_max = -1;
    int local_lowbound = h->lowscore;
    int start = h->lowscore - h->min;
    int end = h->highscore - h->min;
    for (int offset = start; offset <= end; offset++) {
        int value = h->histogram[offset];
        int candidate_sc = offset + h->min;
        if (value > local_max && candidate_sc >= h->lowscore && candidate_sc <= h->highscore) {
            local_max = value;
            local_lowbound = candidate_sc;
        }
    }
    max = local_max;
    lowbound = local_lowbound;
}
