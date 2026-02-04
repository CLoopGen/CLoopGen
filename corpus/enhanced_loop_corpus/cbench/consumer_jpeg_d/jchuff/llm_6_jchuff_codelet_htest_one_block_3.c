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
    for (k = 1; k < 64; k++) {
        temp = block[jpeg_natural_order[k]];
        if (temp == 0) {
            r++;
        } else {
            // Eliminate loop-carried dependency on 'r' by using a local copy
            int local_r = r;
            for (; local_r > 15; local_r -= 16) {
                ac_counts[240]++;
            }
            if (temp < 0)
                temp = -temp;
            nbits = 0;
            for (int t = temp; t != 0; t >>= 1) {
                nbits++;
            }
            ac_counts[(local_r << 4) + nbits]++;
            r = 0; // WAW: Write-after-write on 'r' is preserved only at end
        }
    }
}
