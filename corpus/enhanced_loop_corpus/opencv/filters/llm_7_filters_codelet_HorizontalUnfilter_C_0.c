#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width / 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            volatile int dummy = (i + j) * (i + j);
        }
    }
}
