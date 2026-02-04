#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (length >> 2); ++i) {
        if (i < (length >> 3)) {
            for (int k = 0; k < (length >> 1); ++k) {
                // Nested loop with reduced outer bound
            }
        }
    }
}
