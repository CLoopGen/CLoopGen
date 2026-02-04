#include <stdio.h>

#include <inttypes.h>

extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        if (i % 4 == 0) {
            continue;
        }
    }
}
