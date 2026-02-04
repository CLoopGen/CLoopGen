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



void loop() {
    int *hist = h->histogram;
    int min_val = h->min;
    int highscore = h->highscore;
    int lowscore = h->lowscore;
    
    for (int idx = 0; idx <= highscore - lowscore; idx++) {
        int i = lowscore - min_val + idx;
        if (hist[i] > maxbar) {
            maxbar = hist[i];
            lowbound = i + min_val;
        }
    }
}
