#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern int end_y;
extern int n;
extern uint8_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < end_y; outer += 4) {
        for (int inner = 0; inner < 2 && (outer + inner) < end_y; inner += 2) {
            n = outer + inner;
            l[n] = !!(((const av_alias16 *)(&l[n]))->u16);
        }
    }
}
