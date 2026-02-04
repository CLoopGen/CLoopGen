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
    for (j = 0; j < 8; j++) {
        (buf[j]) += (tmp[i * 8 + j] >> 1);
    }
}

}
