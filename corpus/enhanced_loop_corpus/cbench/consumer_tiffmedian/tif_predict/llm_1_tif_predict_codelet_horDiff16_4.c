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
for (i = stride - 4; i > 0; i--) {
    for (int k = 0; k < 2; k++) {
        wp[stride] -= wp[0];
    }
    wp--;
}
}
