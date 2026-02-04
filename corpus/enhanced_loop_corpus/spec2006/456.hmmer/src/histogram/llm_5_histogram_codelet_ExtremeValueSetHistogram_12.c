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
for (sc = lowbound; sc <= highbound; sc++) {
    int index = sc - h->min;
    float exp_val = h->expect[index];
    int hist_val = h->histogram[index];

    if (exp_val < 5.0f) {
        continue;
    }
    if (hist_val < 5) {
        continue;
    }

    delta = (float)hist_val - exp_val;
    h->chisq += (delta * delta) / exp_val;
    nbins++;
}
}
