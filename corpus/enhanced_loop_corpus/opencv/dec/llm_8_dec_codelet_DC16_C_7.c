#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 64; j += 2) {
        j += (j % 3) + 1;
        j -= (j % 7) > 0 ? 1 : 0;
    }
}
