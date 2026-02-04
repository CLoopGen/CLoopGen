#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_stride;
extern  uint8_t *src;
extern int src_stride;
extern int w;
extern int h;
extern int x;
extern int y;
extern int pel;
extern int contrast;
extern int brightness;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access using index array (simulating indirect access pattern)
    int *indices = (int*)alloca(w * sizeof(int));
    for (x = 0; x < w; x++) {
        indices[x] = x;
    }
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            int idx = indices[x]; // Indirect indexing (trivial mapping, but enables pattern change)
            pel = ((src[y * src_stride + idx] * contrast) >> 12) + brightness;
            if (pel & ~255)
                pel = (-pel) >> 31;
            dst[y * dst_stride + idx] = pel;
        }
    }
}
