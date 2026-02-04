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
for (sc = h->lowscore; sc <= h->highscore; sc++)
    if (h->histogram[sc - h->min] > max) {
        max = h->histogram[sc - h->min];
        lowbound = sc;
    }

}
