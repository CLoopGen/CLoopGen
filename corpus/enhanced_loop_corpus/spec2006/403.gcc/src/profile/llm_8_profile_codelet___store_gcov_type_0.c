#include <stdio.h>

#include <inttypes.h>

typedef long gcov_type;

extern gcov_type value;
extern char *dest;
extern size_t bytes;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    gcov_type temp_value = value;
    size_t limit = (sizeof(value) < bytes) ? sizeof(value) : bytes;
    for (i = 0; i < limit; i++) {
        gcov_type mask = (i == (bytes - 1)) ? 127 : 255;
        dest[i] = (char)(temp_value & mask);
        temp_value >>= 8;  // Replace division with bit shift for efficiency
    }
}
