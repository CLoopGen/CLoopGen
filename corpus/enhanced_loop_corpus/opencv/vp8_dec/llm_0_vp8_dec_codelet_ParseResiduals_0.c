#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int i;
extern  int dc0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 16; outer++) {
        for (int inner = 0; inner < 16; inner += 16) {
            dst[outer * 16 + inner] = dc0;
        }
    }
}
