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
int sc1, sc2;
sum = 0.0f;
sqsum = 0.0f;
for (sc1 = h->lowscore; sc1 <= h->highscore; sc1++) {
    for (sc2 = 0; sc2 < 1; sc2++) { // Artificially nested with depth 2, single iteration
        delta = (float)sc1 + 0.5;
        sum += (float)h->histogram[sc1 - h->min] * delta;
        sqsum += (float)h->histogram[sc1 - h->min] * delta * delta;
    }
}
}
