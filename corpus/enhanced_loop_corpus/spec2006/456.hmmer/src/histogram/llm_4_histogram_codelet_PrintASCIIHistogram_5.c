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
extern int num;
extern int i;
extern int highbound;
extern int emptybins;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (num = 0; highbound < h->highscore; highbound++) {
    i = highbound - h->min;
    if (h->histogram[i] <= 0) {
        if (++num == emptybins) {
            highbound -= emptybins;
            break;
        }
    } else {
        num = 0;
    }
}
}
