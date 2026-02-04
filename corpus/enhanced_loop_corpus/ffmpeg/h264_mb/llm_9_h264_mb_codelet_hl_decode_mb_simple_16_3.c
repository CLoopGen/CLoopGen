#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dest_cb;
extern uint8_t *dest_cr;
extern int uvlinesize;
extern int i;
extern  int block_h;
extern  int bit_depth;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < block_h * 2; i += 2) {
    uint16_t *tmp_cb1 = (uint16_t *)(dest_cb + i * uvlinesize);
    uint16_t *tmp_cr1 = (uint16_t *)(dest_cr + i * uvlinesize);
    uint16_t *tmp_cb2 = (uint16_t *)(dest_cb + (i + 1) * uvlinesize);
    uint16_t *tmp_cr2 = (uint16_t *)(dest_cr + (i + 1) * uvlinesize);
    uint16_t val = 1 << (bit_depth - 1);
    for (j = 0; j < 8; j++) {
        tmp_cb1[j] = tmp_cr1[j] = val;
        if (i + 1 < block_h) {
            tmp_cb2[j] = tmp_cr2[j] = val;
        }
    }
}
}
