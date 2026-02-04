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
extern int hsize;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (idx = 0; idx < hsize; idx++) {
        h->expect[idx] = 0.0f;
        // Add auxiliary computation to increase computational intensity
        float temp = h->param[0] + h->param[1];
        temp *= temp;
        h->chisq += temp;
    }
}
