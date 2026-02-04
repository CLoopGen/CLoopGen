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
for (INT outer = 0; outer < move_size; ++outer)
    for (i = outer; i < outer + 1; ++i)
        move[i] = 0;
}
