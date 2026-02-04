#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *pix;
extern int line_size;
extern int w;
extern int s;
extern int i;
extern int j;
extern  uint32_t *sq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing indices and accessing pix in a flattened manner
    uint8_t *base_pix = pix;
    for (i = 0; i < w; i++) {
        for (j = 0; j < w; j++) {
            int index = i * line_size + j;
            s += sq[base_pix[index]];
        }
    }
    pix = base_pix + w * line_size; // Update pix to reflect final pointer position
}
