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
    if (hsize > 0) {
        for (int i = 0; i < hsize; i += 8) {
            int end = (i + 8 < hsize) ? i + 8 : hsize;
            for (int j = i; j < end; j++) {
                h->expect[j] = 0.;
            }
        }
    }
}
