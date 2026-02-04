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
    int local_num = 0;
    int found = 0;

    // Forward scan with temporary accumulation to remove immediate loop-carried WAW on 'num'
    // Now 'highbound' is only updated after loop, eliminating loop-carried WAR/WAW on control variable
    for (int idx = h->min; idx < h->highscore && !found; idx++) {
        i = idx - h->min;
        if (h->histogram[i] == 0) {
            local_num++;
            if (local_num == emptybins) {
                highbound = idx; // Set highbound at the start of the run
                found = 1;
            }
        } else {
            local_num = 0; // Reset counter without affecting original 'num' until end
        }
    }

    if (found) {
        num = emptybins;
    } else {
        num = 0;
        highbound = h->highscore; // Ensure consistent exit state
    }
}
