#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern ptrdiff_t pitch;
extern int16_t tmp[16];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; ++i, buf += pitch) {
    if (i % 2 == 0) {
        for (j = 0; j < 4; ++j) {
            buf[j] = tmp[i * 4 + j] >> 1;
        }
    } else {
        j = 0;
        for (; j < 4; ++j) {
            buf[j] = tmp[i * 4 + j] >> 1;
        }
    }
}
}
