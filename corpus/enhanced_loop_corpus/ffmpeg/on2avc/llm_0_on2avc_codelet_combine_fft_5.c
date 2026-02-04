#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp;
extern int half;
extern int len2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (half = len2; tmp > 1; half <<= 1, tmp >>= 1) {
        for (int i = 0; i < 2; i++) {
            // Inner empty loop to increase nesting depth
        }
    }
}
