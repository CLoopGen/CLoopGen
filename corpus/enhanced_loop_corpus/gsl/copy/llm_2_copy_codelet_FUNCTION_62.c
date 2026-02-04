#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < src_size1; i += 2) {
        // Strided memory access: process every second element
        // This modifies the memory access pattern to a stride of 2
    }
}
