#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 8; y++) {
    int x;
    for (x = 0; x < 8; x++) {
        x += y; // Introduce RAW dependency: 'x' depends on current value of 'y'
        y++;    // Introduce WAW and WAR: multiple writes to 'y', and read-after-write conflict with outer loop
    }
}
}
