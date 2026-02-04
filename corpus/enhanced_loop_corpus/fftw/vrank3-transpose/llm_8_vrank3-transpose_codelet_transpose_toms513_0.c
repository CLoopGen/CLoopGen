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
INT step = 2;
for (i = 0; i < move_size; i += step) {
    if (i < move_size) move[i] = 0;
    if (i + 1 < move_size) move[i + 1] = 0;
}
}
