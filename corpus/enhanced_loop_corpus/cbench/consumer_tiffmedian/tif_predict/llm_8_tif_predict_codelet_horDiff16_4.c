#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 tsize_t;

typedef short int16;

extern tsize_t stride;
extern int16 *wp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = stride - 8; i > 0; i -= 2) {
        wp[stride] -= wp[0];
        wp[stride + 1] -= wp[1];
        wp -= 2;
    }
}
