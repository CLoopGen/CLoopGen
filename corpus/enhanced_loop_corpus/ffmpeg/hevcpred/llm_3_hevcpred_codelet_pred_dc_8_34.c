#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern  uint8_t *top;
extern  uint8_t *left;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    for (i = 0; i < size; i += stride) {
        for (int j = 0; j < stride && (i + j) < size; j++) {
            dc += left[i + j] + top[i + j];
        }
    }
}
