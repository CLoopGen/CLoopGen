#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nal_length_size;
extern  uint8_t *buf;
extern int *buf_index;
extern int i;
extern int nalsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (simulating processing every other byte)
    // Adjust loop bound to prevent out-of-bounds access
    int stride = 2;
    int effective_length = nal_length_size / stride;
    unsigned int temp_nalsize = 0;
    int idx = *buf_index;
    for (i = 0; i < effective_length; i++) {
        temp_nalsize = (temp_nalsize << 8) | buf[idx];
        idx += stride;
    }
    nalsize = temp_nalsize;
    *buf_index = idx - (effective_length - 1) * stride; // Restore index base, adjust if needed on next use
}
