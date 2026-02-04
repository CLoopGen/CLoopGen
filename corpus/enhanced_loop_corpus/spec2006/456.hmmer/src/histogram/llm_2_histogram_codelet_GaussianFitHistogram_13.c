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
extern float sum;
extern float sqsum;
extern float delta;
extern int sc;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int start = h->lowscore - h->min;
    int end = h->highscore - h->min;
    float *hist = (float *)h->histogram;
    for (int idx = start; idx <= end; idx++) {
        float delta_val = (float)(idx + h->min) + 0.5f;
        sum += hist[idx] * delta_val;
        sqsum += hist[idx] * delta_val * delta_val;
    }
}
