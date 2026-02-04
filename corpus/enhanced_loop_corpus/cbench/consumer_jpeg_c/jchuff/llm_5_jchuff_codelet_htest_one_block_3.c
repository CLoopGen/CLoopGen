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
                int t = temp >> 1;
                for (; t != 0; t >>= 1)
                    nbits++;
                ac_counts[(r << 4) + nbits]++;
                r = 0;
            } else {
                do {
                    ac_counts[240]++;
                    r -= 16;
                } while (r > 15);
                if (temp < 0)
                    temp = -temp;
                nbits = 1;
                int shift = temp >> 1;
                if (shift) {
                    nbits++;
                    if (shift >> 1) {
                        nbits++;
                        // Unroll small case instead of loop
                        if ((shift >> 2)) nbits++;
                        if ((shift >> 3)) nbits++;
                        if ((shift >> 4)) nbits++;
                        if ((shift >> 5)) nbits++;
                        if ((shift >> 6)) nbits++;
                        if ((shift >> 7)) nbits++;
                        if ((shift >> 8)) nbits++;
                        if ((shift >> 9)) nbits++;
                        if ((shift >> 10)) nbits++;
                        if ((shift >> 11)) nbits++;
                        if ((shift >> 12)) nbits++;
                        if ((shift >> 13)) nbits++;
                        if ((shift >> 14)) nbits++;
                        if ((shift >> 15)) nbits++;
                    }
                }
                ac_counts[(r << 4) + nbits]++;
                r = 0;
            }
        } else {
            r++;
        }
    }
}
