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
extern int lowbound;
extern int emptybins;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
num = 0;
for (; lowbound > h->lowscore; ) {
    i = lowbound - h->min;
    if (h->histogram[i] > 0) {
        num = 0;
    } else if (++num >= emptybins) {
        lowbound += emptybins;
        break;
    }
    lowbound--;
}
}
