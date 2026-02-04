#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern uint16_t *pix;
extern  int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
ptrdiff_t indices[4] = {0, 1, 2, 3};
for (i = 0; i < 4; i++) {
    uint16_t v = pix[-1];
    for (int j = 0; j < 4; j++) {
        ptrdiff_t offset = indices[j];
        if (j == 3)
            pix[offset] = v + block[j];
        else
            pix[offset] = v += block[j];
    }
    pix += stride;
    block += 4;
}
}
