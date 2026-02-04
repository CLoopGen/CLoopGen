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
    int step = 2;
    int start = h->lowscore;
    int end = h->highscore;
    sum = 0;
    int offset = h->lowscore;
    int min = h->min;
    int* hist = h->histogram;
    float* d_ptr = d;
    float* x_ptr = x;

    // Unroll by factor of 2 to increase computational intensity per iteration
    for (int sc = start; sc <= end; sc += step) {
        // First element
        sum += hist[sc - min];
        d_ptr[sc - offset] = (float)sum / (float)h->total;
        x_ptr[sc - offset] = (float)(sc + 1);

        // Second element, if within bounds
        if (sc + 1 <= end) {
            sum += hist[sc + 1 - min];
            d_ptr[sc + 1 - offset] = (float)sum / (float)h->total;
            x_ptr[sc + 1 - offset] = (float)(sc + 2);
        }
    }

    // Handle any remaining odd element if trip count was odd
    if ((end - start + 1) % 2 == 1) {
        int sc = end;
        sum += h->histogram[sc - h->min];
        d[sc - h->lowscore] = (float)sum / (float)h->total;
        x[sc - h->lowscore] = (float)(sc + 1);
    }
}
