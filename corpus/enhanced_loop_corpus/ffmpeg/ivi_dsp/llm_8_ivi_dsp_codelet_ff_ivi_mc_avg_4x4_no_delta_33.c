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
for (i = 0; i < 8; i += 2, buf += pitch) {
    for (j = 0; j < 4; j++) {
        int16_t val = tmp[i * 4 + j] + tmp[(i + 1) * 4 + j];
        (buf[j]) = (val >> 2);
    }
}
}
