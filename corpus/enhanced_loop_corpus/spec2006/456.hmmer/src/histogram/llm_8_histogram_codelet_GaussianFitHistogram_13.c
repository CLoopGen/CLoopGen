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
    int start = h->lowscore;
    int end = h->highscore;
    int range = end - start + 1;
    int i;
    float local_sum = 0.0f;
    float local_sqsum = 0.0f;

    for (i = 0; i < range; i += 2) {
        int sc1 = start + i;
        int idx1 = sc1 - h->min;
        float delta1 = (float)sc1 + 0.5f;
        float hist_val1 = (float)h->histogram[idx1];
        local_sum += hist_val1 * delta1;
        local_sqsum += hist_val1 * delta1 * delta1;

        if (i + 1 < range) {
            int sc2 = start + i + 1;
            int idx2 = sc2 - h->min;
            float delta2 = (float)sc2 + 0.5f;
            float hist_val2 = (float)h->histogram[idx2];
            local_sum += hist_val2 * delta2;
            local_sqsum += hist_val2 * delta2 * delta2;
        }
    }
    sum += local_sum;
    sqsum += local_sqsum;
}
