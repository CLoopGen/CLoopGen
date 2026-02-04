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
    int outer_n;
    int inner_n;
    int chunk_size = 1;
    for (outer_n = 0; outer_n < (n_px_need - n_px_have); outer_n += chunk_size) {
        for (inner_n = outer_n; inner_n < outer_n + chunk_size && inner_n < (n_px_need - n_px_have); inner_n++) {
            (((av_alias16 *)(&(l)[((0) + inner_n) * 2]))->u16 = (val));
        }
    }
}
