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
    // Variant 2: Indirect memory access via index array to simulate irregular access pattern
    int indices[16];
    for (int j = 0; j < 16; j++) {
        indices[j] = j; // Base indices, could be randomized or reordered in real use cases
    }
    for (i = 0; i < 16; i++) {
        int idx = indices[i]; // Simulate indirect addressing
        (((av_alias64 *)(((uint64_t *)(src + idx * stride)) + 0))->u64 = (a));
        (((av_alias64 *)(((uint64_t *)(src + idx * stride)) + 1))->u64 = (b));
    }
}
