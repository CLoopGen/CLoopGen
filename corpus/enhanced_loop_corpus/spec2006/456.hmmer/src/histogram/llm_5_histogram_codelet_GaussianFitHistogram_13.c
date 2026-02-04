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
extern float sum;
extern float sqsum;
extern float delta;
extern int sc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (sc = h->lowscore; sc <= h->highscore; sc++) {
    delta = (float)sc + 0.5;
    int idx = sc - h->min;
    if (idx >= 0) {
        sum += (float)h->histogram[idx] * delta;
        sqsum += (float)h->histogram[idx] * delta * delta;
    }
}
}
