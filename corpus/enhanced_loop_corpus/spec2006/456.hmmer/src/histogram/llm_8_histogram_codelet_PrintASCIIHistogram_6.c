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
extern int i;
extern int lowbound;
extern int lowcount;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = h->lowscore - h->min;
    int end = lowbound - h->min;
    lowcount = 0;
    for (i = start; i <= end; i += 2) {
        lowcount += h->histogram[i];
        if (i + 1 <= end) {
            lowcount += h->histogram[i + 1];
        }
    }
}
