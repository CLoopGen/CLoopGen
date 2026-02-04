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
    // Variant 2: Strided array access combined with direct offset computation to simulate changed access pattern
    int k;
    int temp, nbits, r_local = r;

    // Simulate strided traversal by accessing natural order in reverse with step of 2 (indirect and sparse)
    for (k = 62; k >= 0; k -= 2) {  // Accessing every second element backwards
        int index = jpeg_natural_order[k + 1];  // Shifted to stay within bounds
        temp = block[index];

        if (temp == 0) {
            r_local++;
        } else {
            for (; r_local > 15; r_local -= 16) {
                ac_counts[240]++;
            }
            temp = (temp < 0) ? -temp : temp;
            nbits = 1;
            for (int shift = temp >> 1; shift != 0; shift >>= 1) {
                nbits++;
            }
            ac_counts[(r_local << 4) + nbits]++;
            r_local = 0;
        }
    }

    // Handle remaining indices not covered due to stride (odd positions forward)
    for (k = 1; k < 64; k += 2) {
        int index = jpeg_natural_order[k];
        temp = block[index];

        if (temp == 0) {
            r_local++;
        } else {
            for (; r_local > 15; r_local -= 16) {
                ac_counts[240]++;
            }
            temp = (temp < 0) ? -temp : temp;
            nbits = 1;
            for (int shift = temp >> 1; shift != 0; shift >>= 1) {
                nbits++;
            }
            ac_counts[(r_local << 4) + nbits]++;
            r_local = 0;
        }
    }
    r = r_local;
}
