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
    // Variant 1: Consecutive memory access with reversed traversal and strided histogram access
    for (num = 0; highbound < h->highscore; highbound += 2) {
        i = (h->highscore - 1) - (highbound - h->min); // Reverse index mapping
        if (i >= 0 && i < (h->max - h->min + 1)) {
            if (h->histogram[i] > 0) {
                num = 0;
                continue;
            }
        }
        if (++num == emptybins) {
            highbound -= emptybins * 2;
            break;
        }
    }
}
