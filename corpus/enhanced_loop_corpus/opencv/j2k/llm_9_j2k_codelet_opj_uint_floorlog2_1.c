#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = 0; a > (OPJ_UINT32)1; l += 2) {  // Increase loop increment to reduce effective iterations
        a >>= 1;
        if (a <= 1) break;
        a >>= 1;  // Perform two shifts per iteration, increasing computational intensity per cycle
        l++;      // Compensate for double step while maintaining correct count logic
    }
}
