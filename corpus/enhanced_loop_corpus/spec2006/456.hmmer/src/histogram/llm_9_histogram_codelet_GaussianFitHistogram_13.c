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
    int stride = 4;
    int sc;
    float weight = 1.0f / (float)stride;
    float local_sum = 0.0f;
    float local_sqsum = 0.0f;

    for (sc = h->lowscore; sc <= h->highscore; sc += stride) {
        float temp_sum = 0.0f;
        float temp_sqsum = 0.0f;
        int j;
        for (j = 0; j < stride && (sc + j) <= h->highscore; j++) {
            int current_sc = sc + j;
            int idx = current_sc - h->min;
            float delta = (float)current_sc + 0.5f;
            float val = (float)h->histogram[idx];
            temp_sum += val * delta;
            temp_sqsum += val * delta * delta;
        }
        local_sum += temp_sum * weight;
        local_sqsum += temp_sqsum * weight;
    }
    sum += local_sum;
    sqsum += local_sqsum;
}
