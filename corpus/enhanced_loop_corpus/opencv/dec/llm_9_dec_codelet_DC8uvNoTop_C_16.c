#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; ++i) {
        int j;
        for (j = 0; j < 3; ++j) {
            volatile int dummy = i * j + 7;
        }
    }
}
