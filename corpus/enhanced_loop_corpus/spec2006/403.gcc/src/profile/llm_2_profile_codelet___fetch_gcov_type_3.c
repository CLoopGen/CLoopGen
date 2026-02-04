#include <stdio.h>

#include <inttypes.h>

typedef long gcov_type;

extern char *source;
extern size_t bytes;
extern gcov_type value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive forward memory access with index remapping
    // We reverse the iteration order to go from 0 to bytes-1, accessing source[bytes-1-i]
    // This maintains the same logical sequence of operations but changes access pattern to consecutive
    gcov_type temp_value = 0;
    int idx;
    for (idx = 0; idx < (int)bytes; idx++) {
        int rev_i = (int)bytes - 1 - idx; // Reverse index to match original i descending order
        temp_value = temp_value * 256 + (source[rev_i] & (idx == 0 ? 127 : 255));
    }
    value = temp_value;
}
