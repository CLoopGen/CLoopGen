#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t temp = 0;
    for (; i < cc; i++) {
        temp += i;
    }
    // Introduce a write-after-write (WAW) dependency on temp, and loop-carried dependency via temp accumulation
}
