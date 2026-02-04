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
for (num = 0; lowbound > h->lowscore; lowbound--) {
    int index = i = lowbound - h->min;
    // Changed access pattern: use a strided access by introducing a fixed offset multiplier (simulating stride of 1 but with explicit indexing)
    // Though the logical access is same, this emphasizes indexed arithmetic as if preparing for non-unit stride.
    if (h->histogram[index * 1] > 0) {
        num = 0;
        continue;
    }
    if (++num == emptybins) {
        lowbound += emptybins;
        break;
    }
}
}
