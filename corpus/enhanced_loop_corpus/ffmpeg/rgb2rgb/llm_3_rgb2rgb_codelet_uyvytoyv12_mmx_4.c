#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *ydst;
extern uint8_t *udst;
extern uint8_t *vdst;
extern int height;
extern int lumStride;
extern int chromStride;
extern int srcStride;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with index-based array indexing to simulate strided memory layout access
    ptrdiff_t i;
    for (i = 0; i < height; i += 2) {
        // Simulate strided access using byte offsets instead of direct pointer increments
        ydst = (uint8_t*)((uint8_t*)ydst + lumStride * 2);
        src = (uint8_t*)((uint8_t*)src + srcStride * 2);
        udst = (uint8_t*)((uint8_t*)udst + chromStride);
        vdst = (uint8_t*)((uint8_t*)vdst + chromStride);
    }
    // Final value of 'y' updated to reflect loop progress
    y = (int)i;
}
