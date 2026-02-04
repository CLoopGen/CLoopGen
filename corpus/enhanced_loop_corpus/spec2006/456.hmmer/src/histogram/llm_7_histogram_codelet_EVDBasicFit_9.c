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
extern float *d;
extern float *x;
extern int sum;
extern int sc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float inv_total = 1.0f / (float)h->total;
    int local_sum = 0;
    for (int i = h->highscore - h->lowscore; i >= 0; i--) {
        int sc_val = h->lowscore + i;
        local_sum += h->histogram[sc_val - h->min];
        d[i] = (float)local_sum * inv_total;
        x[i] = (float)(sc_val + 1);
    }
    sum += local_sum;
}
