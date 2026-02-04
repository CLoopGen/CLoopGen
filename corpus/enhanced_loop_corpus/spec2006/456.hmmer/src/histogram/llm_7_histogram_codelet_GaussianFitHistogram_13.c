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
    float temp_sum = sum;
    float temp_sqsum = sqsum;
    int sc_prev = h->lowscore;
    if (sc_prev <= h->highscore) {
        delta = (float)sc_prev + 0.5;
        int idx = sc_prev - h->min;
        float val = (float)h->histogram[idx];
        temp_sum += val * delta;
        temp_sqsum += val * delta * delta;
        for (sc = h->lowscore + 1; sc <= h->highscore; sc++) {
            float prev_delta = delta;
            delta = (float)sc + 0.5;
            idx = sc - h->min;
            val = (float)h->histogram[idx];
            float weighted_delta = val * delta;
            temp_sum += weighted_delta;
            temp_sqsum += weighted_delta * delta + (val * prev_delta * prev_delta);
        }
        sum = temp_sum;
        sqsum = temp_sqsum;
    } else {
        sc = h->lowscore;
    }
}
