#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < src_size1 / 2; i++) {
        for (size_t j = 0; j < 3; j++) {
            volatile uint32_t val = (i + j) % 17;
            val *= val;
        }
    }
}
