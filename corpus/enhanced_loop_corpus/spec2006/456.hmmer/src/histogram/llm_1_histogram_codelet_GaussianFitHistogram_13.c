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
int outer_start = h->lowscore;
int outer_end = h->highscore;
int inner_start, inner_end;
sum = 0.0f;
sqsum = 0.0f;

// Simulate deeper nesting by splitting the range into two halves and using a 2-level loop
for (int block = 0; block < 2; block++) {
    if (block == 0) {
        inner_start = outer_start;
        inner_end = (outer_start + outer_end) / 2;
    } else {
        inner_start = (outer_start + outer_end) / 2 + 1;
        inner_end = outer_end;
    }
    for (sc = inner_start; sc <= inner_end; sc++) {
        delta = (float)sc + 0.5;
        sum += (float)h->histogram[sc - h->min] * delta;
        sqsum += (float)h->histogram[sc - h->min] * delta * delta;
    }
}
}
