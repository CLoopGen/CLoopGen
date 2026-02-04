#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int srcStride;
extern int dstStride[];
extern int srcSliceH;
extern int inc_size;
extern int width;
extern uint8_t *dest[3];
extern int x;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern using indirect indexing via index array (simulating irregular access)
    // Simulate an index remapping (e.g., reverse order per row to create strided/indirect access effect)
    int *indices = (int*)alloca(width * sizeof(int));
    for (int i = 0; i < width; i++) {
        indices[i] = width - 1 - i;  // Reverse index mapping
    }

    for (h = 0; h < srcSliceH; h++) {
        for (x = 0; x < width; x++) {
            int idx = indices[x];  // Indirect access through index array
            dest[0][idx] = src[x * inc_size + 0];
            dest[1][idx] = src[x * inc_size + 1];
            dest[2][idx] = src[x * inc_size + 2];
        }
        src += srcStride;
        dest[0] += dstStride[0];
        dest[1] += dstStride[1];
        dest[2] += dstStride[2];
    }
}
