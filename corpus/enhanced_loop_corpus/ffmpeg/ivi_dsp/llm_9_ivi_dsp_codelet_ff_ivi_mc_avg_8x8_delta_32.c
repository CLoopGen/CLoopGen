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
for (i = 0; i < 4; i++, buf += pitch * 2) {
    for (j = 0; j < 8; j += 2) {
        buf[j]     += (tmp[i * 16 + j] >> 1);
        buf[j + 1] += (tmp[i * 16 + j + 1] >> 1);
    }
    for (j = 0; j < 8; j += 2) {
        buf[j]     += (tmp[(i * 16 + 8) + j] >> 1);
        buf[j + 1] += (tmp[(i * 16 + 8) + j + 1] >> 1);
    }
}
}
