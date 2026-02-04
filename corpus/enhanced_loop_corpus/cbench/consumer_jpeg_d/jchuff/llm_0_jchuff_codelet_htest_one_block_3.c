#include <stdio.h>

#include <inttypes.h>

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

extern const int jpeg_natural_order[];
extern JCOEFPTR block;
extern long ac_counts[];
extern int temp;
extern int nbits;
extern int k;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 1; k < 64; k++) {
        if ((temp = block[jpeg_natural_order[k]]) == 0) {
            r++;
        } else {
            for (; r > 15; r -= 16) {
                ac_counts[240]++;
            }
            if (temp < 0)
                temp = -temp;
            nbits = 1;
            for (; temp >> 1; temp >>= 1) {
                nbits++;
            }
            ac_counts[(r << 4) + nbits]++;
            r = 0;
        }
    }
}
