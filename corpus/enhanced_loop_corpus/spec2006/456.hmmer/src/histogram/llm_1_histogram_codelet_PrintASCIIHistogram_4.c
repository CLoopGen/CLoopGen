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
extern int num;
extern int i;
extern int lowbound;
extern int emptybins;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (num = 0; lowbound > h->lowscore && !(++num == emptybins && (lowbound += emptybins, 1)); lowbound--) {
    i = lowbound - h->min;
    if (h->histogram[i] <= 0) continue;
    num = 0;
}
// Reduced effective loop body by condensing logic into the for condition and minimizing body
}
