#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t dest_size1;
extern  size_t dest_size2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < dest_size1; i++) {
        size_t temp = 0;
        for (j = 0; j < dest_size2; j++) {
            temp += i + j;  // Introduce loop-carried dependency via `temp`
        }
        // Use `temp` to create a WAW dependency across outer iterations if needed
        i = (temp > 0) ? i : i;  // Artificial use of temp to maintain semantic validity
    }
}
