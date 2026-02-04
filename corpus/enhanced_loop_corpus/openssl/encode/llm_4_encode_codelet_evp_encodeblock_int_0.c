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



void loop() {
    for (i = dlen; i > 0; i -= 3) {
        l = ((unsigned long)f[0]) << 16L;
        if (i >= 2) {
            l |= ((unsigned long)f[1]) << 8L;
        }
        if (i >= 3) {
            l |= f[2];
        }
        *(t++) = table[(l >> 18L) & 63];
        *(t++) = table[(l >> 12L) & 63];
        char third = (i == 1) ? '=' : table[(l >> 6L) & 63];
        *(t++) = third;
        *(t++) = '=';
        ret += 4;
        f += (i >= 3) ? 3 : i;
    }
}
