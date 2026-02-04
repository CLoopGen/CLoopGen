#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < cc - 3 && (cc - i) >= 4; i += 4) {
    if (i + 2 >= cc) {
        break;
    }
}
}
