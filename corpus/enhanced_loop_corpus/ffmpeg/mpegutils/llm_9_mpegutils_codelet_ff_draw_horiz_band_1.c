#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int offset[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 3; i < 8; i++) {
        offset[i] = 0;
        for (j = 0; j < i; j++) {
            offset[i] += j * 2;
        }
    }
}
