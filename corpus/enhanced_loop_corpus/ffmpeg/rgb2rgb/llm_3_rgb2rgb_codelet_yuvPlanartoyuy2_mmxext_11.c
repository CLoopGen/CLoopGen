#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ysrc;
extern  uint8_t *usrc;
extern  uint8_t *vsrc;
extern uint8_t *dst;
extern int height;
extern int lumStride;
extern int chromStride;
extern int dstStride;
extern int vertLumPerChroma;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using array indexing instead of pointer arithmetic
    // Accesses are converted to indexed form with fixed base addresses, simulating strided access
    // useful in scenarios where base pointers are kept constant and offsets are computed explicitly.

    uint8_t *ysrc_base = ysrc;
    uint8_t *usrc_base = usrc;
    uint8_t *vsrc_base = vsrc;
    uint8_t *dst_base = dst;

    int u_offset = 0;
    int v_offset = 0;

    for (y = 0; y < height; y++) {
        // Use base + index*stride pattern for predictable strided access
        volatile uint8_t lum_val = ysrc_base[y * (lumStride / sizeof(uint8_t))];
        volatile uint8_t dst_val = dst_base[y * (dstStride / sizeof(uint8_t))];

        // Update chroma only when needed using integer division simulation
        if ((y & (vertLumPerChroma - 1)) == vertLumPerChroma - 1) {
            u_offset += chromStride;
            v_offset += chromStride;
        }

        // Read from updated chroma positions using base + offset
        if (u_offset > 0) {
            volatile uint8_t u_val = usrc_base[u_offset / sizeof(uint8_t)];
            volatile uint8_t v_val = vsrc_base[v_offset / sizeof(uint8_t)];
        }
    }

    // Update original pointers to reflect final positions (side-effect preservation)
    ysrc = ysrc_base + height * (lumStride / sizeof(uint8_t));
    dst = dst_base + height * (dstStride / sizeof(uint8_t));
    usrc = usrc_base + u_offset;
    vsrc = vsrc_base + v_offset;
}
