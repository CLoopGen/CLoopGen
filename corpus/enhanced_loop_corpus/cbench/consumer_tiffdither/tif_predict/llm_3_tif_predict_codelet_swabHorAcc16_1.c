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
    for (i = stride - 4; i > 0; i -= 2) {
        wp[0] += wp[stride / 2];
        wp++;
        if (i > 1) {
            wp[0] += wp[stride / 2];
            wp++;
        }
    }
}
