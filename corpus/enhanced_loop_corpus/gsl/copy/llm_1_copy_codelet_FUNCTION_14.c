#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (src_size1 > 0) {
        i = 0;
        for (; i < src_size1; ) {
            i++;
        }
    }
}
