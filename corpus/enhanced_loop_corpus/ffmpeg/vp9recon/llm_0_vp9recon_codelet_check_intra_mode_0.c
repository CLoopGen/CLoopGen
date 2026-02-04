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
    int outer;
    int inner;
    int total = n_px_need - n_px_have;
    for (outer = 0; outer < total; outer += 2) {
        for (inner = outer; inner < ((outer + 2) <= total ? (outer + 2) : total); inner++) {
            (((av_alias16 *)(&(*a)[((n_px_have) + inner) * 2]))->u16 = (val));
        }
    }
}
