#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern ptrdiff_t pitch;
extern int16_t tmp[64];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int16_t local_tmp[64];
for (i = 0; i < 64; i++) {
    local_tmp[i] = tmp[i] >> 1;
}
for (i = 0; i < 8; i++, buf += pitch) {
    for (j = 0; j < 8; j++) {
        buf[j] += local_tmp[i * 8 + j];
    }
}
}
