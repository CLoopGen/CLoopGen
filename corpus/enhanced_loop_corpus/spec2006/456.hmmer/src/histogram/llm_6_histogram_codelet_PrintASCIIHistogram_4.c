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
    for (num = 0; temp_lowbound > h->lowscore; temp_lowbound--) {
        i = temp_lowbound - h->min;
        if (h->histogram[i] > 0) {
            temp_num = 0;
            num = temp_num;
            continue;
        }
        temp_num++;
        num = temp_num;
        if (temp_num == emptybins) {
            lowbound = temp_lowbound + emptybins;
            break;
        }
    }
}
