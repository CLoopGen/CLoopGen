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



void loop(){
    int start = h->lowscore - h->min;
    int end = h->highscore - h->min;
    int stride = 4;
    for (i = start; i <= end; i++) {
        int adjusted_i = i;
        for (int j = 0; j < stride && (adjusted_i = start + (i * stride + j)) <= end; j++) {
            if (h->histogram[adjusted_i] > maxbar) {
                maxbar = h->histogram[adjusted_i];
                lowbound = adjusted_i + h->min;
            }
        }
        i = adjusted_i; // Skip processed indices
    }
}
