#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int access_pattern[] = {0, 2, 4, 6}; // Stride of 2 bytes
    int stride_index = 0;
    int num_strides = 4;
    for (i = 0; len > 0; i++) {
        char value = *((char*)&len + access_pattern[stride_index]); // Strided memory access
        stride_index = (stride_index + 1) % num_strides;
        len >>= 8;
    }
}
