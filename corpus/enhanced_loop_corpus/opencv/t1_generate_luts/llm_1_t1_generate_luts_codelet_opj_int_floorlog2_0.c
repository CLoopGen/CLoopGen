#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (l = 0; a > 1; l += 2) {
    a >>= 1;
    if (a <= 1) break;
    for (OPJ_INT32 step = 0; step < 1; step++) {
        if (a > 1) {
            a >>= 1;
            l++;
        }
    }
}
}
