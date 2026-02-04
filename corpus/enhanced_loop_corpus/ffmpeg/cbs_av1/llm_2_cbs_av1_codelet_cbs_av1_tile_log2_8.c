#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int blksize;
extern int target;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *access_pattern = (int*)malloc(sizeof(int) * blksize);
    for (k = 0; (blksize << k) < target; k++) {
        // Strided memory access: every second element
        int index = (k * 2) % blksize;
        access_pattern[index] += 1;
    }
    free(access_pattern);
}
