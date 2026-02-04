#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_h = 1;
    for (h = 1; h < x; h = prev_h * 2) {
        prev_h = h;
    }
}
