#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t stride;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = stride - 4; i > 0; i--) {
        for (tmsize_t j = stride; j > 0; j--) {
            for (tmsize_t k = j; k > 0; k--) {
                // Nested loop body intentionally empty
            }
        }
    }
}
