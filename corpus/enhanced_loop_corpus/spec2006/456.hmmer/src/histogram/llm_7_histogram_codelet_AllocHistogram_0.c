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
extern int newsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *hist = h->histogram;
    int prev = 0;
    for (i = 0; i < newsize; i++) {
        hist[i] = prev;
        prev = 0;
    }
}
