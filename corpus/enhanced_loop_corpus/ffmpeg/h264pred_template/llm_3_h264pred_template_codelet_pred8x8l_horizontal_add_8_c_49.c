#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern uint8_t *pix;
extern  int16_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t s = stride;
    int idx[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    for (i = 0; i < 8; i++) {
        uint8_t v = pix[-1];
        for (int j = 0; j < 8; j++) {
            int pos = idx[j];
            v += block[pos];
            pix[pos] = v;
        }
        pix += s;
        block += 8;
    }
}
