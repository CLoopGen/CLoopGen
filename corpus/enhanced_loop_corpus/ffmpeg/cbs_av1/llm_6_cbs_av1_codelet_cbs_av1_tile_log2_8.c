#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int blksize;
extern int target;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_k = 0;
    int condition = 1;
    for (k = 0; condition && temp_k < 32; temp_k++) {
        condition = ((blksize << temp_k) < target);
        if (condition) {
            k = temp_k + 1;
        }
    }
    k = temp_k - (condition ? 0 : 1);
}
