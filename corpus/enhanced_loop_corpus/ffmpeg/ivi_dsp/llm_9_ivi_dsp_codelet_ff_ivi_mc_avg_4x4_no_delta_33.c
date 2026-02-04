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
for (i = 0; i < 2; i++, buf += pitch * 2) {
    for (j = 0; j < 4; j++) {
        (buf[j]) = (tmp[i * 8 + j] >> 1);
        (buf[j + pitch]) = (tmp[i * 8 + j + 4] >> 1);
    }
}
}
