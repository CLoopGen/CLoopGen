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
    int k;
    for (k = 1; k < 64; k++) {
        int temp_val = block[jpeg_natural_order[k]];
        int r_local = r;
        int nbits_local = 0;

        if (temp_val == 0) {
            r_local++;
        } else {
            for (; r_local > 15; r_local -= 16) {
                ac_counts[240]++;
            }
            if (temp_val < 0) {
                temp_val = -temp_val;
            }
            nbits_local = 1;
            for (; temp_val >>= 1; ) {
                nbits_local++;
            }
            ac_counts[(r_local << 4) + nbits_local]++;
            r_local = 0;
        }
        r = r_local;
    }
}
