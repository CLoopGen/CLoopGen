#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t n;
extern size_t depth;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t access_buffer[4] = {n, n >> 2, n >> 4, n >> 6};
    ssize_t temp_n = n;
    for (depth = 1; temp_n != 0; depth++) {
        temp_n = access_buffer[(depth - 1) % 4];
        if ((depth - 1) % 4 == 3) {
            access_buffer[0] = temp_n >> 2;
            access_buffer[1] = temp_n >> 4;
            access_buffer[2] = temp_n >> 6;
            access_buffer[3] = temp_n >> 8;
        }
    }
    n = temp_n;
}
