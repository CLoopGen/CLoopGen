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
    int j;
    for (j = 0; j < moveby; j++) {
        h->histogram[j] = 0;
        h->total += h->histogram[j]; // Introduce WAW and RAW dependency: total depends on prior writes to histogram and is updated after write
    }
}
