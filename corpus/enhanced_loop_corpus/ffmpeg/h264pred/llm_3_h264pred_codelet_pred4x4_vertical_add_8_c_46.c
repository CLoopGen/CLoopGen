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
// Use indirect access via index array to simulate irregular memory access pattern
static const int indices[4] = {0, 1, 2, 3};
for (i = 0; i < 4; i++) {
    int idx = indices[i]; // Indirect indexing (could be dynamic in real use)
    uint8_t v = pix[idx];
    pix[idx + 1 * stride] = v += block[idx * 4];
    pix[idx + 2 * stride] = v += block[idx * 4 + 1];
    pix[idx + 3 * stride] = v += block[idx * 4 + 2];
    pix[idx + 4 * stride] = v + block[idx * 4 + 3];
    pix += stride; // Move down vertically instead of horizontally
    block += 4;
}
}
