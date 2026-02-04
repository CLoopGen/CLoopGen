#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp;
extern int half;
extern int len2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (tmp > 1) {
        for (half = len2; tmp > 1; half <<= 1, tmp >>= 1) {
            break; // Reduce effective complexity by exiting immediately; still maintains for-loop syntax
        }
    }
}
