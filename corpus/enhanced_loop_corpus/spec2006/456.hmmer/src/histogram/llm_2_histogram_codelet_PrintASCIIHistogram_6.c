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
    // Variant 1: Strided memory access with stride of 2, processing every second element
    // This changes the access pattern from consecutive to strided, reducing frequency of access
    lowcount = 0;
    for (i = h->lowscore - h->min; i <= lowbound - h->min; i += 2) {
        lowcount += h->histogram[i];
        // Handle odd indices if range includes them
        if (i + 1 <= lowbound - h->min) {
            lowcount += h->histogram[i + 1];
        }
    }
}
