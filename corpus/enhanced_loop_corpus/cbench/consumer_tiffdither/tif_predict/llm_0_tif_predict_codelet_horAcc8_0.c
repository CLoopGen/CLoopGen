#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 tsize_t;

extern tsize_t stride;
extern char *cp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tsize_t outer_i;
    for (outer_i = (stride - 4) / 2; outer_i > 0; outer_i--) {
        for (i = stride - 4; i > 0 && i > stride - 8; i--) {
            cp[stride] += *cp;
            cp++;
        }
    }
}
