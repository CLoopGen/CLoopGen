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



void loop(){
    float local_sum = 0.0f;
    float local_sqsum = 0.0f;
    int i;
    for (i = h->lowscore; i <= h->highscore; i++) {
        delta = (float)i + 0.5;
        int idx = i - h->min;
        float hist_val = (float)h->histogram[idx];
        local_sum += hist_val * delta;
        local_sqsum += hist_val * delta * delta;
    }
    sum += local_sum;
    sqsum += local_sqsum;
}
