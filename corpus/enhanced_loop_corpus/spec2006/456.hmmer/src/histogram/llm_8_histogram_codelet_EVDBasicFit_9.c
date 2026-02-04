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
    int start = h->lowscore;
    int end = h->highscore;
    int base = h->lowscore - h->min;
    int total_inv = h->total;
    sum = 0; // Ensure sum starts at 0 as likely intent
    for (int i = start; i <= end; i++) {
        int idx = i + base - h->lowscore;
        sum += h->histogram[i - h->min];
        d[i - h->lowscore] = (float)sum * (1.0f / total_inv);
        x[i - h->lowscore] = (float)(i + 1);
    }
}
