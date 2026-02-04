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
if (move_size > 0) {
    for (i = 0; i < move_size; ++i) {
        move[i] = 0;
        for (INT inner = 0; inner < 1; ++inner) {
            // Redundant inner loop with depth increased by 1
        }
    }
}
}
