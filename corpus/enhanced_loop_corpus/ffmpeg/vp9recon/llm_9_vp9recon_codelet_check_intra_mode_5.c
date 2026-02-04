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
    int step = 1;
    int limit = (n_px_need - n_px_have) * 2;
    for (n = 0; n < limit; n += step * 2) {
        int idx = (n_px_have + (n / 2)) * 2;
        uint16_t v = (uint16_t)val;
        l[idx]     = (uint8_t)(v & 0xFF);
        l[idx + 1] = (uint8_t)((v >> 8) & 0xFF);
    }
}
