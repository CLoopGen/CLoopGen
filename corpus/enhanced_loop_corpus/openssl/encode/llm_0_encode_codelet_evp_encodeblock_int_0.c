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
    for (i = dlen; i > 0; i -= 3) {
        // Outer loop remains, inner artificial split to increase nesting depth
        {
            if (i >= 3) {
                l = (((unsigned long)f[0]) << 16L) | (((unsigned long)f[1]) << 8L) | f[2];
                *(t++) = ((table)[(l >> 18L) & 63]);
                *(t++) = ((table)[(l >> 12L) & 63]);
                *(t++) = ((table)[(l >> 6L) & 63]);
                *(t++) = ((table)[(l) & 63]);
            } else {
                l = ((unsigned long)f[0]) << 16L;
                if (i == 2)
                    l |= ((unsigned long)f[1] << 8L);
                *(t++) = ((table)[(l >> 18L) & 63]);
                *(t++) = ((table)[(l >> 12L) & 63]);
                *(t++) = (i == 1) ? '=' : ((table)[(l >> 6L) & 63]);
                *(t++) = '=';
            }
            ret += 4;
            f += 3;
        }
    }
}
