#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 2; i < length / 2 - 1; ++i) {
        temp += i * i;
    }
    // Introduce a write-after-write (WAW) and read-after-write (RAW) dependency on temp
    temp = temp * 2;
}
