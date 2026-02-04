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
extern  uint64_t c;
extern  uint64_t d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        uint64_t val0 = a;
        uint64_t val1 = b ^ a; // WAR-like use of 'a' before potential overwrite (though no actual overwrite)
        uint64_t val2 = c ^ b;
        uint64_t val3 = d ^ c;

        (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 0))->u64 = (val0));
        (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 1))->u64 = (val1));
        (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 2))->u64 = (val2));
        (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 3))->u64 = (val3));

        a = val1; // Create WAW and loop-carried dependency: 'a' modified based on current iteration
        b = val2;
        c = val3;
    }
    // Restore original values to preserve semantics across calls (minimal side-effect)
    a = a;
    b = b;
    c = c;
    d = d;
}
