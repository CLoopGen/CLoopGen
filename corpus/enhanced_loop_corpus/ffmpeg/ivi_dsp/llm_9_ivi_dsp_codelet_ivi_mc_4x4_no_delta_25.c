#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern ptrdiff_t dpitch;
extern  int16_t *ref_buf;
extern ptrdiff_t pitch;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++ , buf += dpitch * 2, ref_buf += pitch * 2) {
    for (j = 0; j < 8; j++) {
        if (j < 4) {
            buf[j] = ref_buf[j];
        } else {
            buf[j % 4 + dpitch/sizeof(int16_t)] = ref_buf[j % 4 + pitch/sizeof(int16_t)];
        }
    }
}
}
