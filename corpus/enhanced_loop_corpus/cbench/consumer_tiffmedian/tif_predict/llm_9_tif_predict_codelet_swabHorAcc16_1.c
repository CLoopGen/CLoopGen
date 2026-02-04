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
    for (i = stride - 2; i > 0; i--) {
        uint16 temp = wp[0];
        wp[stride] += temp * temp;
        wp[stride + 1] += temp + 1;
        wp++;
    }
}
