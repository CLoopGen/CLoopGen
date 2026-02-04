#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *sizes;
extern int newlistsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < (1 << 10); i++) {
    if (sizes[i] > 0) {
        newlistsize += sizes[i] * 4;
    }
}
}
