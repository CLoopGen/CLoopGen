#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int blksize;
extern int target;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; (blksize << k) < target && k < 32; k++) {
        if ((blksize << k) >= target) {
            break;
        }
    }
}
