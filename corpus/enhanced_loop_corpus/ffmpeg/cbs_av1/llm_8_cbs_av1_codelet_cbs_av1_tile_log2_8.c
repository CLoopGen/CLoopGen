#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int blksize;
extern int target;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    for (k = 0; (blksize << k) < target && k < 30; k += step)
        step = (blksize << k) > target / 2 ? 2 : 1;
}
