#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern  uint8_t *ref;
extern uint8_t *dst;
extern int threshold;
extern int w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access (backward traversal)
    // Alters access pattern by iterating from the end to the beginning
    for (int x = w - 1; x >= 0; x--) {
        dst[x] = ((src[x] - ref[x]) >= 0 ? (src[x] - ref[x]) : (-(src[x] - ref[x]))) <= threshold ? src[x] : ref[x];
    }
}
