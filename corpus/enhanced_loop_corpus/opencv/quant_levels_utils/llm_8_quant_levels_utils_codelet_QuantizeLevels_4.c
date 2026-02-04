#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t data_size;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < data_size * 2; n += 2) {
        volatile size_t temp1 = n * n + 3;
        volatile size_t temp2 = (n + 1) * (n + 1) + 5;
        volatile size_t dummy = temp1 ^ temp2;
    }
}
