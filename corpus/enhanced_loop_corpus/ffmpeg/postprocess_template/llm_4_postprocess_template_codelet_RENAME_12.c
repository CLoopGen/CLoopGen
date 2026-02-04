#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 8; y++) {
        int x;
        if (y % 2 == 0) {
            for (x = 0; x < 8; x++) {
                if (x == 4) continue;
            }
        }
    }
}
