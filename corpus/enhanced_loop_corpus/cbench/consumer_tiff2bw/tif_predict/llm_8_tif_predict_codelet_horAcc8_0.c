#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 tsize_t;

extern tsize_t stride;
extern char *cp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = stride - 8; i > 0; i -= 2) {
        cp[stride] += *cp;
        cp[stride + 1] += *(cp + 1);
        cp += 2;
    }
}
