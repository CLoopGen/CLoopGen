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
    if (end_y > 0) {
        for (n = 0; n < end_y; n += 2) {
            uint8_t temp = !!(((const av_alias16 *)(&l[n]))->u16);
            l[n] = temp;
        }
    }
}
