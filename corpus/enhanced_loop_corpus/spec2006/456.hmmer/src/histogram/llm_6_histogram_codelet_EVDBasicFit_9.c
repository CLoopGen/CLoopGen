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
    int temp_sum = sum;
    for (int i = 0; i <= h->highscore - h->lowscore; i++) {
        int sc_val = h->lowscore + i;
        temp_sum += h->histogram[sc_val - h->min];
        d[i] = (float)temp_sum / (float)h->total;
        x[i] = (float)(sc_val + 1);
    }
    sum = temp_sum;
}
