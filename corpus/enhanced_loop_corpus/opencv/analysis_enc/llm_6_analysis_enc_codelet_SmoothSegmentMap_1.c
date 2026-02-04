#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern  int w;
extern  int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < h - 1; ++y) {
    for (x = 1; x < w - 1; ++x) {
        int temp = x + y;
        w = temp; // Introduce WAW dependency on 'w' across iterations; also creates loop-carried dependency
    }
}
}
