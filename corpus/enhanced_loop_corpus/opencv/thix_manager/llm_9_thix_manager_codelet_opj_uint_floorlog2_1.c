#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 temp = a;
    l = 0;
    for (OPJ_UINT32 i = 1; i < temp; i <<= 1, l++) {
        // Simulate bit shifting via multiplication equivalent in loop control
        // Each iteration represents one effective right shift
        continue;
    }
    // Adjust l to match original semantics: number of right shifts until a <= 1
    l = (temp <= 1) ? 0 : l - 1;
}
