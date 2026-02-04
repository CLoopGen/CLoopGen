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
    temp = block[jpeg_natural_order[k]];
    if (temp != 0) {
        if (r <= 15) {
            if (temp < 0)
                temp = -temp;
            nbits = 1;
            temp >>= 1;
            if (temp > 0) {
                nbits++;
                temp >>= 1;
                if (temp > 0) {
                    do {
                        nbits++;
                        temp >>= 1;
                    } while (temp > 0);
                }
            }
            ac_counts[(r << 4) + nbits]++;
            r = 0;
        } else {
            ac_counts[240]++;
            r -= 16;
            k--;  // Re-process same k after adjusting r
            continue;
        }
    } else {
        r++;
    }
}
}
