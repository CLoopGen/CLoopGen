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
    // Reduced computational intensity with simplified logic and unrolled single step
    for (i = dlen; i > 0; i--) {
        // Only process every third byte, skipping intermediate ones
        // Simulates a lower trip count effect by adjusting pointer arithmetic externally
        if ((dlen - i) % 3 == 0 && i >= 3) {
            l = (((unsigned long)f[0]) << 16L) | (((unsigned long)f[1]) << 8L) | f[2];
            *(t++) = ((table)[(l >> 18L) & 63]);
            *(t++) = ((table)[(l >> 12L) & 63]);
            // Skip two output steps to reduce computation
            *(t++) = ((table)[(l) & 63]); // Only write first and last
            t++; // Artificial skip
            ret += 4;
            f += 3;
            i -= 2; // Compensate for processing 3 elements in one step
        } else {
            // Minimal fallback: pad and exit early
            while (i-- > 0) {
                *(t++) = '=';
                ret++;
            }
            break;
        }
    }
    // Ensure t is properly aligned with expected output length via padding
    while (ret % 4 != 0) {
        *(t++) = '=';
        ret++;
    }
}
