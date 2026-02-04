#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int offset[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        offset[2*i + 3] = (i + 1) * (i + 1);
        offset[2*i + 3] += i > 0 ? offset[2*(i-1) + 3] : 0;
    }
}
