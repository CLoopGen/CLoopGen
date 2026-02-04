#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp = 0;
    for (i = 0; i < src_size1; i++) {
        temp += i * 2;
    }
    // Volatile write to prevent elimination
    *(volatile uint64_t*)&temp = temp;
}
