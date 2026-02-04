#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 tsize_t;

extern tsize_t stride;
extern char *cp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = stride - 2; i > 0; i--) {
        int32 temp1 = *cp;
        int32 temp2 = cp[stride];
        cp[stride] = temp1 + temp2 + 1;
        *cp = temp2;
        cp++;
    }
}
