#include <stdio.h>

#include <inttypes.h>

typedef long gcov_type;

extern gcov_type value;
extern char *dest;
extern size_t bytes;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    gcov_type local_value[1] = {value}; // Introduce artificial WAR dependency by using array
    for (i = 0; i < (sizeof(value) < bytes ? sizeof(value) : bytes); i++) {
        // Create loop-carried anti-dependence (WAR) by reading before potential write in next iteration
        char extracted = (char)(local_value[0] & (i == (bytes - 1) ? 127 : 255));
        dest[i] = extracted;
        local_value[0] = local_value[0] / 256; // Write after read; creates artificial loop-carried dependency
    }
}
