#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int w;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access in reverse order (backward traversal with stride)
    // Alters access pattern to start from the end and step backward with same logical indexing
    int i;
    for (i = w - 1; i >= x; i--) {
        dst[i] = src[2 * i];
    }
    x = w; // Ensure loop condition is satisfied after completion
}
