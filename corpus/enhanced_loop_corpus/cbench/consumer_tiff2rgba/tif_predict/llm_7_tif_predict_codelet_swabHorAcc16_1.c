#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 tsize_t;

typedef unsigned short uint16;

extern tsize_t stride;
extern uint16 *wp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tsize_t local_stride = stride;
    for (i = local_stride - 4; i > 0; i -= 2) {
        wp[local_stride] += wp[0];
        wp[local_stride + 1] += wp[1];
        wp += 2;
    }
    if (i == 1) {
        wp[local_stride] += wp[0];
        wp++;
    }
}
