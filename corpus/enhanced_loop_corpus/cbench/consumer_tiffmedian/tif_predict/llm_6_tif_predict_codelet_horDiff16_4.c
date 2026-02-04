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
    tsize_t idx = stride - 4;
    for (i = stride - 4; i > 0; i--) {
        wp[1] = wp[0]; // Introduce WAW and WAR dependency: write after write and write after read on wp[0] and wp[1]
        wp[0] = wp[stride]; // Carry dependency through wp[0] to next iteration
        idx -= 2;
        wp--;
    }
}
