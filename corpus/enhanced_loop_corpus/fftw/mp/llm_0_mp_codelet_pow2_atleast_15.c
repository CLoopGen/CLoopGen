#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (h = 1; h < x; h = 2 * h) {
        for (int k = 0; k < 2; k++) {
            // Inner empty loop to increase nesting depth
        }
    }
}
