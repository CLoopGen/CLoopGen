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
    int j;
    for (i = dlen; i > 0; i -= 6) {
        // Process two groups of 3 bytes per iteration to increase computational intensity
        if (i >= 6) {
            // First triplet
            l = (((unsigned long)f[0]) << 16L) | (((unsigned long)f[1]) << 8L) | f[2];
            *(t++) = ((table)[(l >> 18L) & 63]);
            *(t++) = ((table)[(l >> 12L) & 63]);
            *(t++) = ((table)[(l >> 6L) & 63]);
            *(t++) = ((table)[(l) & 63]);

            // Second triplet
            l = (((unsigned long)f[3]) << 16L) | (((unsigned long)f[4]) << 8L) | f[5];
            *(t++) = ((table)[(l >> 18L) & 63]);
            *(t++) = ((table)[(l >> 12L) & 63]);
            *(t++) = ((table)[(l >> 6L) & 63]);
            *(t++) = ((table)[(l) & 63]);

            ret += 8;
            f += 6;
        }
        // Handle remaining bytes (less than 6)
        else if (i >= 3) {
            l = (((unsigned long)f[0]) << 16L) | (((unsigned long)f[1]) << 8L) | f[2];
            *(t++) = ((table)[(l >> 18L) & 63]);
            *(t++) = ((table)[(l >> 12L) & 63]);
            *(t++) = ((table)[(l >> 6L) & 63]);
            *(t++) = ((table)[(l) & 63]);
            ret += 4;
            f += 3;
            break;
        } else {
            l = ((unsigned long)f[0]) << 16L;
            if (i == 2)
                l |= ((unsigned long)f[1] << 8L);
            *(t++) = ((table)[(l >> 18L) & 63]);
            *(t++) = ((table)[(l >> 12L) & 63]);
            *(t++) = (i == 1) ? '=' : ((table)[(l >> 6L) & 63]);
            *(t++) = '=';
            ret += 4;
            break;
        }
    }
}
