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
    for (int stage = 0; stage < 2; stage++) {
        int start, end;
        if (stage == 0) {
            start = h->lowscore - h->min;
            end = (h->highscore - h->min) / 2;
        } else {
            start = ((h->highscore - h->min) / 2) + 1;
            end = h->highscore - h->min;
        }
        for (i = start; i <= end; i++)
            if (h->histogram[i] > maxbar) {
                maxbar = h->histogram[i];
                lowbound = i + h->min;
            }
    }
}
