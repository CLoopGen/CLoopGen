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
    // Change memory access pattern to strided: process every 2nd element in natural order, then the others
    for (int pass = 0; pass < 2; pass++) {
        for (k = 1 + pass; k < 64; k += 2) {
            int index = jpeg_natural_order[k];
            temp = block[index];

            if (temp == 0) {
                r++;
            } else {
                for (; r > 15; r -= 16) {
                    ac_counts[240]++;
                }
                temp = temp < 0 ? -temp : temp;
                nbits = 0;
                for (int t = temp; t != 0; t >>= 1) {
                    nbits++;
                }
                ac_counts[(r << 4) + nbits]++;
                r = 0;
            }
        }
    }
}
