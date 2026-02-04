#include <stdio.h>

#include <inttypes.h>

extern unsigned char *t;
extern  unsigned char *f;
extern int dlen;
extern int i;
extern int ret;
extern unsigned long l;
extern  unsigned char *table;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Mapping
    // Use an auxiliary index array to indirectly access f[], simulating irregular or reordered input processing.
    // For realism, assume `index_map` is precomputed to reverse the access order in chunks.
    // Since we cannot declare new global arrays, simulate small indirect access using modulo arithmetic as index mapping.

    int j;
    for (j = 0; j < dlen; j += 3) {
        // Simulate indirect access: map logical position j to reversed physical position within clamped bounds
        int pos0 = (dlen - 3 - j >= 0) ? (dlen - 3 - j) : j;
        int pos1 = pos0 + 1;
        int pos2 = pos0 + 2;

        l = 0;
        if (pos0 < dlen) l |= ((unsigned long)f[pos0]) << 16L;
        if (pos1 < dlen) l |= ((unsigned long)f[pos1]) << 8L;
        if (pos2 < dlen) l |= (unsigned long)f[pos2];

        int rem = dlen - j;
        *(t++) = ((table)[(l >> 18L) & 63]);
        *(t++) = ((table)[(l >> 12L) & 63]);
        if (rem >= 2) {
            *(t++) = ((table)[(l >> 6L) & 63]);
        } else {
            *(t++) = '=';
        }
        *(t++) = '=';

        if (rem >= 3) {
            // Full triplet written
        } else if (rem == 2) {
            t[-1] = '=';
        } else if (rem == 1) {
            t[-2] = '=';
            t[-1] = '=';
        }

        ret += 4;
    }
}
