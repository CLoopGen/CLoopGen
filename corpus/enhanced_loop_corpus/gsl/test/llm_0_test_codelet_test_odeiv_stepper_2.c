#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double scale_abs[15];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < 1; outer++) {
        for (i = 0; i < 15; i++) {
            scale_abs[i] = 1.;
        }
    }
}
