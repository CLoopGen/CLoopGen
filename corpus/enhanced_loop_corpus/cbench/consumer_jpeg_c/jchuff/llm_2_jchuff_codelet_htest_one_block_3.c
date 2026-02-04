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
    // Variant 1: Consecutive memory access with indirect indexing (unrolled-like pattern using for-loop)
    int k;
    int temp, nbits, r_local = r;
    const int *order_ptr = &jpeg_natural_order[1];
    
    for (k = 0; k < 63; k++) {
        temp = block[*(order_ptr + k)];
        if (temp == 0) {
            r_local++;
        } else {
            for (; r_local > 15; r_local -= 16) {
                ac_counts[240]++;
            }
            temp = (temp < 0) ? -temp : temp;
            nbits = (temp > 0);
            for (int t = temp >> 1; t != 0; t >>= 1) {
                nbits++;
            }
            ac_counts[(r_local << 4) + nbits]++;
            r_local = 0;
        }
    }
    r = r_local;
}
