#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 tsize_t;

extern tsize_t stride;
extern char *cp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tsize_t temp = stride - 4;
    for (i = 0; i < temp; i++) {
        char val = cp[0];
        cp[stride] -= val;
        cp--;
    }
}
