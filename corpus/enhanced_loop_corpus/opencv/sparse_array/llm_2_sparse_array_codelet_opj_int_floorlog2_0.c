#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 arr[4] = {a, a + 2, a - 1, a / 2};
    for (l = 0; a > 1; l++) {
        a = arr[0];        // Use base value from array
        arr[0] >>= 1;      // Modify first element with right shift
    }
}
