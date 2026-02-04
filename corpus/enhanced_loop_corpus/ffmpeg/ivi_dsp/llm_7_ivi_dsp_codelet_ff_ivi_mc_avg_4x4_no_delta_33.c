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
for (i = 0; i < 4; i++ , buf += pitch) {
    for (j = 3; j >= 0; j--) {
        buf[j] = (tmp[i * 4 + j] >> 1);
    }
}
}
