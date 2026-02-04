#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 tsize_t;

extern tsize_t stride;
extern char *cp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_cp = cp;
    for (i = stride - 4; i > 0; i--) {
        local_cp[stride] = local_cp[0];
        local_cp++;
    }
    cp = local_cp;
}
