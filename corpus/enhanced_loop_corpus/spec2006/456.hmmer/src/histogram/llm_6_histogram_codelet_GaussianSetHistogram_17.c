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
extern int sc;
extern int nbins;
extern float delta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_chisq = 0.0f;
    int temp_nbins = 0;
    int s;
    for (s = h->lowscore; s <= h->highscore; s++) {
        int idx = s - h->min;
        if (h->expect[idx] >= 5.0f && h->histogram[idx] >= 5) {
            float delta_local = (float)h->histogram[idx] - h->expect[idx];
            temp_chisq += delta_local * delta_local / h->expect[idx];
            temp_nbins++;
        }
    }
    h->chisq += temp_chisq;
    nbins += temp_nbins;
}
