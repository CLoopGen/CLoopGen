#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int stride;
extern  int xStride;
extern int i;
extern unsigned int temp[8];
extern int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 2; j++) {
        for (i = 0; i < 4; i++) {
            temp[2 * i + j] = block[stride * i + xStride * 0] + (j == 0 ? (unsigned int)block[stride * i + xStride * 1] : - (unsigned int)block[stride * i + xStride * 1]);
        }
    }
}
