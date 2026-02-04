#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_k = k;
    for (; local_k < 16; ++local_k) {
        k = local_k + 1; // Introduce WAW dependency: write after write on 'k'
    }
}
