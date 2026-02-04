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
int i_start = dx + h - 2;
int i_step = 2;
for (i = i_start; i > dx; i -= i_step) {
    nsptr = sptr + i * stride + dy * 3;
    npfptr = pfptr + i * stride + dy * 3;
    for (j = 0; j < w * 3; j += 3) {
        diff |= npfptr[j] ^ nsptr[j];
        dptr[j] = nsptr[j];
        if (j + 1 < w * 3) {
            diff |= npfptr[j+1] ^ nsptr[j+1];
            dptr[j+1] = nsptr[j+1];
        }
        if (j + 2 < w * 3) {
            diff |= npfptr[j+2] ^ nsptr[j+2];
            dptr[j+2] = nsptr[j+2];
        }
    }
    dptr += w * 3;
}
}
