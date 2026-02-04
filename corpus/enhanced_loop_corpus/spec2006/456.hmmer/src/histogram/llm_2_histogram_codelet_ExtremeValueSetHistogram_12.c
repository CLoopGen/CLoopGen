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
extern float lowbound;
extern float highbound;
extern int sc;
extern int nbins;
extern float delta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = (int)(lowbound - h->min);
    int end = (int)(highbound - h->min);
    for (int idx = start; idx <= end; idx++) {
        if (h->expect[idx] >= 5.0f && h->histogram[idx] >= 5) {
            float delta_local = (float)h->histogram[idx] - h->expect[idx];
            h->chisq += delta_local * delta_local / h->expect[idx];
            nbins++;
        }
    }
}
