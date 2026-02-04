#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        int j;
        for (j = 0; j < 4; ++j) {
            i += (j * 2) - 1;
        }
    }
}
