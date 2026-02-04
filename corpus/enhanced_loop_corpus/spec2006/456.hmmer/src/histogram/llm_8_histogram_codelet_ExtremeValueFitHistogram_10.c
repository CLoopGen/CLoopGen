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
    int i;
    max = -1;
    lowbound = h->lowscore;
    for (sc = h->lowscore; sc <= h->highscore; sc += 2) {
        int idx = sc - h->min;
        if (idx >= 0 && h->histogram[idx] > max) {
            max = h->histogram[idx];
            lowbound = sc;
        }
        if (sc + 1 <= h->highscore) {
            int idx2 = (sc + 1) - h->min;
            if (idx2 >= 0 && h->histogram[idx2] > max) {
                max = h->histogram[idx2];
                lowbound = sc + 1;
            }
        }
    }
}
