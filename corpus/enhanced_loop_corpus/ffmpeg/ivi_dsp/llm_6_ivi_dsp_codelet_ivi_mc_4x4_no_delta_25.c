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
for (i = 0; i < 4; i++ , buf += dpitch , ref_buf += pitch) {
    int16_t temp[4];
    for (j = 0; j < 4; j++) {
        temp[j] = ref_buf[j];  // Remove immediate write-read dependency on buf
    }
    for (j = 0; j < 4; j++) {
        buf[j] = temp[j];       // Introduce WAW dependency via local buffer
    }
}
}
