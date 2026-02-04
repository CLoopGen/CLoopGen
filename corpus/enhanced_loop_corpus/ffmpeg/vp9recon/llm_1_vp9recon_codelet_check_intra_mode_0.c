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
    int i, j;
    int iter = (n_px_need - n_px_have + 3) / 4; // Ceiling division by 4 to reduce loop count
    for (i = 0; i < iter; i++) {
        for (j = 0; j < 4; j++) {
            int n = i * 4 + j;
            if (n < (n_px_need - n_px_have)) {
                (((av_alias16 *)(&(*a)[((n_px_have) + n) * 2]))->u16 = (val));
            }
        }
    }
}
