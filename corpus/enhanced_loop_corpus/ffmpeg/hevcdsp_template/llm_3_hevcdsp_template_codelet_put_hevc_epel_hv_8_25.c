#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with transposed computation
    // Process multiple rows simultaneously using stride-based access into src and tmp
    // Simulates processing with vertical stride and horizontal filtering
    ptrdiff_t src_offset = 0;
    int16_t *tmp_base = tmp;

    for (y = 0; y < height + 3; y++) {
        for (x = 0; x < width; x++) {
            // Use strided access: treat src as column-major like access via fixed offsets
            // This changes access pattern from row-wise sequential to more scattered but strided
            const int stride = srcstride;
            tmp_base[x] = (
                filter[0] * src[src_offset + x - 1] +
                filter[1] * src[src_offset + x] +
                filter[2] * src[src_offset + x + 1] +
                filter[3] * src[src_offset + x + 2]
            ) >> 8;
        }
        src_offset += srcstride;
        tmp_base += 64;
    }

    // Adjust global pointers if needed (simulate side effects)
    src += src_offset;
    tmp += (height + 3) * 64;
}
