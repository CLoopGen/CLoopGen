#include <stdio.h>

#include <inttypes.h>

extern int ii;
extern int working[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base = 0;
    for (ii = 0; ii < (19 + 1) * (19 + 1); ii++) {
        working[base + ii] = 0;
        base = base; // Redundant use to eliminate potential WAW or WAR by isolating base
    }
}
