#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 tsize_t;

extern tsize_t stride;
extern char *cp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tsize_t j;
    for (j = stride - 4; j > 0; j -= 2) {
        if (j > 1) {
            cp[stride] += cp[0];
            cp[stride + 1] += cp[1]; 
            cp += 2;
        } else {
            cp[stride] += *cp;
            cp++;
        }
    }
}
