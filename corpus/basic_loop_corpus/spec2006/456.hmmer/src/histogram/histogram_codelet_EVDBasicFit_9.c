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
for (sc = h->lowscore; sc <= h->highscore; sc++) {
    sum += h->histogram[sc - h->min];
    d[sc - h->lowscore] = (float)sum / (float)h->total;
    x[sc - h->lowscore] = (float)(sc + 1);
}

}
