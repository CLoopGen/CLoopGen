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
    int local_max = max;
    int local_lowbound = lowbound;
    int i;
    for (i = 0; i <= h->highscore - h->lowscore; i++) {
        sc = h->lowscore + i;
        int offset = sc - h->min;
        if (h->histogram[offset] > local_max) {
            local_max = h->histogram[offset];
            local_lowbound = sc;
        }
    }
    max = local_max;
    lowbound = local_lowbound;
    sc = h->lowscore + (h->highscore - h->lowscore); // Ensure sc ends at highscore
}
