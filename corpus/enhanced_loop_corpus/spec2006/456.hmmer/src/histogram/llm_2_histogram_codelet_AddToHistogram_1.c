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
    // Variant 1: Strided memory access with stride of 2
    // Zeroes every second element first, then fills in the odd indices
    int stride = 2;
    for (i = 0; i < moveby; i += stride)
        h->histogram[i] = 0;
    
    for (i = 1; i < moveby; i += stride)
        h->histogram[i] = 0;
}
