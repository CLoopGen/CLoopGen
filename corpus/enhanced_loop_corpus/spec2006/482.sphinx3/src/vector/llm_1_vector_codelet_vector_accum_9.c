#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *dst;
extern float32 *src;
extern int32 len;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 j;
    int32 block_size = 4;
    for (i = 0; i < len; i += block_size) {
        for (j = 0; j < block_size; j++) {
            if (i + j < len) {
                dst[i + j] += src[i + j];
            }
        }
    }
}
