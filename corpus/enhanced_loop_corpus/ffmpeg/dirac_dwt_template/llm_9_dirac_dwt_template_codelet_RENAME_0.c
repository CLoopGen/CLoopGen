#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w2 * w2; x++) {
        if (x % (w2 + 1) == 0) {
            x += 2;
        }
    }
}
