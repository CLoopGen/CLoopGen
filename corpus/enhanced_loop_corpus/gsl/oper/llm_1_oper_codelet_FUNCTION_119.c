#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t loop_lim;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < loop_lim; i++) {
        for (size_t j = 0; j < loop_lim; j++) {
            for (size_t k = 0; k < loop_lim; k++) {
            }
        }
    }
}
