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
    uint16 *wp_local = wp;
    tsize_t s = stride;
    for (i = s - 4; i > 0; i--) {
        wp_local[s] = wp_local[0];
        wp_local += 2;
    }
}
