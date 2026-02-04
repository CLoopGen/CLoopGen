#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < 45; i += 2) {
        base[i] += base[i - 1] + base[i - 2];
        base[i - 1] += base[i - 2] + base[i - 3];
    }
}
