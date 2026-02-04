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
        int local_diff = 0;
        for (j = 0; j < w * 3; j++) {
            uint8_t val = nsptr[j];
            dptr[j] = val;
            local_diff |= npfptr[j] ^ val;
        }
        if (local_diff) {
            diff |= 1;
        }
        dptr += w * 3;
    }
}
