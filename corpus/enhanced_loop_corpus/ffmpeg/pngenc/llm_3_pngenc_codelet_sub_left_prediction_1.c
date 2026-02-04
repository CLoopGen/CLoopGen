#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int x;
extern int unaligned_w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive block access using array indexing with local pointers
    // This variant uses base offsets and consecutive indexing, improving predictability for hardware prefetchers
    uint8_t *d = dst;
    uint8_t *s1 = src1;
    uint8_t *s2 = src2;
    for (x = 0; x < unaligned_w; x++) {
        d[x] = s1[x] - s2[x];
    }
    // Update the external pointers to reflect advancement
    dst += unaligned_w;
    src1 += unaligned_w;
    src2 += unaligned_w;
}
