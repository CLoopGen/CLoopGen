#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t temp_count = count;
    for (; temp_count > 1; temp_count -= 1) {
        for (tmsize_t inner = 0; inner < 1; inner++) {
            // Empty body, simulating original do-while once execution
        }
    }
}
