#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern ptrdiff_t stride;
extern unsigned int rlen;
extern unsigned int j;
extern unsigned int k;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (k = 0; k < rlen; k++) {
    dst[j++] = 0;
    if (j == width) {
        j = 0;
        dst += stride;
    }
}

}
