#include <stdio.h>

#include <inttypes.h>

typedef long gcov_type;

extern gcov_type value;
extern char *dest;
extern size_t bytes;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = (sizeof(value) < bytes) ? sizeof(value) : bytes;
    gcov_type temp_value = value;
    gcov_type masks[8];
    
    // Precompute masks to increase computational intensity
    for (i = 0; i < 8; i++) {
        masks[i] = (i == (bytes - 1) && i < limit) ? 127 : 255;
    }

    // Unroll the loop partially to increase operations per iteration
    for (i = 0; i < limit; i += 2) {
        dest[i] = (char)(temp_value & masks[i]);
        temp_value = temp_value / 256;
        
        if (i + 1 < limit) {
            dest[i + 1] = (char)(temp_value & masks[i + 1]);
            temp_value = temp_value / 256;
        }
    }
}
