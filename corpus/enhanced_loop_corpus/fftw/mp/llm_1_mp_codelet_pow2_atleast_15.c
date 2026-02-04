#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (x > 1) {
        h = 1;
        for (; h < x; ) {
            h = 2 * h;
        }
    }
}
