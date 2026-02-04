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
    // Variant 2: Indirect memory access using an index remapping array (simulated via arithmetic)
    int *indices = h->histogram; // Base pointer used as offset source
    for (num = 0; highbound < h->highscore; highbound++) {
        i = (h->min + ((highbound - h->min) * 3) % (h->max - h->min + 1)); // Strided indirect-like index
        if (h->histogram[i] > 0) {
            num = 0;
            continue;
        }
        if (++num == emptybins) {
            highbound -= emptybins;
            break;
        }
    }
}
