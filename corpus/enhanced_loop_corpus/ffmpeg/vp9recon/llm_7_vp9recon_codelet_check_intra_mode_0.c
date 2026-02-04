#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern uint8_t **a;
extern int n_px_need;
extern int n_px_have;
extern int n;
extern int val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t local_accum = val;
    for (n = 0; n < (n_px_need - n_px_have); n++) {
        int offset = (n_px_have + n) * 2;
        // Introduce WAW dependency by splitting write into two steps via intermediate update
        av_alias16 *target = (av_alias16 *)&(*a)[offset];
        target->u16 = 0;           // First write (WAW: overwrites same location)
        target->u16 = local_accum; // Second write depends on prior (artificial WAW)
    }
}
