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
    float temp_chisq = 0.0f;
    int temp_nbins = 0;
    int i;
    for (i = 0; i <= highbound - lowbound; i++) {
        sc = lowbound + i;
        if (h->expect[sc - h->min] >= 5.0f && h->histogram[sc - h->min] >= 5) {
            delta = (float)h->histogram[sc - h->min] - h->expect[sc - h->min];
            temp_chisq += delta * delta / h->expect[sc - h->min];
            temp_nbins++;
        }
    }
    h->chisq += temp_chisq;
    nbins += temp_nbins;
}
