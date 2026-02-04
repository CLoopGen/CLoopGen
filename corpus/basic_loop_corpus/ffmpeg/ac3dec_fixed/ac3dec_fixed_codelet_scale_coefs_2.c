#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *dst;
extern  int32_t *src;
extern int len;
extern int i;
extern unsigned int mul;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < len; i += 8) {
    dst[i] = src[i] * mul;
    dst[i + 1] = src[i + 1] * mul;
    dst[i + 2] = src[i + 2] * mul;
    dst[i + 3] = src[i + 3] * mul;
    dst[i + 4] = src[i + 4] * mul;
    dst[i + 5] = src[i + 5] * mul;
    dst[i + 6] = src[i + 6] * mul;
    dst[i + 7] = src[i + 7] * mul;
}

}
