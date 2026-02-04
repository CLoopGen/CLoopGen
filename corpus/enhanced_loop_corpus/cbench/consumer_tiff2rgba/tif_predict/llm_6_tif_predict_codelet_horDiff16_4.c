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
    tsize_t temp_stride = stride - 4;
    int16 temp_val = wp[0];
    for (i = temp_stride; i > 0; i--) {
        wp[stride] -= temp_val;
        wp--;
    }
}
