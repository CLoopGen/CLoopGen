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
extern int highbound;
extern int highcount;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Forward Access using reversed bounds and forward loop
    highcount = 0;
    int start = highbound - h->min;
    int end = h->highscore - h->min;

    // Traverse the same elements but in reverse order by flipping loop direction
    // and accessing consecutive memory locations forward to improve cache locality
    for (i = start; i <= end; i++) {
        highcount += h->histogram[end + start - i]; // Mirror index to maintain original access order logically
    }
}
