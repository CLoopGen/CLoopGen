#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t temp1 = i, temp2 = i + 1, temp3 = i + 2, temp4 = i + 3;
    for (; i < cc - 3; i += 4) {
        temp1 = temp1 + 1;
        temp2 = temp1 + 2; // RAW dependency on temp1
        temp3 = temp2 + 3; // RAW dependency on temp2
        temp4 = temp3 + 4; // RAW dependency on temp3
    }
    i = (temp1 + temp2 + temp3 + temp4) / 4; // Introduce WAW with original i update
}
