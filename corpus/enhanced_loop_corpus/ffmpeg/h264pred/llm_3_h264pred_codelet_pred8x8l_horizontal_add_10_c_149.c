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
// Modify memory access pattern to use indirect (gather-like) access via index array
// Simulate irregular but deterministic access using fixed offsets
static const int offsets[8] = {0, 1, 2, 3, 4, 5, 6, 7};
for (i = 0; i < 8; i++) {
    uint16_t v = pix[-1];
    for (int j = 0; j < 8; j++) {
        if (j == 7)
            pix[offsets[j]] = v + block[offsets[j]];
        else
            pix[offsets[j]] = v += block[offsets[j]];
    }
    pix += stride;
    block += 8;
}
}
