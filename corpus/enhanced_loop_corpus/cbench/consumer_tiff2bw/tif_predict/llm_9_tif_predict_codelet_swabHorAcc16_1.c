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
    for (i = (stride >> 2); i > 0; i--) {
        wp[stride] += wp[0] * 2;
        wp[stride + 1] += wp[1] * 2;
        wp[stride + 2] += wp[2] * 2;
        wp[stride + 3] += wp[3] * 2;
        wp += 4;
    }
}
