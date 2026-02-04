#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int channels;
extern  int32_t *samples;
extern int stride;
extern uint32_t bits[2];
extern int result;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed channel iteration to modify access order and increase stride effect
    ptrdiff_t total_offset = 0;
    for (j = result - 1; j >= 0; j--) {
        for (i = channels - 1; i >= 0; i--) { // Reverse channel traversal
            bits[i] |= (*(samples + total_offset + i) & 1) << j;
        }
        total_offset += stride;
    }
}
