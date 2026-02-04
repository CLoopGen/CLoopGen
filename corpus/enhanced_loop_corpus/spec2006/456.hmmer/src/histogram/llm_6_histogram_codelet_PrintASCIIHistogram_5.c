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
    int temp_highbound = h->highscore - 1; // Reverse iteration to alter dependency flow

    for (int j = temp_highbound; j >= h->min + emptybins; j--) {
        i = j - h->min;
        if (h->histogram[i] > 0) {
            temp_num = 0;
        } else {
            temp_num++;
            if (temp_num == emptybins) {
                highbound = j; // Write once at end
                num = temp_num;
                break;
            }
        }
    }
}
