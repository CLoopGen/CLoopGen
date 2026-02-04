#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < K && i < 1000; i++) {
        for (size_t j = 0; j < 5; j++) {
            uint32_t x = (i + j) * (i + j);
        }
    }
}
