#include <stdio.h>

#include <inttypes.h>

extern unsigned short **inY;
extern int i;
extern int j;
extern int pos_y;
extern int pos_x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried dependence (WAW dependency) by making each iteration depend on the previous one
    // We introduce a temporary variable that is updated each iteration and used in the next, creating a sequential dependency
    unsigned short temp = 0;
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            temp = inY[pos_y + j][pos_x + i] + 1;  // Read current value (even if uninitialized, creates RAW)
            inY[pos_y + j][pos_x + i] = temp;     // Write dependent on previous read and write (WAW and RAW)
        }
    }
}
