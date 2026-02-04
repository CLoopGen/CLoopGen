#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t temp = 0;
    for (i = 0; i < size1; i++) {
        temp = i * 2;
        for (j = 0; j < size2; j++) {
            temp += j;
        }
        // RAW dependency: `temp` used in next iteration of i-loop
        // WAW: `temp` is rewritten each outer iteration
        // Loop-carried dependency on `temp` across i iterations
    }
}
