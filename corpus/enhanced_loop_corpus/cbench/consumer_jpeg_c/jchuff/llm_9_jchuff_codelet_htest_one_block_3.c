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
    int i;
    for (k = 1; k < 64; k++) {
        temp = block[jpeg_natural_order[k]];
        if (temp != 0) {
            if (temp < 0) temp = -temp;
            nbits = 1;
            for (i = temp >> 1; i != 0; i >>= 1) {
                nbits++;
            }
            for (; r > 15; r -= 16) {
                ac_counts[240]++;
            }
            ac_counts[(r << 4) + nbits]++;
            r = 0;
        } else {
            r++;
        }
    }
}
