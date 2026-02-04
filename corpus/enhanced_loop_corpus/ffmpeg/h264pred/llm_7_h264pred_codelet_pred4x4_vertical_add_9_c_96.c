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
uint16_t temp_values[4];
int offsets[] = {0, 4, 8, 12};
for (i = 0; i < 4; i++) {
    uint16_t v = pix[0];
    temp_values[0] = v + block[offsets[0]];
    temp_values[1] = temp_values[0] + block[offsets[1]];
    temp_values[2] = temp_values[1] + block[offsets[2]];
    temp_values[3] = temp_values[2] + block[offsets[3]];
    pix[1 * stride] = temp_values[0];
    pix[2 * stride] = temp_values[1];
    pix[3 * stride] = temp_values[2];
    pix[4 * stride] = temp_values[3];
    pix++;
    block++;
}
}
