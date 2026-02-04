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
extern int prevsize;
extern int newsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = prevsize; i < newsize; i += step) {
        if (i < newsize) h->histogram[i] = 0;
        if (i + 1 < newsize) h->histogram[i + 1] = 0;
    }
    if (newsize % 2 == 1 && prevsize % 2 == 0) {
        h->histogram[newsize - 1] = 0;
    }
}
