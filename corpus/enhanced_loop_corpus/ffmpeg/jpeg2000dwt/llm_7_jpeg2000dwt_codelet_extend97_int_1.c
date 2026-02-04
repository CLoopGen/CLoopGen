#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 4; i >= 1; i--) {
        p[i1 + i - 1] = p[i1 - i - 1];
        p[i0 - i] = p[i0 + i];
    }
}
