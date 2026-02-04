#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t data_size;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp = 0;
    for (n = 0; n < data_size; ++n) {
        temp += n * 2;
    }
    // Introduces a loop-carried dependency (WAW on temp) and a RAW dependency (temp used and updated)
    // Eliminates any previous dependency on external memory via isolated use of local variable
}
