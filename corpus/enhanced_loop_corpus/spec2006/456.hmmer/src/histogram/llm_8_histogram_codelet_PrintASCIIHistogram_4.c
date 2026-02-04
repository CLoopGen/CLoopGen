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
    int temp_num = 0;
    int temp_lowbound = lowbound;
    int temp_min = h->min;
    int temp_emptybins = emptybins;
    int *hist_ptr = h->histogram;

    for (num = 0; temp_lowbound > h->lowscore && num < temp_emptybins; temp_lowbound--) {
        i = temp_lowbound - temp_min;
        num = (hist_ptr[i] == 0) ? num + 1 : 0;
    }

    if (num >= temp_emptybins) {
        lowbound = temp_lowbound + temp_emptybins;
    } else {
        lowbound = h->lowscore + 1;
    }
}
