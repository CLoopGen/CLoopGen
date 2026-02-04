#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern  uint8_t *block;
extern int x;
extern int y;
extern int dist;
extern int bias;
extern int dist4;
extern int dist2;
extern int bits;
extern int mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 8; y++) {
    for (x = 0; x < 4; x++) {
        int alp = block[3 + x * 4 + y * stride] * 9 + bias + (y & 1);
        int ind, tmp;
        tmp = (alp >= dist4 * 2) ? -1 : 0;
        ind = tmp & 4;
        alp -= dist4 * 2 & tmp;
        tmp = (alp >= dist2) ? -1 : 0;
        ind += tmp & 2;
        alp -= dist2 & tmp;
        ind += (alp >= dist / 2);
        ind = -ind & 7;
        ind ^= (3 > ind);
        mask |= ind << bits;
        bits += 4;
        if (bits >= 16) {
            *dst++ = mask;
            *dst++ = mask >> 8;
            mask >>= 16;
            bits -= 16;
        }
    }
}
}
