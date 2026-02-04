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



void loop() {
    for (k = 1; k < 64; k += 2) {
        temp = block[jpeg_natural_order[k]];
        if (temp == 0) {
            r++;
        } else {
            for (; r > 15; r -= 16) {
                ac_counts[240]++;
            }
            if (temp < 0) {
                temp = -temp;
            }
            nbits = 0;
            int t = temp;
            for (; t != 0; t >>= 1) {
                nbits++;
            }
            ac_counts[(r << 4) + nbits]++;
            r = 0;
        }
        if (k + 1 < 64) {
            temp = block[jpeg_natural_order[k + 1]];
            if (temp == 0) {
                r++;
            } else {
                for (; r > 15; r -= 16) {
                    ac_counts[240]++;
                }
                if (temp < 0) {
                    temp = -temp;
                }
                nbits = 0;
                int t2 = temp;
                for (; t2 != 0; t2 >>= 1) {
                    nbits++;
                }
                ac_counts[(r << 4) + nbits]++;
                r = 0;
            }
        }
    }
}
