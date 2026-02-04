#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *dst;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev = 0;
    for (i = 0; i < len; i++) {
        int current = dst[i];
        dst[i] = prev;
        prev = current;
    }
}
