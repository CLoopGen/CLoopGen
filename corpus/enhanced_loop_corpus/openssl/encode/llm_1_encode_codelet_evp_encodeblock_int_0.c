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
    // Reduced effective loop depth by inlining the condition handling into a single flat structure
    // Simulated reduction in control flow complexity by unrolling assumptions

    int remaining = dlen;
    for (i = dlen; i > 0; i -= 3) {
        l = ((unsigned long)f[0]) << 16L;
        if (remaining >= 2) l |= ((unsigned long)f[1]) << 8L;
        if (remaining >= 3) l |= f[2];

        *(t++) = ((table)[(l >> 18L) & 63]);
        *(t++) = ((table)[(l >> 12L) & 63]);

        if (remaining >= 3 || remaining == 1) {
            *(t++) = ((table)[(l >> 6L) & 63]);
            *(t++) = ((table)[(l) & 63]);
        } else {
            *(t++) = ((table)[(l >> 6L) & 63]);
            *(t++) = '=';
        }

        if (remaining < 3 && remaining > 0) {
            if (remaining == 1) {
                *(t - 2) = '=';
            }
        }

        ret += 4;
        f += 3;
        remaining -= 3;
    }
}
