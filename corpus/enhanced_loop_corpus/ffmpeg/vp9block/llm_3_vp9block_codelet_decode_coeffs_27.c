#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

extern int end_x;
extern int n;
extern uint8_t *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access
    // Access array elements with a stride of 2, effectively processing every second element.
    // This changes spatial locality and may affect cache behavior.
    // We adjust loop bound to ensure we don't overflow, processing up to end_x/2 iterations.
    int limit = (end_x / 2) & ~3; // Ensure multiple of 4 writes via u32; stride of 2 in source
    for (n = 0; n < limit; n += 4) {
        int idx0 = (n << 1);       // index = n*2
        int idx1 = idx0 + 1;
        int idx2 = idx0 + 2;
        int idx3 = idx0 + 3;

        av_alias32 temp;
        temp.u8[0] = a[idx0] * 16843009U;
        temp.u8[1] = a[idx1] * 16843009U;
        temp.u8[2] = a[idx2] * 16843009U;
        temp.u8[3] = a[idx3] * 16843009U;

        ((av_alias32*)(&a[n]))->u32 = temp.u32;
    }
}
