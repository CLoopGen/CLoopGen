#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *sptr;
extern uint8_t *dptr;
extern int dx;
extern int dy;
extern int h;
extern int w;
extern int stride;
extern uint8_t *pfptr;
extern int i;
extern int j;
extern uint8_t *nsptr;
extern uint8_t *npfptr;
extern int diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = dx + h; i > dx; i--) {
        nsptr = sptr + i * stride + dy * 3;
        npfptr = pfptr + i * stride + dy * 3;
        j = 0;
        for (; j < w * 3; ) {
            diff |= npfptr[j] ^ nsptr[j];
            dptr[j] = nsptr[j];
            j++;
        }
        dptr += w * 3;
    }
}
