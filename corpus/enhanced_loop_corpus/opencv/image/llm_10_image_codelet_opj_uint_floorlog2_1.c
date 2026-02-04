#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 shift_amount = 4;
    OPJ_UINT32 i;
    for (l = 0; a > (OPJ_UINT32)1 << shift_amount; l += shift_amount) {
        a >>= shift_amount;
    }
    // Remaining iterations handled in unrolled small-step loop
    for (i = 0; i < shift_amount && a > 1; ++i) {
        a >>= 1;
        ++l;
    }
}
