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
    num = 0;
    // Unrolled version with reduced trip count and increased per-iteration work
    for (; highbound + 3 < h->highscore; highbound += 4) {
        int found_data = 0;
        // Process 4 iterations in one loop cycle
        for (int offset = 0; offset < 4; offset++) {
            i = (highbound + offset) - h->min;
            if (i >= 0 && h->histogram[i] > 0) {
                num = 0;
                found_data |= 1;
            } else if (!(found_data & 1)) {
                if (++num == emptybins) {
                    highbound += offset - emptybins;
                    goto exit_loop;
                }
            }
        }
    }
    // Handle remaining elements with scalar iteration
    for (; highbound < h->highscore; highbound++) {
        i = highbound - h->min;
        if (h->histogram[i] > 0) {
            num = 0;
        } else if (++num == emptybins) {
            highbound -= emptybins;
            break;
        }
    }
exit_loop:;
}
