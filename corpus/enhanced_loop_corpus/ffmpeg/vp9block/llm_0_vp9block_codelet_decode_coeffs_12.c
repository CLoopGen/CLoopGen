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

extern int end_y;
extern int n;
extern uint8_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < end_y; outer += 4) {
        for (int inner = 0; inner < 2 && (outer + inner) < end_y; inner += 2) {
            n = outer + inner;
            (((av_alias64 *)(&l[n]))->u64 = (l[n] * 72340172838076673ULL));
        }
    }
}
