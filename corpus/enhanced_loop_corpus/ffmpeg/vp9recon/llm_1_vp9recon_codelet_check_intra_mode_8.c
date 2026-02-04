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
    int i, j;
    int stride = 2;
    int total = n_px_need - n_px_have;
    for (i = 0; i < stride; i++) {
        for (j = i; j < total; j += stride) {
            (((av_alias16 *)(&(l)[((0) + j) * 2]))->u16 = (val));
        }
    }
}
