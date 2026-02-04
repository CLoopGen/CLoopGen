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
    int limit = n_px_need - n_px_have;
    for (n = 0; n < limit && val >= 0; n++) {
        uint16_t write_val = (val % 256) ? (val + n) : 0;
        (((av_alias16 *)(&(l)[n * 2]))->u16 = write_val);
    }
}
