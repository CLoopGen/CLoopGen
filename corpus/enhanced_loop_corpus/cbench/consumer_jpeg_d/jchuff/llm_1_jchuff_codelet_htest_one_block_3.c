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
            for (int i = 0; r > 15; i++) {
                ac_counts[240]++;
                r -= 16;
            }
            if (temp < 0)
                temp = -temp;
            nbits = 1;
            for (int shift_val = temp >> 1; shift_val != 0; shift_val = temp >> 1) {
                nbits++;
                temp >>= 1;
            }
            ac_counts[(r << 4) + nbits]++;
            r = 0;
        }
    }
}
