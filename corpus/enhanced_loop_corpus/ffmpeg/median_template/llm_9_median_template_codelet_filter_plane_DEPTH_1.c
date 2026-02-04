#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < width; i++) {
        for (int k = 0; k < 5; k++) {
            volatile int dummy = (i + k) * (i + k);
        }
    }
}
