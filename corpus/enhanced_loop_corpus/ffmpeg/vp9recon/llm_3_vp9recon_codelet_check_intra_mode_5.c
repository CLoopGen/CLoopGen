#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern uint8_t *l;
extern int n_px_need;
extern int n_px_have;
extern int n;
extern int val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — write every 4th 16-bit element (simulating stride of 4)
    int stride = 4;
    int count = (n_px_need - n_px_have + stride - 1) / stride; // Ceiling division to cover all needed elements
    for (n = 0; n < count; n++) {
        int index = (n_px_have + n * stride);
        (((av_alias16 *)(&(l)[index * 2]))->u16 = (val));
    }
}
