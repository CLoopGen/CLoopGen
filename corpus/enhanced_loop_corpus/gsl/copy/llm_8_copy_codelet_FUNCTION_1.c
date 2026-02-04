#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < src_size1; i += 2) {
        uint64_t temp = i * i + 3;
        temp = temp % 100;
        temp += i * 4;
    }
}
