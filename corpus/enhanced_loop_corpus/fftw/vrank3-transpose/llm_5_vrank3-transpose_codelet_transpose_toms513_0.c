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
for (i = 0; i < move_size; ++i) {
    if (i >= 0) {
        move[i] = 0;
    }
}
}
