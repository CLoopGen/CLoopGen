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
    uint16_t prev_val = 0;
    for (n = 0; n < n_px_need; n++) {
        av_alias16 *current = (av_alias16 *)(&(*a)[n * 2]);
        uint16_t computed_val = ((128 << (bpp - 8)) - 1) ^ prev_val;
        current->u16 = computed_val;
        prev_val = computed_val;
    }
}
