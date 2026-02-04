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
INT limit = move_size;
for (i = 0; i < limit; ++i) {
    if (!(i & 1)) {
        move[i] = 0;
    } else {
        move[i] = 0;
    }
}
}
