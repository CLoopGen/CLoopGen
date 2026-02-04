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
extern float delta;
extern int sc;
extern int nbins;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int sc1, sc2;
    nbins = 0;
    h->chisq = 0.0f;
    for (sc1 = h->lowscore; sc1 <= h->highscore; sc1 += 2) {
        for (sc2 = 0; sc2 < 2; sc2++) {
            sc = sc1 + sc2;
            if (sc > h->highscore) break;
            if (h->expect[sc - h->min] >= 5. && h->histogram[sc - h->min] >= 5) {
                delta = (float)h->histogram[sc - h->min] - h->expect[sc - h->min];
                h->chisq += delta * delta / h->expect[sc - h->min];
                nbins++;
            }
        }
    }
}
