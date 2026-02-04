#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Prefetching Simulation
    // Restructure to emphasize strided access patterns and simulate potential prefetch benefits
    // by grouping memory accesses in a more predictable, regular stride across src rows

    const int ss = src_stride;
    const int ds = dst_stride;
    for (i = 2; i < width - 2; i += 2) {
        // Precompute base pointers for current column group
        uint8_t *base_src_m1 = src - ss;
        uint8_t *base_src_0 = src;
        uint8_t *base_src_p1 = src + ss;
        uint8_t *base_src_p2 = src + 2*ss;

        // Fetch all required source values with explicit strided indexing
        #define LOAD(y, x) ((unsigned int)(*(base_src_##y + (x))))
        
        unsigned int ul = LOAD(m1, -1);
        unsigned int uc = LOAD(m1,  0);
        unsigned int ur = LOAD(m1,  1);
        unsigned int cl = LOAD(0, -1);
        unsigned int cc = LOAD(0,  0);
        unsigned int cr = LOAD(0,  1);
        unsigned int ll = LOAD(p1, -1);
        unsigned int lc = LOAD(p1,  0);
        unsigned int lr = LOAD(p1,  1);
        unsigned int xl = LOAD(p2, -1);
        unsigned int xc = LOAD(p2,  0);
        unsigned int xr = LOAD(p2,  1);

        // Write to destination using direct offset arithmetic
        dst[0*ds*3 + 0] = cc;
        dst[0*ds*3 + 1] = (uc + cl + cr + lc) >> 2;
        dst[0*ds*3 + 2] = (ul + ur + ll + lr) >> 2;

        dst[0*ds*3 + 3] = (cr + lr + xr + cc) >> 2;
        dst[0*ds*3 + 4] = lc;
        dst[0*ds*3 + 5] = (cc + cr) >> 1;

        dst[1*ds*3 + 0] = (ll + lr + ul + ur) >> 2;
        dst[1*ds*3 + 1] = lc;
        dst[1*ds*3 + 2] = (cc + xc) >> 1;

        dst[1*ds*3 + 3] = lr;
        dst[1*ds*3 + 4] = (cr + lc + lr + xr) >> 2;
        dst[1*ds*3 + 5] = (cc + cr + xc + xr) >> 2;

        src += 2;
        dst += 6;
    }
}
