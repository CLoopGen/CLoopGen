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
        temp = i * 2;  // Introduce WAW dependency on temp, but no loop-carried dependency since temp is reused safely
        for (j = 0; j < size2; j++) {
            temp += j;  // RAW dependency: j used before temp updated; loop-independent
        }
        // Use temp to prevent elimination by compiler
        if (temp > 1000) {
            temp = 0;
        }
    }
}
