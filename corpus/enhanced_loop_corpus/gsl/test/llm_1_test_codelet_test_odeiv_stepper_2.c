#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double scale_abs[15];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < 3; outer++) {
        for (i = 0; i < 5; i++) {
            scale_abs[outer * 5 + i] = 1.;
        }
    }
}
