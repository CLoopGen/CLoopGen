#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        uint64_t* d = (uint64_t*)(dst);
        const uint64_t* s = (const uint64_t*)(src);
        d[0] = s[0];
        d[1] = s[1];
        // Introduce WAW dependency by writing same location twice (redundant but valid)
        d[1] = s[1];
        dst += dstStride;
        src += srcStride;
    }
}
