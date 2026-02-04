#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; k < 16 && k >= 0; ++k) {
        if (k == 8) {
            k += 2;
        }
    }
}
