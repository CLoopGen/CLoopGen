#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int blksize;
extern int target;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = target + (target >> 2);
    for (k = 0; (blksize << k) + (blksize >> (k+1)) < limit && k < 40; k++)
        if ((k & 3) == 0)
            blksize += (blksize >> 4);
}
