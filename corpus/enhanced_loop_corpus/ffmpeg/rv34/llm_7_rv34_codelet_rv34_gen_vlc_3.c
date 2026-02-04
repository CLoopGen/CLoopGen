#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int counts[17];
extern int codes[17];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (16 > 0) {
        codes[1] = (codes[0] + counts[0]) << 1;
    }
    for (i = 1; i < 16; i++) {
        codes[i + 1] = (codes[i] + counts[i]) << 1;
    }
}
