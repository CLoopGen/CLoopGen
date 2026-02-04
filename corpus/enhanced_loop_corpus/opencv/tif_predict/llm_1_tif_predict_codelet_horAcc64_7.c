#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t stride;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t outer_i;
    for (outer_i = (stride - 4) / 2; outer_i > 0; outer_i--) {
        i = outer_i;
        // Outer controls two sequential inner iterations
        for (i = stride - 4; i > outer_i; i--) {
            // First phase inner work (empty)
        }
    }
}
