#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < width - 2; i += 2) {
    const uint8_t* s = src;
    uint8_t* d = dst;

    // Flatten memory access into linear offsets using precomputed base pointers
    // Access pattern changed to use relative byte offsets for better locality

    int c0 = 0, c1 = 2, c2 = 4;
    int m1 = -src_stride, z = 0, p1 = src_stride, p2 = 2*src_stride;

    // Load all required 16-bit values once to simulate consecutive reuse
    uint16_t v_m1_c0 = ((const union unaligned_16*)(&s[m1 + c0]))->l;
    uint16_t v_m1_c1 = ((const union unaligned_16*)(&s[m1 + c1]))->l;
    uint16_t v_m1_c2 = ((const union unaligned_16*)(&s[m1 + c2]))->l;

    uint16_t v_0_c0 = ((const union unaligned_16*)(&s[z + c0]))->l;
    uint16_t v_0_c1 = ((const union unaligned_16*)(&s[z + c1]))->l;
    uint16_t v_0_c2 = ((const union unaligned_16*)(&s[z + c2]))->l;

    uint16_t v_p1_c0 = ((const union unaligned_16*)(&s[p1 + c0]))->l;
    uint16_t v_p1_c1 = ((const union unaligned_16*)(&s[p1 + c1]))->l;
    uint16_t v_p1_c2 = ((const union unaligned_16*)(&s[p1 + c2]))->l;

    uint16_t v_p2_c0 = ((const union unaligned_16*)(&s[p2 + c0]))->l;
    uint16_t v_p2_c1 = ((const union unaligned_16*)(&s[p2 + c1]))->l;
    uint16_t v_p2_c2 = ((const union unaligned_16*)(&s[p2 + c2]))->l;

    // Write to destination with consecutive byte packing
    d[0]                      = (v_m1_c0 + v_p1_c0) >> 9;
    d[1]                      = v_0_c0 >> 8;
    d[2]                      = (v_0_c1 + v_0_c1) >> 9;  // Symmetric horizontal blend

    d[3]                      = (v_m1_c0 + v_m1_c2 + v_p1_c0 + v_p1_c2) >> 10;
    d[4]                      = (v_m1_c1 + v_0_c0 + v_0_c2 + v_p1_c1) >> 10;
    d[5]                      = v_p1_c1 >> 8;

    d[dst_stride + 0]         = v_p1_c0 >> 8;
    d[dst_stride + 1]         = (v_0_c0 + v_p1_c1 + v_p1_c1 + v_p2_c0) >> 10;
    d[dst_stride + 2]         = (v_0_c1 + v_0_c1 + v_p2_c1 + v_p2_c1) >> 10;

    d[dst_stride + 3]         = (v_p1_c0 + v_p1_c2) >> 9;
    d[dst_stride + 4]         = v_p1_c1 >> 8;
    d[dst_stride + 5]         = (v_0_c1 + v_p2_c1) >> 9;

    src += 4;
    dst += 6;
}
}
