#include <stdio.h>

#include <inttypes.h>

extern uint8_t *out;
extern  uint8_t *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal with index remapping
    // Input is accessed consecutively from start to end, output written in reverse order
    // This improves spatial locality compared to original scattered access
    for (i = 0; i < 16; i++)
        out[15 - i] = in[i];
}
