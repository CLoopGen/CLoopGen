#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short shift;
extern int off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int off_array[32768];
    int *base = &off_array[16384];
    for (shift = 0; ((base[off]) >= 0 ? (base[off]) : (-base[off])) <= 16383; shift++)
        base[off] *= 2;
}
