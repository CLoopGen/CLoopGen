#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
    double f64;
    float f32[2];
} av_alias64;

extern int i;
extern uint16_t *src;
extern int stride;
extern  uint64_t a;
extern  uint64_t b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed iteration and increased stride simulation
    int effective_stride = stride * 2; // Simulate accessing every other row more aggressively
    for (i = 7; i >= 0; i--) {
        uint16_t* row = src + (7 - i) * effective_stride; // Reverse order, strided forward
        ((av_alias64*)((uint64_t*)row + 0))->u64 = a;
        ((av_alias64*)((uint64_t*)row + 1))->u64 = b;
    }
}
