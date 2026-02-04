#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (l = 0; a > 1; l++) {
    for (OPJ_INT32 temp = a; temp > 1 && temp == a; temp >>= 1) {
        a >>= 1;
    }
}
}
