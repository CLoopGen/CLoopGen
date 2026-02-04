#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern uint8_t **a;
extern int bpp;
extern int n_px_need;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reverse traversal and stride of 4 (simulating alignment or padding)
    uint16_t val = (128 << (bpp - 8)) - 1;
    for (n = n_px_need - 1; n >= 0; n--) {
        int index = n * 4; // Stride of 4 instead of 2, accessing every other 16-bit element
        if (index + 1 < n_px_need * 2) { // Safe bounds check
            ((av_alias16 *)(&(*a)[index]))->u16 = val;
        }
    }
}
