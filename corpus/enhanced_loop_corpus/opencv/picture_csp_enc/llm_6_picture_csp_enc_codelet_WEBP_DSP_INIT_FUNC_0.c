#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (v = 0; v <= 255; ++v) {
        temp += v;
    }
    v = temp; // Introduce WAW dependency: write-after-write on 'v'
}
