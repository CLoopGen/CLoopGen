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
for (i = 0; i < 16; i += 2) {
    for (j = 0; j < 8; j++) {
        int index = i * 8 + j;
        int val = tmp[index] >> 1;
        (buf[j]) = val;
    }
    buf += pitch;
}
}
