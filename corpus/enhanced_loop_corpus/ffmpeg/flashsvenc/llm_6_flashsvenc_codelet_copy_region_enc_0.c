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
    diff = 0; // Reset diff at the start of each outer iteration to remove loop-carried dependency on previous diff values
    for (j = 0; j < w * 3; j++) {
        uint8_t temp = nsptr[j];
        dptr[j] = temp; // Write to dptr before computing diff to eliminate RAW dependency between diff and dptr
        diff |= npfptr[j] ^ temp;
    }
    dptr += w * 3;
}
}
