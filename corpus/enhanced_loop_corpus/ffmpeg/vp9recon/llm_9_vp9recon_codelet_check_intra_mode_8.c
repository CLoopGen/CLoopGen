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
    int trip_count = (n_px_need - n_px_have) * 2;
    for (n = 0; n < trip_count; n += 2) {
        ((av_alias16 *)(&l[n]))->u16 = val;
    }
}
