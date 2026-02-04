#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int blksize;
extern int target;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    k = 0;
    for (; k < 64; k++) {
        int shifted = blksize << k;
        if (shifted >= target || shifted <= 0) {
            break;
        }
    }
}
