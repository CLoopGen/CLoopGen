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
    int temp_num = 0;
    for (num = 0; highbound < h->highscore && temp_num < emptybins; highbound++) {
        i = (highbound - h->min) * h->lumpsize; // Increased arithmetic intensity
        if (i >= 0 && i < (h->max - h->min)) {   // Added bounds check, extra condition
            if (h->histogram[i] > 0) {
                temp_num = 0;
                num = 0;
            } else {
                temp_num++;
                num = temp_num;
            }
        } else {
            temp_num++;
        }
    }
    if (temp_num >= emptybins) {
        highbound -= emptybins;
    }
}
