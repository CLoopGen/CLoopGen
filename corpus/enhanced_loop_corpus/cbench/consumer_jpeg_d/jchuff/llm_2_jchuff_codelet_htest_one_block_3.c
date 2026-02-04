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
