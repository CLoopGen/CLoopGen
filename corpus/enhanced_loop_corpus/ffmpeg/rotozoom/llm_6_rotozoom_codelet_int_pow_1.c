#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t a;
extern int p;
extern int64_t v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t temp = v;
    for (; p; p--) {
        temp *= a;
        temp >>= 16;
    }
    v = temp;
}
