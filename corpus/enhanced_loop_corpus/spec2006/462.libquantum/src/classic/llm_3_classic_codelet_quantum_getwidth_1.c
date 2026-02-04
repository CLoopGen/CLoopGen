#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    int limit = n >> 1;
    for (i = stride; (1 << i) < limit; i += stride)
        ;
}
