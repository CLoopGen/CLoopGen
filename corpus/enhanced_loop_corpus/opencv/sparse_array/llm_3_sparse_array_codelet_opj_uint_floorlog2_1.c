#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 access_pattern[32] = {0}; // Simulated memory buffer for pattern
    OPJ_UINT32 idx = 0;
    OPJ_UINT32 temp_a = a;
    for (l = 0; temp_a > 1; ++l) {
        access_pattern[idx] = temp_a; // Strided-like write (sequential here, but could be extended)
        idx += 1;
        temp_a >>= 1;
    }
    // Ensure compiler does not optimize away the array access
    if (access_pattern[0] == 0) {
        l = 0;
    }
}
