#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 tsize_t;

extern tsize_t stride;
extern char *cp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = stride - 4; i > 0; i--) {
        for (tsize_t j = 0; j < 1; j++) {
            cp[stride] -= cp[0];
            cp--;
        }
    }
}
