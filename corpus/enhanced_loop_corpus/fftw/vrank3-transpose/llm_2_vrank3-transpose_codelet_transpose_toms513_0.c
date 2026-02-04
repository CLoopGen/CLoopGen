#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

extern char *move;
extern INT move_size;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < move_size; i += 2)
        move[i] = 0;
    if (move_size > 0) {
        for (i = 1; i < move_size; i += 2)
            move[i] = 0;
    }
}
