#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern  size_t n;
extern size_t * pp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= n; i++) {
        pp[i-1] = i - 1;
    }
}
