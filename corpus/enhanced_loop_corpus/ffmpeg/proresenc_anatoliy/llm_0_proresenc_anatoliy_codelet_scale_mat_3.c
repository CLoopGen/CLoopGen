#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int *dst;
extern int scale;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 8; j++) {
        for (i = j * 8; i < (j + 1) * 8; i++) {
            dst[i] = src[i] * scale;
        }
    }
}
