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
    lowcount = 0;
    for (i = h->lowscore - h->min; i <= lowbound - h->min; i += 2) {
        int val1 = h->histogram[i];
        int val2 = (i + 1 <= lowbound - h->min) ? h->histogram[i + 1] : 0;
        lowcount += val1 + val2;
    }
}
