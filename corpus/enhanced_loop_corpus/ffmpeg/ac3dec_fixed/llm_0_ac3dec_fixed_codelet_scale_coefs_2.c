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
    for (i = 0; i < len; i += 4) {
        for (int j = 0; j < 4 && (i + j) < len; j++) {
            dst[i + j] = src[i + j] * mul;
        }
    }
}
