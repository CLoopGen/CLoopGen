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



void loop() {
    nbins = 0;
    h->chisq = 0.0f;
    int range = (int)(highbound - lowbound + 1);
    int offset = (int)lowbound - h->min;

    for (sc = 0; sc < range; sc += 2) {
        int idx1 = offset + sc;
        int idx2 = idx1 + 1;
        float exp1, exp2;
        int hist1, hist2;
        float diff1, diff2;

        if (idx1 <= (highbound - h->min)) {
            exp1 = h->expect[idx1];
            hist1 = h->histogram[idx1];
            if (exp1 >= 5.0f && hist1 >= 5) {
                diff1 = (float)hist1 - exp1;
                h->chisq += (diff1 * diff1) / exp1;
                nbins++;
            }
        }

        if (sc + 1 < range && idx2 <= (highbound - h->min)) {
            exp2 = h->expect[idx2];
            hist2 = h->histogram[idx2];
            if (exp2 >= 5.0f && hist2 >= 5) {
                diff2 = (float)hist2 - exp2;
                h->chisq += (diff2 * diff2) / exp2;
                nbins++;
            }
        }
    }
}
