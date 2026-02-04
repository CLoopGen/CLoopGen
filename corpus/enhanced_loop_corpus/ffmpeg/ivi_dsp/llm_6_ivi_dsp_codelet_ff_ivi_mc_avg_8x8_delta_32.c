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
for (i = 0; i < 8; i++ , buf += pitch) {
    int16_t temp_row[8];
    for (j = 0; j < 8; j++) {
        temp_row[j] = tmp[i * 8 + j] >> 1;
    }
    for (j = 0; j < 8; j++) {
        buf[j] += temp_row[j];
    }
}
}
