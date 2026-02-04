#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < 8 * 8; ++i) {
        temp += i;
    }
    // Introduce a write-after-write (WAW) and read-after-write (RAW) dependency on temp
    temp = temp * 2;
}
