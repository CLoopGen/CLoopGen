#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc2;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    dc0 = 0;
    dc2 = 0;
    for (i = 0; i < 4; i++) {
        int index1 = -1 + i * stride;
        int index2 = -1 + (i + 4) * stride;
        if (index1 >= 0) {
            dc0 += src[index1];
        }
        if (index2 >= 0) {
            dc2 += src[index2];
        }
    }
}
