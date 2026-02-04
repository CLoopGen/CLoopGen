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
extern int moveby;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = moveby;
    for (i = 0; i < limit; i += 2) {
        h->histogram[i] = 0;
        if (i + 1 < limit)
            h->histogram[i + 1] = 0;
    }
}
