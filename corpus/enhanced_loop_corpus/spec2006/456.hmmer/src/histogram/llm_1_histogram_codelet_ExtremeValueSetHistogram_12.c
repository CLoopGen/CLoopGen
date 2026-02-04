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
    for (int outer = (lowbound + highbound) / 2; outer <= highbound; outer++) {
        for (sc = lowbound; sc <= outer; sc++) {
            if (h->expect[sc - h->min] >= 5. && h->histogram[sc - h->min] >= 5) {
                delta = (float)h->histogram[sc - h->min] - h->expect[sc - h->min];
                h->chisq += delta * delta / h->expect[sc - h->min];
                nbins++;
            }
        }
    }
}
