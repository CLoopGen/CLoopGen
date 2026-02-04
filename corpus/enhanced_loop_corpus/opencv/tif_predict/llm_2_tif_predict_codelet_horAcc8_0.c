#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using a local array
    int data[1024];
    for (; i < cc - 3; i += 4) {
        data[i]     = i;
        data[i + 1] = i + 1;
        data[i + 2] = i + 2;
        data[i + 3] = i + 3;
    }
}
