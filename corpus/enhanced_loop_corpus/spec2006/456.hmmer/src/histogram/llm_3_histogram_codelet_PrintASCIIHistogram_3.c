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
extern int maxbar;
extern int i;
extern int lowbound;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int base = h->lowscore - h->min;
    int limit = h->highscore - h->min;
    int stride = 1;
    
    for (int offset = 0; base + offset <= limit; offset += stride) {
        int i = base + offset;
        int value = h->histogram[i];
        if (value > maxbar) {
            maxbar = value;
            lowbound = i + h->min;
        }
    }
}
